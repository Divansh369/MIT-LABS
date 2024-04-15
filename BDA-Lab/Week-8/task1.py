from pyspark.sql import SparkSession

# Create SparkSession
spark = SparkSession.builder \
    .appName("Replace String in Column") \
    .getOrCreate()

# Load data into DataFrame
df = spark.read \
    .format("csv") \
    .option("header", "true") \
    .load("your_input_file.csv")

# Replace string using na.replace
df = df.na.replace("Checking", "Cash", "Card_type")

# Show updated DataFrame
df.show()
