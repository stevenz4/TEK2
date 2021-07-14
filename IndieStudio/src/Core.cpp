/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Core
*/

#include "Core.hpp"
#include "GameObject.hpp"

Core::Core()
{
    InitAudioDevice();
    _titleMusic = new music("assets/title_music.mp3");
    _ingameMusic = new music("assets/ingame.mp3");
    _HEIGHT = 1017;
    _WIDTH = 1920;
    _fps = 60;
    _isOpen = true;
    _titleMusic->playMusic();
    _ingameMusic->playMusic();
    _currentScreen = LOGO;
    _mapCreated = false;
    setButton();
    createWindow();
    _background = new Background("assets/texture/background.png", 1920, 1080);
    _endScreen = new Background("assets/texture/end_screen.png", 1920, 1080);
    _logo = LoadTexture("assets/texture/indie_logo.png");
    _bombMenu = LoadTexture("assets/texture/bomb.png");
    gameLoop();
}

void Core::setButton()
{
    _button.push_back(new Button(float(_WIDTH) / 2 - 75, 310, 200, 100, "Play", MENU));
    _button.push_back(new Button(float(_WIDTH) / 2 - 75, 435, 200, 100, "Options", MENU));
    _button.push_back(new Button(float(_WIDTH) / 2 - 75, 560, 200, 100, "Quit", MENU));
    _button.push_back(new Button(2, 2, 75, 50, "Back", OPTIONS));
    _button.push_back(new Button(2, 2, 75, 50, "Back", MAP));
    _button.push_back(new Button(730, 255, 50, 50, "-", OPTIONS));
    _button.push_back(new Button(1200, 255, 50, 50, "+", OPTIONS));
    _button.push_back(new Button(800, 255, 50, 50, "-", MAP));
    _button.push_back(new Button(1100, 255, 50, 50, "+", MAP));
    _button.push_back(new Button(600, 555, 200, 100, "Small", MAP));
    _button.push_back(new Button(1200, 555, 200, 100, "Large", MAP));
    _button.push_back(new Button(900, 555, 200, 100, "Medium", MAP));
}

Core::~Core()
{
    UnloadTexture(_logo);
    UnloadTexture(_bombMenu);
    delete _endScreen;
    delete _titleMusic;
    delete _ingameMusic;
    delete _background;
    for (GameObject *j: _mapObject)
        delete j;
    for (Button *j: _button)
        delete j;
    for (Player *j: _Player)
        delete j;
    _mapObject.clear();
    _button.clear();
    _Player.clear();
    CloseAudioDevice();
    CloseWindow();
}

void Core::createWindow()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(_WIDTH, _HEIGHT, "Indie Studio");
    SetTargetFPS(_fps);
    ShowCursor();
}

void Core::getWindowSize()
{
    _HEIGHT = GetScreenHeight();
    _WIDTH = GetScreenWidth();
}

float Core::createTimer(float &timer)
{
    timer += GetFrameTime();
    return timer;
}

void Core::bombAnimation(float &bombTimer)
{
    static float w = 100.0f, h = 100.0f;
    static float x = GetScreenWidth() * 0.58f , y = 0.0f;
    static bool increase = true;

    x = GetScreenWidth() * 0.58f;
    DrawTexturePro(_bombMenu, Rectangle{0.0f, 0.0f, 144.0f, 145.0f}, Rectangle{x, y, w, h}, {0,0} ,0, WHITE);
    if (h >= 120 || w >= 120)
        increase = false;
    else if (h == 100 || w == 100)
        increase = true;
    if (createTimer(bombTimer) > 0.015f) {
        bombTimer = 0.0f;
        if (increase == false)
            h -= 1, w -= 1, x += 0.5f, y += 0.5f;
        else
            h += 1, w += 1, x -= 0.5f, y -= 0.5f;
    }
}

void Core::inputCore()
{
    int xBar = 800;
    int xBar2 = 800;

    _titleMusic->UpdateMusic();
    _background->DrawBackground();
    if (_currentScreen == MAP) {
        DrawText("Choose The Game Mode", (_WIDTH / 2) - MeasureText("Choose The Game Mode", 100) / 2, 10, 100, WHITE);
        DrawText(std::to_string(_ia).c_str(), (_WIDTH / 2) + 40, 250, 70, WHITE);
        DrawText("IA:", (_WIDTH / 2) - 50, 250, 70, WHITE);
    }
    if (_currentScreen == OPTIONS) {
        DrawText("Options", (_WIDTH / 2) - 200, 10, 100, WHITE);
        DrawText("Volume", 50, 250, 70, WHITE);
        for (float j = 0.1f; j < _titleMusic->getVolume(); j += 0.1f, xBar += 40)
            DrawRectangle(xBar, 260, 20, 50, WHITE);
        for (float j = 0.1f; j < 1.00; j += 0.1f, xBar2 += 40)
            DrawRectangleLines(xBar2, 260, 20, 50, GRAY);
    }
    for (Button *i: _button) {
        i->checkMouseCollision();
        if (i->getScreen() == _currentScreen) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (i->checkMouseCollision()) {
                    if (strcmp(i->getText().c_str(), "Back") == 0)
                        _currentScreen = MENU;
                    else if (strcmp(i->getText().c_str(), "-") == 0)
                        if (_currentScreen == OPTIONS)
                            _titleMusic->setVolume('-');
                        else
                            _ia > 0 ? _ia-- : _ia;
                    else if (strcmp(i->getText().c_str(), "+") == 0)
                        if (_currentScreen == OPTIONS)
                            _titleMusic->setVolume('+');
                        else
                            _ia < 3 ? _ia++ : _ia;
                    else if (strcmp(i->getText().c_str(), "Play") == 0)
                        _currentScreen = MAP;
                    else if (strcmp(i->getText().c_str(), "Options") == 0)
                        _currentScreen = OPTIONS;
                    else if (strcmp(i->getText().c_str(), "Quit") == 0)
                        _isOpen = false;
                    else if (strcmp(i->getText().c_str(), "Large") == 0) {
                        _map = new Map(LARGE);
                        _camera = new Camera_class(LARGE);
                        _currentScreen = GAME;
                    } else if (strcmp(i->getText().c_str(), "Medium") == 0) {
                        _map = new Map(MEDIUM);
                        _camera = new Camera_class(MEDIUM);
                        _currentScreen = GAME;
                    } else if (strcmp(i->getText().c_str(), "Small") == 0) {
                        _map = new Map(SMALL);
                        _camera = new Camera_class(SMALL);
                        _currentScreen = GAME;
                    }
                }
            }
            i->disp();
        }
    }
}

