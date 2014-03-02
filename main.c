#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include "Grid.h"
#include "Unit.h"
#include "PlaceUnits.h"
#include "CycleOfLife.h"
#include <assert.h>

#define bool char
#define true 1
#define false 0

bool Init();

struct e
{
    SDL_Window *window;
    SDL_GLContext glc;
    bool is_running;
    bool cycle;
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

    //Unit instance
    struct Unit unit;
    unit.size = 20;
    unit.x = 0;
    unit.y = 0;

    while(e.is_running)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                e.is_running = false;
                break;
            case SDL_KEYDOWN:
                if (!event.key.repeat)
                {
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        e.is_running = false;
                    }
                    else if (event.key.keysym.sym == SDLK_SPACE)
                    {
                        e.cycle = !e.cycle;
                    }
                }
                break;
            default:;
            }
        }

        int mx, my;
        Uint32 state = SDL_GetMouseState(&mx, &my);
        int x = floor(mx/grid.size) * grid.size;
        int y = floor(my/grid.size) * grid.size;

        if (state & SDL_BUTTON(1)) {
            modUnits(&grid, x, y, MOD_ADD);
        }
        else if (state & SDL_BUTTON(3)) {
            modUnits(&grid, x, y, MOD_REMOVE);
        }

        if(e.cycle)
        {
            unitCycle(&grid);
        }

        //Render shit
        glClear(GL_COLOR_BUFFER_BIT);
        drawUnit(&unit, &grid);
        drawUnitOnMousePos(x, y);
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
    e.cycle = false;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1020, 760, 0, 0, 1); //Set projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


    return true;
}
