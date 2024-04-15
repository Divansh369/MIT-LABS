-- A. Consider normal text file to learn the pig running modes and execution modes. Run the program locally and test it on Hadoop.

-- B. Write a pig program to count the number of word occurrences using python in different modes (local mode, MapReduce mode)
-- Load the text file
lines = LOAD 'input.txt' AS (line:chararray);

-- Tokenize each line into words
words = FOREACH lines GENERATE FLATTEN(TOKENIZE(line)) AS word;

-- Group the words and count the occurrences
word_counts = GROUP words BY word;
word_occurrences = FOREACH word_counts GENERATE group AS word, COUNT(words) AS count;

-- Store the result in a file
STORE word_occurrences INTO 'word_counts_output' USING PigStorage(',');

-- C. Execute the pig script to find the "most popular movie in the dataset". In this example, we will be dealing with 2 files (ratings.data and movies.item).
-- Load the ratings data
ratings = LOAD 'ratings.data' USING PigStorage('\t') AS (userID:int, movieID:int, rating:int, timestamp:int);

-- Load the movie data
movies = LOAD 'movies.item' USING PigStorage('|') AS (movieID:int, title:chararray, release_date:chararray, video_release_date:chararray, IMDb_URL:chararray, unknown:int, Action:int, Adventure:int, Animation:int, Childrens:int, Comedy:int, Crime:int, Documentary:int, Drama:int, Fantasy:int, Film_Noir:int, Horror:int, Musical:int, Mystery:int, Romance:int, Sci_Fi:int, Thriller:int, War:int, Western:int);

-- Group the ratings by movieID and calculate the average rating for each movie
avg_ratings = FOREACH (GROUP ratings BY movieID) GENERATE group AS movieID, AVG(ratings.rating) AS avg_rating;

-- Join the movie data with the average ratings
movie_ratings = JOIN avg_ratings BY movieID, movies BY movieID;

-- Find the most popular movie by sorting in descending order of average rating and taking the top record
most_popular_movie = ORDER movie_ratings BY avg_ratings::avg_rating DESC;
top_movie = LIMIT most_popular_movie 1;

-- Store the result in a file
STORE top_movie INTO 'most_popular_movie_output' USING PigStorage(',');
