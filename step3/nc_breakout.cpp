#include <ncurses.h>

int main(void) {
    initscr();
    noecho();   // キー入力されても表示しない
    curs_set(0);    // カーソルを非表示

    keypad(stdscr, TRUE);   // xtermでマウスイベントとの取得に必要
    mousemask(ALL_MOUSE_EVENTS, NULL);  // マウスイベントを取得
    MEVENT e;

    int px = 2;

    while (true) {
        int ch = getch();
        if (ch == 'q') break;
        if (ch == KEY_MOUSE) {
            if (getmouse(&e) == OK) {
                clear();
                px = e.x;
                if (px < 2) px = 2;
                if (px > 77) px = 77;
                mvprintw(23, px-2, "-----");
                refresh();
            }
        }
    }
    endwin();
}