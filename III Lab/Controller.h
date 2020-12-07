//
// Created by dimag on 03.12.2020.
//
#ifndef III_LAB_GAMECONTROLLER_H
#define III_LAB_GAMECONTROLLER_H
#include <SFML/Graphics.hpp>
#include "Render.h"

class Controller
{
    Model* m_game;
    Render* m_render;
public:
    Controller(Model* game, Render* render);
    ~Controller();
    void Run();
};
#endif //III_LAB_GAMECONTROLLER_H
