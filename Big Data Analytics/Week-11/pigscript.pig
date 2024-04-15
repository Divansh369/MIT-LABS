-- Load the data from the input file
emails = LOAD 'input.txt' USING PigStorage(' ') AS (User_ID:chararray, From:chararray, To:chararray);

-- Flatten the To column to get individual email addresses
flattened_emails = FOREACH emails GENERATE User_ID, From, FLATTEN(TOKENIZE(REPLACE(To, '(', ''))) AS To;

-- Filter out rows with empty To field
filtered_emails = FILTER flattened_emails BY To IS NOT NULL;

-- Group by User_ID and collect a bag of To email addresses for each user
grouped_emails = GROUP filtered_emails BY User_ID;
result = FOREACH grouped_emails GENERATE group AS User_ID, filtered_emails.From AS From, filtered_emails.To AS To;

-- Store the result in a file
STORE result INTO 'output' USING PigStorage(',');

-- Display the result
DUMP result;
