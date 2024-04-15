from pyspark.sql import SparkSession
from pyspark.sql.functions import col

# Create a SparkSession
spark = SparkSession.builder \
    .appName("Spark Tasks") \
    .getOrCreate()

# Print task number and question
print()
print()
print("Task 1:")
print("Create the dataset of your choice and perform word count program using spark tool.")
print("---------------------------------------------")

# Task 1: Create dataset and perform word count
text_data = [
    "Hello World !","Hello Hi Bye ! ! !","Bye Bye "
]
text_rdd = spark.sparkContext.parallelize(text_data)
word_count = text_rdd.flatMap(lambda line: line.split(" ")).map(lambda word: (word, 1)).reduceByKey(lambda a, b: a + b)
word_count_df = word_count.toDF(["word", "count"])
word_count_df.show()

# Print task number and question
print("Task 2:")
print("Given a dataset of employee records containing (name, age, salary), use map transformation to transform each record into a tuple of (name, age * 2, salary)?")
print("---------------------------------------------")

# Task 2: Transform each record
employee_data = [
    ("John", 26, 30000),
    ("Jack", 40, 80000),
    ("Joshi", 25, 35000),
    ("Jash", 35, 75000),
    ("Yash", 40, 60000),
    ("Smith", 20, 24000),
    ("Lion", 42, 56000),
    ("Kate", 50, 76000),
    ("Cassy", 51, 40000),
    ("Ronald", 57, 65000),
    ("John", 26, 30000),
    ("Smith", 20, 24000),
    ("Jash", 35, 75000),
    ("Cassy", 51, 40000)
]
employee_rdd = spark.sparkContext.parallelize(employee_data)
transformed_data = employee_rdd.map(lambda x: (x[0], x[1] * 2, x[2]))
transformed_data_df = transformed_data.toDF(["name", "double_age", "salary"])
transformed_data_df.show()

# Print task number and question
print("Task 3:")
print("From the same employee dataset, filter out employees whose salary is greater than 50000 using the filter transformation.")
print("---------------------------------------------")

# Task 3: Filter employees with salary greater than 50000
filtered_data = transformed_data.filter(lambda x: x[2] > 50000)
filtered_data_df = filtered_data.toDF(["name", "double_age", "salary"])
filtered_data_df.show()

# Print task number and question
print("Task 4:")
print("Create a text file that will have few sentences, use flatMap transformation to split each sentence into words.")
print("---------------------------------------------")

# Task 4: Create a text file and split sentences into words
text_sentences = [
    "Spark is an awesome tool for data processing.",
    "It provides APIs for building data processing applications.",
    "PySpark simplifies the process of data processing with its easy-to-use interface."
]
text_rdd = spark.sparkContext.parallelize(text_sentences)
word_rdd = text_rdd.flatMap(lambda line: line.split(" "))
print(word_rdd.collect())

# Print task number and question90009000
print("Task 5:")
print("Create a dataset having student details such as (name, subject, score), from this dataset group students by subject using the groupBy transformation.")
print("---------------------------------------------")

# Task 5: Group students by subject
student_data = [
    ("Alice", "Math", 85),
    ("Bob", "Science", 90),
    ("Charlie", "Math", 88),
    ("David", "Science", 95),
    ("Eve", "English", 75)
]
student_rdd = spark.sparkContext.parallelize(student_data)
grouped_data = student_rdd.map(lambda x: (x[1], (x[0], x[2]))).groupByKey().mapValues(list)
grouped_data_df = grouped_data.toDF(["subject", "students"])
grouped_data_df.show()

# Print task number and question
print("Task 6:")
print("From the employee dataset, collect the first 5 records as an array using the collect action.")
print("---------------------------------------------")

# Task 6: Collect first 5 records as an array
first_five_records = transformed_data.take(5)
print(first_five_records)

# Print task number and question
print()
print("Task 7:")
print("Demonstrate the creation of RDD using Parallelized collection, existing RDD by finding the sum of all elements in an RDD1 (which holds array elements). Also, create an RDD from external sources.")
print("---------------------------------------------")

# Task 7: RDD creation and operations
rdd1 = spark.sparkContext.parallelize([1, 2, 3, 4, 5])
sum_of_elements = rdd1.reduce(lambda a, b: a + b)
print("Sum of elements in RDD1:", sum_of_elements)

# Creating RDD from external source (text file)
external_rdd = spark.sparkContext.textFile("input_text_file.txt")
print("RDD created from external source:")
print(external_rdd.collect())

# Stop the SparkSession
spark.stop()
