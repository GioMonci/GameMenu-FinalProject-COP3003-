/*
 * COP 3003 - Game Menu
 * Sources:
 * https://www.sfml-dev.org/tutorials/2.5/ - sfml website: download code.
 * https://en.sfml-dev.org/forums/index.php?topic=8536.0 - sfml dev on how code works.
 * http://gamedevgeek.com/tutorials/managing-game-states-in-c/ - How game states work and how to implement
 * https://github.com/SonarSystems - code for game state algorithm and chest game algorithm
 * Special thanks to people on SFML dev website, game state, and sonar systems for aid in project.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "state.h"
#include "Game.h"

namespace GioState
{
    class MainMenuState : public State
    {
    public:
        MainMenuState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _background;

        sf::Sprite _playButton;

        sf::Sprite _playButtonOuter;


        sf::Sprite _title;

    };
}