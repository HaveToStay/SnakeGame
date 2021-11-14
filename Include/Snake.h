#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <vector>

#include "Coord.h"
#include "Screen.h"

using namespace std;

typedef vector<Coord> CoordVector;

class Snake {
public:
    Snake();
    void reset(Coord start_pos);                  // "сброс" змеи
    void draw(Screen& scr);                       // первичная отрисовка змеи на экране
    void move(const Coord& delta, Screen& scr);   // передвижение змеи на приращение координат
    void grow(const Coord& pos, int growbits);    // увеличение длины змеи
    bool into(const Coord& pos);                  // проверка попадания координаты в тело змеи
    Coord head();                                 // метод возвращает координаты головы змеи
    int size();                                   // метод возвращает длину змеи
    char get_head();                              // метод возвращает направление змеи

private:
    CoordVector worm;       // вектор координат сегментов тела змеи
    char head_mark;         // символ, которым отрисовывается голова змеи
    unsigned int drawn;     // длина отрисованного тела змеи
};

#endif // __SNAKE_H__