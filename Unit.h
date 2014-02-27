#ifndef UNIT_H
#define UNIT_H

#include "Grid.h"

struct Unit
{
    int x, y;
    int size;
};
void drawUnit(struct Unit *u, struct Grid *g);
void drawUnitOnMousePos(int x, int y);

#endif // UNIT_H
