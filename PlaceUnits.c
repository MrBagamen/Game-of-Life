#include "PlaceUnits.h"
#include "Unit.h"

void placeUnits(struct Grid *g, SDL_Event evt, bool mouseButton)
{
    int mx = NULL, my = NULL;
    int index;

    SDL_GetMouseState(&mx, &my);
    mx = floor(mx/g->size) * g->size;
    my = floor(my/g->size) * g->size;
    drawUnitOnMousePos(mx, my);

    SDL_GetMouseState(&mx, &my);
    index = floor(my/g->size) * (g->width/g->size) + floor(mx / g->size);
    //printf("Cell number %d\n", index);
    //fflush(stdout);

    if(mouseButton)
    {
        if(evt.button.button == SDL_BUTTON_LEFT)
        {
            g->grid_states[index] = 1;
        }
        if(evt.button.button == SDL_BUTTON_RIGHT)
        {
            g->grid_states[index] = 0;
        }
    }
}
