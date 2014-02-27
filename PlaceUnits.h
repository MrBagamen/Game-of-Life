#ifndef PLACEUNITS_H
#define PLACEUNITS_H

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "Grid.h"

#define bool char
#define true 1
#define false 0

void placeUnits(struct Grid *g, SDL_Event evt, bool mouseButton);

#endif
