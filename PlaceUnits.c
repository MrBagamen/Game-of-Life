#include "PlaceUnits.h"
#include "Unit.h"

void modUnits(struct Grid *g, int mx, int my, ModType type)
{
    int index;

    SDL_GetMouseState(&mx, &my);
    mx = floor(mx/g->size) * g->size;
    my = floor(my/g->size) * g->size;
    drawUnitOnMousePos(mx, my);

    SDL_GetMouseState(&mx, &my);
    index = floor(my/g->size) * (g->width/g->size) + floor(mx / g->size);
    //printf("Cell number %d\n", index);
    //fflush(stdout);

    if(type == MOD_ADD)
    {
        g->grid_states[index] = 1;
    }
    else if(type == MOD_REMOVE)
    {
        g->grid_states[index] = 0;
    }
}
