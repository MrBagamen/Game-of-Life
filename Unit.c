#include "Unit.h"

void drawUnit(struct Unit *u, struct Grid *g)
{
    int i;
    int a = 0;
    int b = 0;

    for(i = 0; i < ((g->height/g->size)*(g->width/g->size)); i++)
    {
        if(g->grid_states[i] == 1)
        {
            glPushMatrix();
            glColor3f(0.0f, 1.0f, 0.0f);
            glBegin(GL_QUADS);
                glVertex2f(b*g->size, a*g->size);
                glVertex2f(b*g->size+g->size, a*g->size);
                glVertex2f(b*g->size+g->size, a*g->size+g->size);
                glVertex2f(b*g->size, a*g->size+g->size);
            glEnd();
            glPopMatrix();
        }
        b++;
        if(b == 51)
        {
            a++;
            b = 0;
        }
    }

    /*for(a = 0; a < (g->height/g->size); a++)
    {
        if(g->grid_states[a+b] == 1)
        {
            glPushMatrix();
            glColor3f(0.0f, 1.0f, 0.0f);
            glBegin(GL_QUADS);
                glVertex2f(b*g->size, a*g->size);
                glVertex2f(b*g->size+g->size, a*g->size);
                glVertex2f(b*g->size+g->size, a*g->size+g->size);
                glVertex2f(b*g->size, a*g->size+g->size);
            glEnd();
            glPopMatrix();
        }
        if(b == 50)
        {
            b = 0;
        }
        b++;

        for(b = 0; b < (g->width/g->size); b++)
        {
            if(g->grid_states[a+b] == 1)
            {
                glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                glBegin(GL_QUADS);
                    glVertex2f(b*g->size, a*g->size);
                    glVertex2f(b*g->size+g->size, a*g->size);
                    glVertex2f(b*g->size+g->size, a*g->size+g->size);
                    glVertex2f(b*g->size, a*g->size+g->size);
                glEnd();
                glPopMatrix();
            }
        }
    }*/
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
