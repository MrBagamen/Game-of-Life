#include "Unit.h"

void drawUnit(struct Unit *u, struct Grid *g)
{
    int i;
    for(i = 0; i < ((g->width/g->size)*(g->height/g->size)); i++)
    {
        if(g->grid_states[i] == 1)
        {
            glPushMatrix();
            glColor3f(0.0f, 1.0f, 0.0f);
            glBegin(GL_QUADS);
                glVertex2f(u->x, u->y);
                glVertex2f(u->x+u->size, u->y);
                glVertex2f(u->x+u->size, u->y+u->size);
                glVertex2f(u->x, u->y+u->size);
            glEnd();
            glPopMatrix();
        }
    }
}
void drawUnitOnMousePos(int x, int y)
{
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x+20, y);
        glVertex2f(x+20, y+20);
        glVertex2f(x, y+20);
    glEnd();
    glPopMatrix();
}
