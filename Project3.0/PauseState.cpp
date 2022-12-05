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
#include "PauseState.h"
#include "DEFINITIONS.h"
#include <iostream>
#include "GameState.h"
#include "MainMenuState.h"

namespace GioState
{
    PauseState::PauseState(GameDataRef data) : _data(data)
    {

    }
    void PauseState::Init()
    {
        this->_data->assets.LoadTexture("BackGround2", PAUSE_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("ResumeButton", RESUME_BUTTON);
        this->_data->assets.LoadTexture("HomeButton", HOME_BUTTON);

        this->_background2.setTexture(this->_data->assets.GetTexture("BackGround2"));
        this->_resumeButton.setTexture(this->_data->assets.GetTexture("ResumeButton"));
        this->_homeButton.setTexture(this->_data->assets.GetTexture("HomeButton"));

        this->_resumeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width /2), (this->_data->window.getSize().y / 3) - (this->_resumeButton.getLocalBounds().height /2));
        this->_homeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_homeButton.getLocalBounds().width /2), (this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height /2));


    }

    void PauseState::HandleInput()
    {
        sf::Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            if(this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.RemoveState();
            }
            if(this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.RemoveState();
                this->_data->machine.AddState( StateRef(new MainMenuState(_data)), true);
            }

        }
    }
    void PauseState::Update(float dt)
    {

    }
    void PauseState::Draw(float dt)
    {
        this->_data->window.clear();
        this->_data->window.draw(this->_background2);
        this->_data->window.draw(this->_resumeButton);
        this->_data->window.draw(this->_homeButton);

        this->_data->window.display();

    }
}
