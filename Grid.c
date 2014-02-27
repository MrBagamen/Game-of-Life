#include "Grid.h"

void drawGrid(struct Grid *g)
{
    int i;
    int oldX = g->startX;
    int oldY = g->startY;

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        //Vertical lines
        for(i = 0; i < (g->width/g->size); i++)
        {
            glVertex2f(g->startX, g->startY);
            glVertex2f(g->startX, g->startY+g->height);
            g->startX += g->size;
        }
        g->startX = oldX;
        //Horizontal lines
        for(i = 0; i < (g->height/g->size); i++)
        {
            glVertex2f(g->startX, g->startY);
            glVertex2f(g->startX+g->width, g->startY);
            g->startY += g->size;
        }
        g->startY = oldY;
    glEnd();
    glPopMatrix();
}
