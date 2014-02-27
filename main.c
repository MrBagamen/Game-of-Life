#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include "Grid.h"
#include "Unit.h"
#include "PlaceUnits.h"

#define bool char
#define true 1
#define false 0

bool Init();

struct e
{
    SDL_Window *window;
    SDL_Event event;
    SDL_GLContext glc;
    bool is_running;
}e;

int main(int argc, char** argv)
{
    e.is_running = Init();

    //Le Grid
    struct Grid grid;
    grid.size = 20;
    grid.startX = grid.startY = 0;
    grid.width = 1020;
    grid.height = 760;
    grid.grid_states = malloc((grid.width/grid.size)*(grid.height/grid.size)+1);
    memset(grid.grid_states, 0, (grid.width/grid.size)*(grid.height/grid.size)+1);
    int i;
    /*for(i = 0; i < (grid.width/grid.size)*(grid.height/grid.size)+1;i++)
    {

        printf("%d", grid.grid_states[i]);
    }*/

    //Units
    grid.grid_states[4] = 1;
    grid.grid_states[10] = 1;
    grid.grid_states[50] = 1;
    grid.grid_states[51] = 1;
    grid.grid_states[1937] = 1;
    struct Unit unit;
    unit.size = 20;
    unit.x = 0;
    unit.y = 0;


    //Placing Units
    //struct PlaceUnits placeUnits;

    while(e.is_running)
    {
        while(SDL_PollEvent(&e.event))
        {
            switch(e.event.type)
            {
            case SDL_QUIT:
                e.is_running = false;
            default:;
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);

        //Render shit
        drawUnit(&unit, &grid);
        placeUnits(&grid);
        drawGrid(&grid);


        SDL_GL_SwapWindow(e.window);

        SDL_Delay(16);
    }

    free(grid.grid_states);
    SDL_GL_DeleteContext(e.glc);
    SDL_DestroyWindow(e.window);
    SDL_Quit();
    return 0;
}

bool Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    e.window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1020, 760, SDL_WINDOW_OPENGL);
    e.glc = SDL_GL_CreateContext(e.window);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1020, 760, 0, 0, 1); //Set projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


    return true;
}
