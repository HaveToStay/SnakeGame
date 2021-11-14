#include "Coord.h"

Coord& Coord::operator +=(const Coord& op) {
    x += op.x;
    y += op.y;
    return *this;
}

Coord operator +(const Coord& op1, const Coord& op2) {
    return Coord(op1.x + op2.x, op1.y + op2.y);
}

bool operator ==(const Coord& op1, const Coord& op2) {
    return op1.x == op2.x && op1.y == op2.y;
}