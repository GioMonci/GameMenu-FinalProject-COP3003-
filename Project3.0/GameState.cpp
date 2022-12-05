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
#include "GameState.h"
#include "DEFINITIONS.h"
#include <iostream>
#include "MainMenuState.h"
#include "PauseState.h"
#include "GameOverState.h"

namespace GioState
{
    GameState::GameState(GameDataRef data) :_data(data){

    }
    void GameState::Init()
    {
        gameState = STATE_PLAYING;
        turn = PLAYER_PIECE;

        this->ai = new AI(turn, this->_data);

        this->_data->assets.LoadTexture("BackGround1", GAME_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("PauseButton", PAUSE_BUTTON);
        this->_data->assets.LoadTexture("GridSprite", GRID_SPRITE_FILE_PATH);
        this->_data->assets.LoadTexture("X Piece", X_PIECE_FILEPATH);
        this->_data->assets.LoadTexture("O Piece", O_PIECE_FILEPATH);
        this->_data->assets.LoadTexture("X Winning Piece", X_WINNING_PIECE_FILEPATH);
        this->_data->assets.LoadTexture("O Winning Piece", O_WINNING_PIECE_FILEPATH);


        _background1.setTexture(this->_data->assets.GetTexture("BackGround1"));
        _pauseButton.setTexture(this->_data->assets.GetTexture("PauseButton"));
        _gridSprite.setTexture(this->_data->assets.GetTexture("GridSprite"));


        _pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);
        _gridSprite.setPosition((SCREEN_WIDTH / 2) - (_gridSprite.getGlobalBounds().width /2), (SCREEN_WIDTH / 2) - (_gridSprite.getGlobalBounds().height));

        InitGridPieces();

        for(int x = 0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++)
            {
                gridArray[x][y] = EMPTY_PIECE;
            }
        }
    }

    void GameState::HandleInput()
    {
        sf::Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            if(this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
            }
            else if (this->_data->input.IsSpriteClicked(this->_gridSprite, sf::Mouse::Left, this->_data->window))
            {
                if(STATE_PLAYING == gameState)
                {
                    this->CheckAndPlacePiece();

                }
            }
        }
    }
    void GameState::Update(float dt)
    {
        if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
        {
            if (this->_clock.getElapsedTime().asSeconds() > TIME_BEFORE_SHOWING_GAME_OVER)
            {
                // Switch To Main Menu
                this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
            }
        }
    }
    void GameState::Draw(float dt)
    {
        this->_data->window.clear();
        this->_data->window.draw(this->_background1);
        this->_data->window.draw(this->_pauseButton);
        this->_data->window.draw(this->_gridSprite);
        for(int x = 0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++)
            {
                this->_data->window.draw(this->_gridPieces[x][y]);

            }
        }

        this->_data->window.display();

    }
    void GameState::InitGridPieces()
    {
        sf::Vector2u tempSpriteSize = this->_data->assets.GetTexture("X Piece").getSize();
        for(int x = 0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++){
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("X Piece"));
                _gridPieces[x][y].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x * x) - 7 , _gridSprite.getPosition().y + (tempSpriteSize.y * y) -7 );
                _gridPieces[x][y].setColor(sf::Color(255,255,255,0));
            }
        }
    }
    void GameState::CheckAndPlacePiece()
    {
        sf::Vector2i touchPoint = this->_data->input.GetMousePosition(this->_data->window);
        sf::FloatRect gridSize = _gridSprite.getGlobalBounds();
        sf::Vector2f gapOutsideOfGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width) / 2, (SCREEN_HEIGHT - gridSize.height) / 2);

        sf::Vector2f gridLocalTouchPos = sf::Vector2f(touchPoint.x - gapOutsideOfGrid.x, touchPoint.y - gapOutsideOfGrid.y);

        //std::cout << gridLocalTouchPos.x << ", " << gridLocalTouchPos.y << std::endl;

        sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.width / 3, gridSize.height / 3);

        int column, row;

        // Check which column the user has clicked
        if (gridLocalTouchPos.x < gridSectionSize.x) // First Column
        {
            column = 1;
        }
        else if (gridLocalTouchPos.x < gridSectionSize.x * 2) // Second Column
        {
            column = 2;
        }
        else if (gridLocalTouchPos.x < gridSize.width) // Third Column
        {
            column = 3;
        }

        // Check which row the user has clicked
        if (gridLocalTouchPos.y < gridSectionSize.y) // First Row
        {
            row = 1;
        }
        else if (gridLocalTouchPos.y < gridSectionSize.y * 2) // Second Row
        {
            row = 2;
        }
        else if (gridLocalTouchPos.y < gridSize.height) // Third Row
        {
            row = 3;
        }

        if (gridArray[column - 1][row - 1] == EMPTY_PIECE)
        {
            gridArray[column - 1][row - 1] = turn;

            if (PLAYER_PIECE == turn)
            {
                _gridPieces[column - 1][row - 1].setTexture(this->_data->assets.GetTexture("X Piece"));

                this-> CheckPlayerHasWon(turn);
            }

            _gridPieces[column - 1][row - 1].setColor(sf::Color(255, 255, 255, 255));
        }
    }
    void GameState::CheckPlayerHasWon(int player)
    {
        Check3PiecesForMatch(0, 0, 1, 0, 2, 0, player);
        Check3PiecesForMatch(0, 1, 1, 1, 2, 1, player);
        Check3PiecesForMatch(0, 2, 1, 2, 2, 2, player);
        Check3PiecesForMatch(0, 0, 0, 1, 0, 2, player);
        Check3PiecesForMatch(1, 0, 1, 1, 1, 2, player);
        Check3PiecesForMatch(2, 0, 2, 1, 2, 2, player);
        Check3PiecesForMatch(0, 0, 1, 1, 2, 2, player);
        Check3PiecesForMatch(0, 2, 1, 1, 2, 0, player);

        if(STATE_WON != gameState)
        {
            gameState = STATE_AI_PLAYING;
            ai->PlacePiece(&gridArray, _gridPieces, &gameState);
            Check3PiecesForMatch(0, 0, 1, 0, 2, 0, AI_PIECE);
            Check3PiecesForMatch(0, 1, 1, 1, 2, 1, AI_PIECE);
            Check3PiecesForMatch(0, 2, 1, 2, 2, 2, AI_PIECE);
            Check3PiecesForMatch(0, 0, 0, 1, 0, 2, AI_PIECE);
            Check3PiecesForMatch(1, 0, 1, 1, 1, 2, AI_PIECE);
            Check3PiecesForMatch(2, 0, 2, 1, 2, 2, AI_PIECE);
            Check3PiecesForMatch(0, 0, 1, 1, 2, 2, AI_PIECE);
            Check3PiecesForMatch(0, 2, 1, 1, 2, 0, AI_PIECE);
        }

        int emptyNum = 9;

        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (EMPTY_PIECE != gridArray[x][y])
                {
                    emptyNum--;
                }
            }
        }
        if (0 == emptyNum && (STATE_WON != gameState) && (STATE_LOSE != gameState))
        {
            gameState = STATE_DRAW;
        }

        // check if the game is over
        if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
        {
            // show game over
            this->_clock.restart( );
        }

        std::cout << gameState << std::endl;
    }
    void GameState::Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck)
    {
            if (pieceToCheck == gridArray[x1][y1] && pieceToCheck == gridArray[x2][y2] && pieceToCheck == gridArray[x3][y3])
            {
                std::string winningPieceStr;

                if (O_PIECE == pieceToCheck)
                {
                    winningPieceStr = "O Winning Piece";
                }
                else
                {
                    winningPieceStr = "X Winning Piece";
                }

                _gridPieces[x1][y1].setTexture(this->_data->assets.GetTexture(winningPieceStr));
                _gridPieces[x2][y2].setTexture(this->_data->assets.GetTexture(winningPieceStr));
                _gridPieces[x3][y3].setTexture(this->_data->assets.GetTexture(winningPieceStr));


                if (PLAYER_PIECE == pieceToCheck)
                {
                    gameState = STATE_WON;
                }
                else
                {
                    gameState = STATE_LOSE;
                }
            }
    }
}
