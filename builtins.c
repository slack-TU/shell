#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

void cd(char** argv);
int dir(char* arg);
void clr();
void env();
void ps();
void quit();
void help();
void echo();

extern char **environ;
extern int errno;

int main(int argc, char**argv, char**envp){
  /*clr();
  dir(argv[1]);
  cd(argv);*/
  //env(envp);
  //ps();
  //help();
  //echo(argc, argv);
  //quit();
}

void echo(int argc, char**argv){
  for(int i = 1; i < argc; i++)
    printf("%s ", argv[i]);

  printf("\n");
}

void help(){
  printf("What do you call a computer that sings?\n");
  sleep(3);
  printf("A Dell!\n");
  sleep(2);
  printf("Type program names and arguments, and hit enter.\n");
}

void quit(){
  exit(0);
}

void ps(){
  char play[1] = "\n";

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, stdin)) !=-1){
    char * token = strtok(line, play);
    if(token==NULL){
      return;
    }
  }
}

void env(){
  for(char **e = environ;*e;e++){
    printf("%s\n", *e);
  }
}

int dir(char* arg){
  if(arg != NULL){
    chdir(arg);
  }

  char cwd [PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != NULL){
    DIR* directory = opendir(cwd);
    struct dirent *e;
    while(( e = readdir(directory))!=NULL){
      printf("%s\n", e->d_name);
    }
    closedir(directory);
    return 0;
  }
  else{
    return 1;
  }
}

void cd(char** argv){
  if(argv[1] != NULL){
    chdir(argv[1]);
  }

  char cwd [PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != NULL)
    printf("%s\n", cwd);
}

void clr(){
  printf("\033[H\033[2J");
}
