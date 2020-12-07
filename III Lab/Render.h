//
// Created by dimag on 04.12.2020.
//
#ifndef III_LAB_RENDER_H
#define III_LAB_RENDER_H

#include <SFML/Graphics.hpp>
#include "Model.h"

class Render : public sf::Drawable, public sf::Transformable
{
    Model* mod;
    sf::RenderWindow win;
    sf::Text tex;
public:
    Render(Model* game);
    ~Render();
    sf::RenderWindow& window() { return win; };
    bool Init();
    void Render();
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif //III_LAB_RENDER_H
