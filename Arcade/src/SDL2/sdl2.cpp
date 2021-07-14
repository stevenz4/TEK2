/*
** EPITECH PROJECT, 2021
** sdl2 lib
** File description:
** Arcade
*/

#include "sdl2.hpp"

SDL2::SDL2()
{
    this->win = nullptr;
    this->rend = nullptr;
    this->WIDTH = 1280;
    this->HEIGHT = 720;
}

SDL2::~SDL2()
{
    SDL_FreeWAV(this->wavBuffer);
    SDL_CloseAudioDevice(this->deviceId);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    SDL_DestroyRenderer(this->rend);
    SDL_DestroyWindow(this->win);
}

void SDL2::renderClear()
{
    SDL_RenderClear(this->rend);
}

void SDL2::renderPresent()
{
    SDL_RenderPresent(this->rend);
}

void SDL2::drawImage(const std::string imageName, rect_t src, rect_t dst)
{
    SDL_Texture *texture = IMG_LoadTexture(this->rend, imageName.c_str());
    SDL_Rect src_b = {src.x, src.y, src.h, src.w};
    SDL_Rect dst_b = {dst.x, dst.y, dst.h, dst.w};

	SDL_RenderCopy(this->rend, texture, &src_b, &dst_b);
	SDL_DestroyTexture(texture);
}

void SDL2::drawText(const std::string text, int ftsize, int x, int y)
{
    SDL_Rect dst;
    TTF_Font *font = TTF_OpenFont("assets/font.TTF", ftsize);
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), SDL_Color {255, 165, 0, 255});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(this->rend, surface);
    
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(texture, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(this->rend, texture, NULL, &dst);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}

int SDL2::createWin()
{
    TTF_Init();
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError());
        return 84;
    }
    this->win = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    if (this->win == nullptr) {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return 84;     
    }
    this->rend = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED);
    if (this->rend == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return 84;
    }
    return 0;
}

int SDL2::createSound(const char *musicName)
{
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
 
    SDL_LoadWAV(musicName, &wavSpec, &this->wavBuffer, &wavLength);
    this->deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(this->deviceId, 0);
    return 0;
}

int SDL2::getInput()
{
    while (SDL_PollEvent(&this->events)) {
        switch (this->events.type)
        {
        case SDL_QUIT:
            return 84;
            break;
        case SDL_KEYDOWN:
            if (this->events.key.keysym.scancode == SDL_SCANCODE_W)
                return 'z';
            if (this->events.key.keysym.scancode == SDL_SCANCODE_A)
                return 'q';
            if (this->events.key.keysym.scancode == SDL_SCANCODE_S)
                return 's';
            if (this->events.key.keysym.scancode == SDL_SCANCODE_D)
                return 'd';
            if (this->events.key.keysym.scancode == SDL_SCANCODE_R)
                return 'r';
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (this->events.button.button == SDL_BUTTON_LEFT) {
                std::cout << "x: " << this->events.button.x << " y: " << this->events.button.y << std::endl;
                this->mouse_x = this->events.button.x;
                this->mouse_y = this->events.button.y;
                return 1;
            }
            if (this->events.button.button == SDL_BUTTON_RIGHT)
                return -2;
            break;
        default:
            break;
        }
    }
    return 0;
}

int SDL2::getMouseX()
{
    return this->mouse_x;
}

int SDL2::getMouseY()
{
    return this->mouse_y;
}

extern "C" SDL2 *create_obj()
{
    SDL2 *newone = new SDL2;

    return newone;
}
