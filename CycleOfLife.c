#include "CycleOfLife.h"

int wrap(struct Grid *g, int i)
{
    const int w = g->width / g->size;
    const int h = g->height / g->size;
    int x = i % w;
    int y = i / w;
    if (x >= w) {
        x = 0;
    }
    if (y >= h) {
        y = 0;
    }
    if (x < 0) {
        x = w - 1;
    }
    if (y < 0) {
        y = h - 1;
    }
    return y * w + x;
}

int countNeighbours(struct Grid *g, int i)
{
    int neighbours = 0;
    //Bottom Left
    if(g->grid_states[wrap(g, i+50)] == 1)
    {
        neighbours++;
    }
    //Bottom Middle Neighbour
    if(g->grid_states[wrap(g, i+51)] == 1)
    {
        neighbours++;
    }
    //Bottom right
    if(g->grid_states[wrap(g, i+52)] == 1)
    {
        neighbours++;
    }
    //Top left
    if(g->grid_states[wrap(g, i-50)] == 1)
    {
        neighbours++;
    }
    //Top Middle neighbour
    if(g->grid_states[wrap(g, i-51)] == 1)
    {
        neighbours++;
    }
    //top right neighbour
    if(g->grid_states[wrap(g, i-52)] == 1)
    {
        neighbours++;
    }
    //left and right
    if(g->grid_states[wrap(g, i-1)] == 1)
    {
        neighbours++;
    }
    if(g->grid_states[wrap(g, i+1)] == 1)
    {
        neighbours++;
    }
    return neighbours;
}


void unitCycle(struct Grid *g)
{
    for(int i = 0; i < (g->width/g->size)*(g->height/g->size); i++)
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
