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
#include "AI.h"

namespace GioState
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        void InitGridPieces();

        void CheckAndPlacePiece();

        void CheckPlayerHasWon(int turn);
        void Check3PiecesForMatch(int x1, int y1,int x2, int y2,int x3, int y3, int pieceToCheck);

        GameDataRef _data;

        sf::Sprite _background1;

        sf::Sprite _pauseButton;

        sf::Sprite _gridSprite;

        sf::Sprite _gridPieces[3][3];
        int gridArray[3][3];

        int turn;
        int gameState;
        AI *ai;

        sf::Clock _clock;
    };
}