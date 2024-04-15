// Task 1: Word count program using Spark tool
val textData = List("Hello World !", "Hello Hi Bye ! ! !", "Bye Bye")
val textRDD = sc.parallelize(textData)
val wordCount = textRDD.flatMap(line => line.split(" ")).map(word => (word, 1)).reduceByKey(_ + _)
wordCount.toDF("word", "count").show()

// Task 2: Transform each record
val employeeData = List(("John", 26, 30000), ("Jack", 40, 80000), ("Joshi", 25, 35000), ("Jash", 35, 75000), ("Yash", 40, 60000), ("Smith", 20, 24000), ("Lion", 42, 56000), ("Kate", 50, 76000), ("Cassy", 51, 40000), ("Ronald", 57, 65000), ("John", 26, 30000), ("Smith", 20, 24000), ("Jash", 35, 75000), ("Cassy", 51, 40000))
val employeeRDD = sc.parallelize(employeeData)
val transformedData = employeeRDD.map { case (name, age, salary) => (name, age * 2, salary) }
transformedData.toDF("name", "double_age", "salary").show()

// Task 3: Filter employees with salary greater than 50000
val filteredData = transformedData.filter { case (_, _, salary) => salary > 50000 }
filteredData.toDF("name", "double_age", "salary").show()

// Task 4: Split sentences into words using flatMap transformation
val textSentences = List("Spark is an awesome tool for data processing.", "It provides APIs for building data processing applications.", "PySpark simplifies the process of data processing with its easy-to-use interface.")
val textRDD = sc.parallelize(textSentences)
val wordRDD = textRDD.flatMap(line => line.split(" "))
println(wordRDD.collect().mkString(", "))

// Task 5: Group students by subject
val studentData = List(("Alice", "Math", 85), ("Bob", "Science", 90), ("Charlie", "Math", 88), ("David", "Science", 95), ("Eve", "English", 75))
val studentRDD = sc.parallelize(studentData)
val groupedData = studentRDD.map { case (name, subject, score) => (subject, (name)) }.groupByKey().mapValues(_.toList)
groupedData.toDF("subject", "students").show()

// Task 6: Collect first 5 records as an array
val firstFiveRecords = transformedData.take(5)
println(firstFiveRecords.mkString(", "))

// Task 7: RDD creation and operations
val rdd1 = sc.parallelize(List(1, 2, 3, 4, 5))
val sumOfElements = rdd1.reduce(_ + _)
println("Sum of elements in RDD1:", sumOfElements)

// Creating RDD from external source (text file)
val externalRDD = sc.textFile("input_text_file.txt")
println("RDD created from external source:")
externalRDD.collect().foreach(println)

// Task 8: sortByKey groupByKey countByKey operations
val rdd = sc.parallelize(employeeData)

// sortByKey() - Sort by name
val sortedRDD = rdd.map { case (name, age, salary) => (name, (age, salary)) }.sortByKey()
sortedRDD.collect().foreach(println)

// groupByKey() - Group by name
val groupedRDD = rdd.map { case (name, age, salary) => (name, (age, salary)) }.groupByKey()
groupedRDD.collect().foreach(println)

// countByKey() - Count occurrences of each name
val countByKey = rdd.map { case (name, _, _) => (name, 1) }.countByKey()
