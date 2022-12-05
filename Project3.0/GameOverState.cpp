/*
 * COP 3003 - Game Menu
 * Sources:
 * https://www.sfml-dev.org/tutorials/2.5/ - sfml website: download code.
 * https://en.sfml-dev.org/forums/index.php?topic=8536.0 - sfml dev on how code works.
 * http://gamedevgeek.com/tutorials/managing-game-states-in-c/ - How game states work and how to implement
 * https://github.com/SonarSystems - code for game state algorithm and chest game algorithm
 * Special thanks to people on SFML dev website, game state, and sonar systems for aid in project.
 */

#include <sstream>
#include "GameOverState.h"
#include "DEFINITIONS.h"
#include <iostream>
#include "GameState.h"
#include "MainMenuState.h"

namespace GioState
{
    GameOverState::GameOverState(GameDataRef data) : _data(data)
    {

    }
    void GameOverState::Init()
    {
        this->_data->assets.LoadTexture("BACKGROUND3", GAMEOVER_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("RetryButton", RETRY_BUTTON);
        this->_data->assets.LoadTexture("HomeButton", HOME_BUTTON);

        this->_background3.setTexture(this->_data->assets.GetTexture("BACKGROUND3"));
        this->_retryButton.setTexture(this->_data->assets.GetTexture("RetryButton"));
        this->_homeButton.setTexture(this->_data->assets.GetTexture("HomeButton"));

        this->_retryButton.setPosition((this->_data->window.getSize().x / 2) - (this->_retryButton.getLocalBounds().width /2), (this->_data->window.getSize().y / 3) - (this->_retryButton.getLocalBounds().height /2));
        this->_homeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_homeButton.getLocalBounds().width /2), (this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height /2));


    }

    void GameOverState::HandleInput()
    {
        sf::Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            if(this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.AddState( StateRef(new GameState(_data)), true);
            }
            if(this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.AddState( StateRef(new MainMenuState(_data)), true);
            }

        }
    }
    void GameOverState::Update(float dt)
    {

    }
    void GameOverState::Draw(float dt)
    {
        this->_data->window.clear();
        this->_data->window.draw(this->_background3);
        this->_data->window.draw(this->_retryButton);
        this->_data->window.draw(this->_homeButton);

        this->_data->window.display();

    }
}
