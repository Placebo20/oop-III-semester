//
// Created by dimag on 04.12.2020.
//

#include "Render.h"
#include "Resources.h"

Render::Render(Model* game)
{
    m_game = game;
    Init();
}
Render::~Render()
{
}

bool Render::Init()
{
    setPosition(50.f, 50.f);
    win.create(sf::VideoMode(600, 600), "15");
    win.setFramerateLimit(60);
    tex = sf::Text("F2 - New Game / Esc - Exit / Arrow Keys - Move Tile", Assets::Instance().font, 20);
    tex.setFillColor(sf::Color::Cyan)
    tex.setPosition(5.f, 5.f);
    return true;
}

void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    sf::Color color = sf::Color(200, 100, 200);

    sf::RectangleShape shape(sf::Vector2f(Model::FIELD_SIZE, Model::FIELD_SIZE));
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);
    target.draw(shape, states);

    shape.setSize(sf::Vector2f(Model::CELL_SIZE - 2, Model::CELL_SIZE - 2));
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);


    sf::Text text("", Assets::Instance().font, 52);

    int* elements = m_game->Elements();
    for (unsigned int i = 0; i < GameModel::ARRAY_SIZE; i++)
    {
        shape.setOutlineColor(color);
        text.setFillColor(color);
        text.setString(std::to_string(elements[i]));
        if (m_game->IsSolved())
        {
            shape.setOutlineColor(sf::Color::Cyan);
            text.setFillColor(sf::Color::Cyan);
        }
        else if (elements[i] == i + 1)
        {
            text.setFillColor(sf::Color::Green);
        }

        if (elements[i] > 0)
        {
            sf::Vector2f position(i % Model::SIZE * Model::CELL_SIZE + 10.f, i / Model::SIZE * Model::CELL_SIZE + 10.f);
            shape.setPosition(position);
            text.setPosition(position.x + 30.f + (elements[i] < 10 ? 15.f : 0.f), position.y + 25.f);
            target.draw(shape, states);
            target.draw(text, states);
        }
    }
}
void Render::Render()
{
    win.clear();
    win.draw(*this);
    win.draw(tex);
    win.display();
}
