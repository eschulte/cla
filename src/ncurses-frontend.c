#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#define MAX_LINE_SIZE 1024

WINDOW * window;

void cleanup(){
  delwin(window);
  endwin();
  refresh();
}

void leave(int sig){
  fprintf(fopen("/tmp/diagnostic", "w"), "closing myself down\n");
  cleanup();
  exit(sig);
}

int main(int argc, char *argv[]) {
  (void) signal(SIGINT,leave);

  /* ncurses setup */
  window = initscr();
  start_color();
  use_default_colors();
  init_pair(1, COLOR_CYAN,  -1);
  init_pair(2, COLOR_WHITE, -1);

  /* process input */
  char buffer[MAX_LINE_SIZE];
  FILE * files[argc];
  int f_ind;
  int fn_ln, max_fn_ln = 0;
  for(f_ind=1;f_ind<argc;f_ind++){
    files[f_ind] = fopen(argv[f_ind], "r");
    if(files[f_ind] == NULL){
      cleanup();
      printf("failed to open %s\n", argv[f_ind]);
      return EXIT_FAILURE;
    }
    fn_ln = strlen(argv[f_ind]);
    if(fn_ln > max_fn_ln)
      max_fn_ln = fn_ln;
  }

  /* print the names of the input files */
  color_set(1, NULL);
  for(f_ind=1;f_ind<argc;f_ind++)
    mvprintw((f_ind - 1), (max_fn_ln - strlen(argv[f_ind])), argv[f_ind]);
  refresh();

  /* draw */
  struct timespec interval, remainder;
  interval.tv_sec = 0;
  interval.tv_nsec = (0.1 * 1e+9);
  color_set(2, NULL);
  while(1){
    for(f_ind=1;f_ind<argc;f_ind++){
      rewind(files[f_ind]);
      if(fgets(buffer, MAX_LINE_SIZE, files[f_ind]) > 0)
        mvprintw((f_ind - 1), max_fn_ln, ": %s", buffer);
    }
    refresh();
    nanosleep(&interval, &remainder);
  }

  cleanup();
  return EXIT_SUCCESS;
}
