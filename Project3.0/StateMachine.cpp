/*
 * COP 3003 - Game Menu
 * Sources:
 * https://www.sfml-dev.org/tutorials/2.5/ - sfml website: download code.
 * https://en.sfml-dev.org/forums/index.php?topic=8536.0 - sfml dev on how code works.
 * http://gamedevgeek.com/tutorials/managing-game-states-in-c/ - How game states work and how to implement
 * https://github.com/SonarSystems - code for game state algorithm and chest game algorithm
 * Special thanks to people on SFML dev website, game state, and sonar systems for aid in project.
 */

#include "StateMachine.h"
 namespace GioState
 {
    void StateMachine::AddState(StateRef newState, bool isReplacing)
    {
     this->_isAdding = true;
     this->_isReplacing = isReplacing;

     this->_newState = std::move(newState);
    }

    void  StateMachine::RemoveState()
    {
        this->_isRemoving = true;
    }

    void StateMachine::ProcessStateChanges()
    {
        if (this->_isRemoving && !this->_states.empty())
        {
            this->_states.pop();
            if(!this->_states.empty())
            {
                this->_states.top()->Resume();
            }
            this->_isRemoving = false;
        }
        if(this->_isAdding)
        {
            if (!this->_states.empty())
            {
                if(this->_isReplacing)
                {
                    this->_states.pop();
                }
                else
                {
                    this->_states.top()->Pause();
                }
            }
            this->_states.push( std::move(this->_newState));
            this->_states.top()->Init();
            this->_isAdding = false;
        }
    }
    StateRef  &StateMachine::GetActiveState()
    {
        return this->_states.top();
    }
 }