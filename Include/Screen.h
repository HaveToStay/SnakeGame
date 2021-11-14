#ifndef __SCREEN_H__
#define __SCREEN_H__


#include <windows.h>

/*
����� ���������� ��� ������ Screen
*/

class ScreenException {
public:
    ScreenException(int _err) : err(_err) {}
    const char* what();         // ���������� ������ � ��������� ������
    int err;                    // ��� ������
};


class Screen {
public:
    Screen();
    ~Screen();
    void cursor_show(bool visible);                 // ��������/������ ������
    void text_attr(WORD attr);                      // ���������� ���� ������/����
    void pos(int x, int y, char ch = 0);            // ���������������� ������� � ����� �������, ���� ch != 0
    void pos_str(int x, int y, const char* str);    // ���������������� ������� � ����� ������
    void cls();                                     // ������� ������

private:
    HANDLE ConsoleOutput;
    CONSOLE_CURSOR_INFO oldCursorInfo, curCursorInfo;
    WORD oldTextAttr;
};


#endif // __SCREEN_H__