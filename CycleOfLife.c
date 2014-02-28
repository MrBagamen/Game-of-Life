#include "CycleOfLife.h"

void countNeighbours(struct Grid *g)
{
    int i;
    int neighbours = 0;
    for(i = 0; i < ((g->height/g->size)*(g->width/g->size)); i++)
    {
        if(g->grid_states[i] == 1)
        {
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

        }
        if(neighbours < 2)
        {
            g->grid_states[i] = 0;
        }
        else if(neighbours == 2 || neighbours == 3)
        {
            g->grid_states[i] = 1;
        }
        else if(neighbours > 3)
        {
            g->grid_states[i] = 0;
        }
        neighbours = 0;
    }
    //printf("Cells: %d\n", cells);
}
