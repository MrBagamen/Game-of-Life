#include "CycleOfLife.h"

int countNeighbours(struct Grid *g, int i)
{
    int neighbours = 0;
    //Bottom Left
    if(g->grid_states[i+50] == 1)
    {
        neighbours++;
    }
    //Bottom Middle Neighbour
    if(g->grid_states[i+51] == 1)
    {
        neighbours++;
    }
    //Bottom right
    if(g->grid_states[i+52] == 1)
    {
        neighbours++;
    }
    //Top left
    if(g->grid_states[i-50] == 1)
    {
        neighbours++;
    }
    //Top Middle neighbour
    if(g->grid_states[i-51] == 1)
    {
        neighbours++;
    }
    //top right neighbour
    if(g->grid_states[i-52] == 1)
    {
        neighbours++;
    }
    //left and right
    if(g->grid_states[i-1] == 1)
    {
        neighbours++;
    }
    if(g->grid_states[i+1] == 1)
    {
        neighbours++;
    }
    return neighbours;
}


void unitCycle(struct Grid *g)
{
    int i;
    for(i = 0; i < ((g->width/g->size)*(g->width/g->size)); i++)
    {
        int neighbours = countNeighbours(g, i);
        if(g->grid_states[i] == 1)
        {
            if(neighbours < 2)
            {
                g->grid_states[i] = 0;
            }
            if(neighbours == 2 || neighbours == 3)
            {
                g->grid_states[i] = 1;
            }
            if(neighbours > 3)
            {
                g->grid_states[i] = 0;
            }
        }
        if(g->grid_states[i] == 0)
        {
            if(neighbours == 3)
            {
                g->grid_states[i] = 1;
            }
        }
    }
}
