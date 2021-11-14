#ifndef __COORD_H__
#define __COORD_H__

struct Coord {
    int x, y;
    Coord() : x(0), y(0) {}
    Coord(int _x, int _y) : x(_x), y(_y) {}
    Coord& operator +=(const Coord& op);
};

Coord operator +(const Coord& op1, const Coord& op2);
bool operator ==(const Coord& op1, const Coord& op2);

#endif // __COORD_H__