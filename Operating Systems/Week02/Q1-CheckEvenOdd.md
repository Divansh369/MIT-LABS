## Q1 - Write a shell script to find if a given number is even or odd.

### Shell Script
```
echo '
#!/bin/bash

echo "Enter any number : "
read number

if [ $ ((number%2)) -eq 0 ]; then
  echo "Even number"
else
  echo "Odd number"
fi' > evenOdd.sh
```

### Command to make it an executable script
```
chmod +x evenOdd.sh
```

### Command to run the file
```
./evenOdd.sh
```



