import org.apache.spark.sql._

// Create SparkSession
val spark = SparkSession.builder().appName("Task 2: Web Log Analysis").getOrCreate()

// Load data into DataFrame
val webLogsDF = spark.read.option("header", "true").csv("web_logs.txt")

// Assuming `webLogsDF` contains columns like `user_id` and `time_spent`
// Group by user_id and calculate total time spent for each user
val engagedUsers = webLogsDF.groupBy("user_id").agg(sum(col("time_spent")).alias("total_time_spent"))

// Show the most engaged users
engagedUsers.show()

// Stop the SparkSession
spark.stop()
