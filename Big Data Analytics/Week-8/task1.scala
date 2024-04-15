import org.apache.spark.sql.SparkSession
import org.apache.spark.sql.functions._

// Create a SparkSession
val spark = SparkSession.builder().appName("Task 1: Replace Card_type").getOrCreate()

// Load data into DataFrame
val df = spark.read.format("csv").option("header", "true").load("your_input_file.csv")

// Replace "Checking" with "Cash" in the Card_type column
val updatedDF = df.withColumn("Card_type", regexp_replace(col("Card_type"), "Checking", "Cash"))

// Show the updated DataFrame
updatedDF.show()

// Stop the SparkSession
spark.stop()
