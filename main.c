#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void type(const char command[]);
void dis(const char file[]);

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  while (1) {
    printf("$ ");
    char command[1024];

    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0';

    if (strcmp(command, "exit") == 0)
	exit(0);
    if (strncmp(command, "echo ", 5) == 0)
      	printf("%s\n", command + 5);
    else if (strncmp(command, "type ", 5) == 0) 
      	type((command + 5)); 
    else if (strncmp(command, "dis ", 4) == 0)
	dis(command+4);
    else 
      printf("%s: command not found\n", command);
  }

  return 0;
}

/*function for the type command it tells if a command is a shell builtin or external application*/
void type(const char command[]) {
  if (strcmp(command, "echo") == 0 || strcmp(command, "type") == 0 ||
      strcmp(command, "exit") == 0)
    printf("%s is a shell builtin\n", command);
  else
    printf("%s: not found\n", command);
}

void dis(const char file[]){
	FILE *fp;
	int i;
	printf("%zu", strlen(file));
}