void Core::displayPlayer()
{
    if (_mapCreated == true) {
        for (Player *i : _Player) {
            if (i->getIa())
                i->input(true, _mapObject);
            else {
                i->input(_mapObject);
            }
            i->display();
            i->manageBomb(_mapObject, _Player, (*i));
        }
    }
}

void Core::getMapObj(Map *createmap)
{
    for (int x = 0; x < createmap->get_width(); x++) {
            for (int y = 0; y < createmap->get_height(); y++) {
                if (createmap->get_map()[x][y] == 0)
                    _mapObject.push_back(new GameObject("Wall", {float(x * 3), 0.0f, float(y * 3)}, LoadModelFromMesh(GenMeshCube(3.0f, 3.0f, 3.0f)), "assets/characters/texture/floors.png"));
                if (createmap->get_map()[x][y] == 3)
                    _mapObject.push_back(new GameObject("CrateBreakable", {float(x * 3), 0.0f, float(y * 3)}, LoadModelFromMesh(GenMeshCube(3.0f, 3.0f, 3.0f)), "assets/characters/texture/woden_crate2.png"));
            }
        }
        for (int i = 4; i != 0 ; i--) {
            _Player.push_back(new Player(i, _ia > 0 ? true : false, i - 1, "Player", {(i < 4 && i > 1 ? 3.0f : 3.0f * (createmap->get_width() - 2)), -1.0f,(i >= 3 ? 3.0f : 3.0f * (createmap->get_height() - 2))},
                                        "assets/characters/model/jerry.iqm", "assets/characters/texture/jerry.png"));
            _ia--;
            _Player.back()->dir = UP;
        }
        _mapObject.push_back(new GameObject("Ground", {3.0f * createmap->get_width() / 2, -3.0f, 3.0f * createmap->get_height() / 2}, LoadModelFromMesh(GenMeshCube(3.0f * (createmap->get_width() - 1), 3.0f * (createmap->get_height() - 1), 3.0f)), "assets/characters/texture/ground.png"));
        _mapCreated = true;
}

void Core::displayStat()
{
    int pos = 0;
    int x = 50;
    int y = 30;
    Color color;

    if (_mapCreated == false)
        return;
    for (Player *i: _Player) {
        switch (i->getId())
        {
        case 2:
            x = 50;
            y = 30;
            color = PURPLE;
            break;
        case 3:
            color = YELLOW;
            x = 1750;
            y = 30;
            break;
        case 1:
            color = RED;
            x = 50;
            y = 800;
            break;
        case 0:
            color = GREEN;
            x = 1750;
            y = 800;
            break;
        default:
            break;
        }
        DrawText(TextFormat("Player %d", i->getId() + 1), x, y, 20, color);
        DrawText(TextFormat("Life: %d", i->getLife()), x, y + 30, 20, color);
        DrawText(TextFormat("Bomb Max: %d", i->getBombMax()), x, y + 60, 20, color);
        DrawText(TextFormat("Bomb Range: %d", i->getBombRange()), x, y + 90, 20, color);
        DrawText(TextFormat("Move Speed: %0.2f", i->getMoveSpeed()), x, y + 120, 20, color);
    }
}

void Core::displayMap(Map *createmap)
{
    if (_mapCreated == false) {
        getMapObj(_map);
    } else 
        for (GameObject *i : _mapObject)
            i->display();
}

int Core::gameLoop()
{
    float bombTimer = 0.0f;

    while(_isOpen && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        _mousePos = GetMousePosition();
        switch (_currentScreen) {
        case LOGO:
            displayLogo();
            break;
        case MENU:
            getWindowSize();
            inputCore();
            DrawTexture(_logo, (_WIDTH / 2) - (_logo.width / 2), 0, WHITE);
            bombAnimation(bombTimer);
            break;
        case OPTIONS:
            inputCore();
            break;
        case MAP:
            inputCore();
            break;
        case GAME:
            displayStat();
            BeginMode3D(_camera->get_cam());
            _ingameMusic->UpdateMusic();
            displayMap(_map);
            displayPlayer();
            EndMode3D();
            if (_Player.size() == 1)
                _currentScreen = END;
            break;
        case END:
            _endScreen->DrawBackground();
            break;
        }
        EndDrawing();
    }
    getWindowSize();
    return 0;
}