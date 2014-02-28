#include "PlaceUnits.h"
#include "Unit.h"

void modUnits(struct Grid *g, int x, int y, ModType type)
{
    int index = floor(y/g->size) * (g->width/g->size) + floor(x / g->size);
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
