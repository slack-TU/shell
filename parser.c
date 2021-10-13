#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

const char delim[4] = " \t\n\a";

int main(void){

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, stdin)) !=-1){
    char* token = strtok(line, delim);
    while(token!=NULL){
      printf("%s\n", token);
      token = strtok(NULL, delim);
    }
  }

  exit(0);
}
