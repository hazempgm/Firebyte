#include <Terminal.hpp>


namespace {
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *texture = nullptr;
    SDL_Event event;

    void Init(std::uint32_t width, std::uint32_t height) {
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow("Firebyte - Best terminal", SDL_WINDOWPOS_UNDEFINED
            , SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);

        if(!window)
            throw std::runtime_error("Can't create window !");

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(!renderer)
            throw std::runtime_error("Can't create renderer !");
    }

    void Draw(int x, int y, uint32_t v = 255) {
        SDL_SetRenderDrawColor(renderer, v, v, v, 255);
        SDL_RenderDrawPoint(renderer, x, y);
    }

    void Present() {
        SDL_RenderPresent(renderer);
    }

    void Destroy() {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}


int main() {
    Init(1000, 1000);


    while(1) {
        if(SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
        for(int i = 0; i <1000; ++i) {
            Draw(i,i);
        }
        Present();
    }

    Destroy();
}