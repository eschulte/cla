#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]){
  char buffer[MAX_LINE_SIZE];
  int i, current_length, last_length = 0;
  FILE * fd;
  if(argc > 1)
    fd = fopen(argv[1], "w+");

  while(gets(buffer)){
    // just in case the line was >MAX_LINE_SIZE
    buffer[MAX_LINE_SIZE] = 0;

    // ensure this line is as long as the last
    current_length = strlen(buffer);
    for(i=current_length;i<last_length;i++)
      buffer[i] = ' ';
    buffer[i]=0;

    // print to output s.t. only the last line exists there
    if(argc > 1){
      // print to a file
      rewind(fd);
      fprintf(fd, buffer);
      fflush(fd);
    }else{
      // print to STDOUT
      printf("\r%s", buffer);
      fflush(stdout);
    }
    last_length = current_length;
  }


  // ensure that after all the output ends in a newline
  if(argc > 1)
    fprintf(fd, "\n");
  else
    puts("");

  return 0;
}
