//
// Created by dimag on 03.12.2020.
//
#include "Controller.h"

Controller::Controller(Model* game, Render* render)
{
    m_game = game;
    m_render = render;
}
Controller::~Controller()
{
}

void Controller::Run()
{
    sf::Event event;
    int move_counter = 0;

    while (m_render->window().isOpen())
    {
        while (m_render->window().pollEvent(event))
        {
            if (event.type == sf::Event::Closed) m_render->window().close();
            if (event.type == sf::Event::KeyPressed)
            {

                if (event.key.code == sf::Keyboard::Escape) m_render->window().close();
                if (event.key.code == sf::Keyboard::Left) m_game->Move(Direction::Left);
                if (event.key.code == sf::Keyboard::Right) m_game->Move(Direction::Right);
                if (event.key.code == sf::Keyboard::Up) m_game->Move(Direction::Up);
                if (event.key.code == sf::Keyboard::Down) m_game->Move(Direction::Down);

                if (event.key.code == sf::Keyboard::F2)
                {
                    m_game->Init();
                    move_counter = 100;
                }
            }
        }

        if (move_counter-- > 0) m_game->Move((Direction)(rand() % 4));

        m_render->Render();
    }
}