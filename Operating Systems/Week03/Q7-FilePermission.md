## Q7 - Write a shell script, that will: 
- a. Ask the user to enter a filename and read the file name 
- b. Change the FAP for user to executable for the given filename

### Shell Script
```
echo '
#!bin/bash
read -p "Enter the filename : " file
if [ ! -f "$file" ]; then
  echo "404: File not found : $file !!!"
  exit 1
fi

chmod +x "$file"

echo "Permission changed for the file - $file"
echo' > changePermission.sh
```

### Command to make it an executable script
```
chmod +x changePermission.sh
```


### Command to run the file
```
./changePermission.sh
```

