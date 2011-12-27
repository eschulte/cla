#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 1024

int main(){
  char buffer[MAX_LINE_SIZE];
  int i, current_length, last_length = 0;
  while(gets(buffer)){
    // just in case the line was >MAX_LINE_SIZE
    buffer[MAX_LINE_SIZE] = 0;
    current_length = strlen(buffer);
    // wipe out remaining characters from the previous line
    for(i=current_length;i<last_length;i++)
      buffer[i] = ' ';
    buffer[i]=0;
    printf("\r%s", buffer);
    fflush(stdout);
    last_length = current_length;
  }
  puts("");
  return 0;
}
