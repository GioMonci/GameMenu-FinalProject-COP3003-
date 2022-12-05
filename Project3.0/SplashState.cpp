/*
 * COP 3003 - Game Menu
 * Sources:
 * https://www.sfml-dev.org/tutorials/2.5/ - sfml website: download code.
 * https://en.sfml-dev.org/forums/index.php?topic=8536.0 - sfml dev on how code works.
 * http://gamedevgeek.com/tutorials/managing-game-states-in-c/ - How game states work and how to implement
 * https://github.com/SonarSystems - code for game state algorithm and chest game algorithm
 * Special thanks to people on SFML dev website, game state, and sonar systems for aid in project.
 */

#include "SplashState.h"
#include <sstream>
#include <iostream>
#include "DEFINITIONS.h"
#include "MainMenuState.h"

namespace GioState
{
    SplashState::SplashState(GameDataRef data) : _data(data)
    {

    }
    void SplashState::Init()
    {
        this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
    }
    void SplashState::HandleInput()
    {
        sf::Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
        }

    }
    void SplashState::Update(float dt)
    {
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            //go to main menu
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
    }
    void SplashState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);
        this->_data->window.draw(this->_background);
        this->_data->window.display();
    }
}