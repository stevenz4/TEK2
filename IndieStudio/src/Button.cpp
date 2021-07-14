/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(float x, float y, float height, float width, std::string text, GameScreen screen)
{
    _screen = screen;
    _rect = {x, y ,height, width};
    _text = text;
}

void Button::disp()
{
    DrawRectangleRec(_rect, Fade(ORANGE, !_collisionState ? 0.6f : 1.0f));
    if (!_collisionState) {
        DrawRectangle(_rect.x, _rect.y + _rect.height - 36, _rect.width, 30, BLACK);
        DrawRectangleLinesEx(_rect, 6, Fade(BLACK, 0.3f));
        DrawText(_text.c_str(), _rect.x + _rect.width - MeasureText(_text.c_str(), 20) - 12, _rect.y + _rect.height - 25, 20, ORANGE);
    }else {
        DrawRectangle(_rect.x, _rect.y + _rect.height - 36, _rect.width, 30, BLACK);
        DrawRectangleLinesEx(_rect, 6, Fade(BLACK, 0.3f));
        DrawText(_text.c_str(), _rect.x + _rect.width - MeasureText(_text.c_str(), 30) - 12, _rect.y + _rect.height - 35, 30, ORANGE);
    }
}

bool Button::checkMouseCollision()
{
    Vector2 mousePoint = GetMousePosition();
    _collisionState = CheckCollisionPointRec(mousePoint, _rect);
    return (_collisionState);
}