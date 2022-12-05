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
#include <vector>
#include <vector>
#include "Game.h"

namespace GioState {
    class AI {
    public:
        AI(int playerPiece, GameDataRef data);

        void PlacePiece(int(*gridArray)[3][3], sf::Sprite gridPieces[3][3], int *gameState);

    private:
        void CheckSection(int x1, int y1, int x2, int y2, int X, int Y, int pieceToCheck, int(*gridArray)[3][3],
                          sf::Sprite gridPieces[3][3]);

        void CheckIfPieceIsEmpty(int X, int Y, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3]);

        int aiPiece;
        int playerPiece;

        std::vector<std::array<int, 6>> checkMatchVector;

        GameDataRef _data;

    };
}