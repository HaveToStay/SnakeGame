#ifndef __SCREEN_H__
#define __SCREEN_H__


#include <windows.h>

/*
Класс исключения для класса Screen
*/

class ScreenException {
public:
    ScreenException(int _err) : err(_err) {}
    const char* what();         // возвращает строку с описанием ошибки
    int err;                    // код ошибки
};


class Screen {
public:
    Screen();
    ~Screen();
    void cursor_show(bool visible);                 // показать/скрыть курсор
    void text_attr(WORD attr);                      // установить цвет текста/фона
    void pos(int x, int y, char ch = 0);            // позиционирование курсора и вывод символа, если ch != 0
    void pos_str(int x, int y, const char* str);    // позиционирование курсора и вывод строки
    void cls();                                     // очистка экрана

private:
    HANDLE ConsoleOutput;
    CONSOLE_CURSOR_INFO oldCursorInfo, curCursorInfo;
    WORD oldTextAttr;
};


#endif // __SCREEN_H__