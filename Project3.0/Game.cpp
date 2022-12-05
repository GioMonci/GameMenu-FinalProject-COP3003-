/*
 * COP 3003 - Game Menu
 * Sources:
 * https://www.sfml-dev.org/tutorials/2.5/ - sfml website: download code.
 * https://en.sfml-dev.org/forums/index.php?topic=8536.0 - sfml dev on how code works.
 * http://gamedevgeek.com/tutorials/managing-game-states-in-c/ - How game states work and how to implement
 * https://github.com/SonarSystems - code for game state algorithm and chest game algorithm
 * Special thanks to people on SFML dev website, game state, and sonar systems for aid in project.
 */

#include "Game.h"
#include "SplashState.h"

namespace GioState
{
    Game::Game(int width, int height, std::string title)
    {
        _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        _data->machine.AddState(StateRef(new SplashState(this->_data)));

        this->Run();
    }
    void Game::Run()
    {
        float newTime, frameTime, interpolation;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while(this->_data->window.isOpen())
        {
            this->_data->machine.ProcessStateChanges();
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if(frameTime > 0.25f)
            {
                frameTime =0.25f;
                accumulator += frameTime;

                while (accumulator >= dt)
                {
                    this->_data->machine.GetActiveState()->HandleInput();
                    this->_data->machine.GetActiveState()->Update(dt);
                    accumulator -= dt;
                }
                interpolation = accumulator / dt;
                this->_data->machine.GetActiveState()->Draw(interpolation);
            }
        }
    };
}