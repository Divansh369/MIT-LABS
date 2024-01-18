## Q5 - Write script to print contents of file from given line number to next given number of lines.

### Shell Script
```
echo '
#!/bin/bash
read -p "Enter the file name: " file

if [ ! -f "$file" ]; then
echo "404: File not found : $file !!!"
exit 1
fi

read -p "Enter the start line : " startLine
read -p "Enter the number of lines to print : " numLines
sed -n "$startLine,$((startLine + numLines - 1))p" "$file"

echo' > contentsFile.sh
```

### Command to make it an executable script
```
chmod +x contentsFile.sh
```


### Command to run the file
```
./contentsFile.sh
```

