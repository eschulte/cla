#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

int main(void) {

  /* setup */
  WINDOW * window = initscr();
  start_color();
  use_default_colors();
  init_pair(1, COLOR_CYAN,  -1);
  init_pair(2, COLOR_WHITE, -1);

  /* draw */
  int i, j;
  for(j=0;j<20000;j++){
    for(i=0;i<3;i++){
      color_set(1, NULL);
      mvaddstr(i, 0, "ncurses");
      color_set(2, NULL);
      mvprintw(i, 7, ": %d", (i+j));
    }
    refresh();
  }

  /* cleanup */
  delwin(window);
  endwin();
  refresh();

  return EXIT_SUCCESS;
}
