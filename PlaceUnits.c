#include "PlaceUnits.h"

void placeUnits(struct Grid *g)
{
    int mx = NULL, my = NULL;
    SDL_GetMouseState(&mx, &my);
    mx = floor(mx/g->size) * g->size;
    my = floor(my/g->size) * g->size;

    //printf("X: %d, Y: %d\n", mx, my);
    drawUnitOnMousePos(mx, my);
}
