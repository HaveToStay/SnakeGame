#include <iostream>
#include <conio.h>
#include "Screen.h"
#include "Game.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

    try {
        Screen screen;
        screen.cursor_show(false);
        screen.text_attr((WORD)0x0a);
        screen.cls();
        Game game(screen, 80, 40, 160);

        game.logo();

        game.read_top10();
        game.top10(false);
        game.pak(18);

        do {
            game.game_loop();
            game.top10(true);

        } while (game.once_more());

        game.goodbye();
    }
    catch (ScreenException& ex) {
        cerr << "*** " << ex.what() << endl;
    }

    return 0;
}