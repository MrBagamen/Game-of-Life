#ifndef PLACEUNITS_H
#define PLACEUNITS_H

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "Grid.h"

#define bool char
#define true 1
#define false 0

typedef enum {
    MOD_ADD,
    MOD_REMOVE
} ModType;

void modUnits(struct Grid *g, int x, int y, ModType type);

#endif
