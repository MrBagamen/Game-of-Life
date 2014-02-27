#include "PlaceUnits.h"

void placeUnits(struct Grid *g)
{
    int mx = NULL, my = NULL;
    int index;

    SDL_GetMouseState(&mx, &my);
    mx = floor(mx/g->size) * g->size;
    my = floor(my/g->size) * g->size;
    drawUnitOnMousePos(mx, my);

    SDL_GetMouseState(&mx, &my);
    index = floor(my/g->size) * (g->width/g->size) + floor(mx / g->size);
    printf("Cell number %d\n", index);
    fflush(stdout);
}
