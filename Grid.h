#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <GL/gl.h>

struct Grid
{
    int startX, startY;
    int size;
    int width, height;
    char *grid_states;
};
void drawGrid(struct Grid *g);

#endif // GRID_H
