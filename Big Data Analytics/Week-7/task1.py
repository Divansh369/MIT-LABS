from pyspark.sql import SparkSession
from pyspark.sql.functions import col, count, when

# Create a SparkSession
spark = SparkSession.builder \
    .appName("Task 1: Clickstream Analysis") \
    .getOrCreate()

# Load data into DataFrame
clickstream_df = spark.read.csv("clickstream_data.csv", header=True)

# Display schema and first 5 rows
print("Schema:")
clickstream_df.printSchema()
print("First 5 rows:")
clickstream_df.show(5)

# Calculate total clicks, views, and purchases for each user
clickstream_df.groupBy("user_id").pivot("action").agg(count("*")).show()

# Identify most common sequence of actions
clickstream_df.createOrReplaceTempView("clickstream")
most_common_sequence = spark.sql("SELECT action_sequence, COUNT(*) AS frequency FROM (SELECT CONCAT_WS(' -> ', collect_list(action)) AS action_sequence FROM (SELECT user_id, action FROM clickstream GROUP BY user_id, action) GROUP BY user_id) GROUP BY action_sequence ORDER BY frequency DESC LIMIT 1")
print("Most common sequence of actions performed by users:")
most_common_sequence.show(truncate=False)

# Stop the SparkSession
spark.stop()
