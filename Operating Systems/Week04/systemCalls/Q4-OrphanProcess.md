### Q4 -  Create a orphan process (parent dies before child, child process adopted by “init” process) and display the PID of parent of child before and after it becomes orphan. Use sleep (n) in the child to delay the termination.

### C program - **orphanProcess.c**

```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child, parent;

    parent = getpid();
    printf("Parent PID: %d\n", parent);

    child = fork();

    if (child < 0) {
        perror("Fork failed");
        return 1;
    } 
    else if (child == 0) {
        printf("Child PID: %d\n", getpid());
        printf("Parent PID in child process (before parent exits): %d\n", getppid());

        sleep(7);

        printf("Parent PID in child process (after parent exits): %d\n", getppid());
    } 
    else {
        printf("Parent process is exiting...\n");
        exit(0);
    }

    return 49;
}
```
### Command to compile the C program
```
gcc -o orphanProcess orphanProcess.c
```

### Command to run the program
```
./orphanProcess
```

