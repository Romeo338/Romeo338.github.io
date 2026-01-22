#include <SDL3/SDL.h>
#include <emscripten.h>
#include <emscripten/html5.h>

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
bool running = true;

void main_loop() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            running = false;
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw something
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_FRect rect = { 100, 100, 200, 150 };
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return 1;
    }

    window = SDL_CreateWindow("SDL3 Emscripten", 800, 600, 0);
    if (!window) {
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    emscripten_set_main_loop(main_loop, 0, 1);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}