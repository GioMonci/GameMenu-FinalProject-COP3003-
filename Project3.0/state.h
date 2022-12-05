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

namespace GioState
{
    class State
    {
    public:
        virtual void Init () = 0;

        virtual void HandleInput () = 0;
        virtual void Update (float dt) = 0;
        virtual void Draw (float dt) = 0;

        virtual void Pause (){}
        virtual void Resume (){}

    };
}