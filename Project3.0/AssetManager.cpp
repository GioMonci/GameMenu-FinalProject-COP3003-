/*
 * COP 3003 - Game Menu
 * Sources:
 * https://www.sfml-dev.org/tutorials/2.5/ - sfml website: download code.
 * https://en.sfml-dev.org/forums/index.php?topic=8536.0 - sfml dev on how code works.
 * http://gamedevgeek.com/tutorials/managing-game-states-in-c/ - How game states work and how to implement
 * https://github.com/SonarSystems - code for game state algorithm and chest game algorithm
 * Special thanks to people on SFML dev website, game state, and sonar systems for aid in project.
 */

#include "AssetManager.h"

namespace GioState
{
    void AssetManager::LoadTexture(std::string name, std::string fileName)
    {
        sf::Texture tex;
        if(tex.loadFromFile(fileName))
        {
            this->_textures[name] = tex;

        }
    }
    sf::Texture &AssetManager::GetTexture(std::string name)
    {
        return this->_textures.at(name);
    }

    void AssetManager::LoadFont(std::string name, std::string fileName)
    {
        sf::Font font;
        if(font.loadFromFile(fileName))
        {
            this->_fonts[name] = font;

        }
    }
    sf::Font &AssetManager::GetFont(std::string name) {
        return this->_fonts.at(name);
    }
}