#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
/*Funtion to clear the screen*/
void clear(){
	system("clear"); //stdlib function "cls" for windows this is for linux and mac
}
void type(const char command[]);
void dis(const char file[]);
void list();
void list_path(const char path[]);

int main() {
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
    else if (strcmp(command, "clear") == 0)
	clear();
    else if (strcmp(command, "list") == 0)
	list();
    else if (strncmp(command, "list ", 5) == 0)
	list_path(command+5);
    else 
      printf("%s: command not found\n", command);
  }

  return 0;
}

/*Function for the type command it tells if a command is a shell builtin or external application*/
void type(const char command[]) {
  if (strcmp(command, "echo") == 0 || strcmp(command, "type") == 0 ||
      strcmp(command, "exit") == 0 || strcmp(command, "clear") == 0 || 
      strcmp(command, "dis") == 0)
    printf("%s is a shell builtin\n", command);
  else
    printf("%s: not found\n", command);
}

/*Function to display the contents of a single file*/
void dis(const char file[]){
	FILE *fp;
	int len;
	len= strlen(file);
	
	char file_name[len];
	strcpy(file_name, file);

	fp= fopen(file_name, "r");
	char ch;
	while((ch= getc(fp))!=EOF){
		printf("%c", ch);
	}
	printf("\n");
}

/*Function to print all the files and sub-directores in the current directory*/
void list(){
	DIR *dir = opendir(".");
	struct dirent *content;		//content here is the structure variable for the dir content storage
	while((content= readdir(dir))!=NULL)
		printf("%s\t", content->d_name);
	printf("\n");
	closedir(dir);
}

/*Function to print all the files and sub-directories in the mentioned path*/ 
void list_path(const char path[]){
	DIR *dir = opendir(path);
	struct dirent *content;		//content here is the structure variable for the dir content storage
	while((content= readdir(dir))!=NULL)
		printf("%s\t", content->d_name);
	printf("\n");
	closedir(dir);
}
