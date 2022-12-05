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

#include <map>

#include <SFML/Graphics.hpp>

namespace GioState
{
    class AssetManager
    {
    public:
        AssetManager(){}
        ~AssetManager(){}

        void LoadTexture(std::string name, std::string fileName );
        sf::Texture &GetTexture(std::string name);

        void LoadFont(std::string name, std::string fileName );
        sf::Font &GetFont(std::string name);

    private:
        std::map<std::string , sf::Texture> _textures;
        std::map<std::string , sf::Font> _fonts;

    };
}