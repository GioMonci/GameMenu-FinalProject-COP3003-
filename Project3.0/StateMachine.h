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

#include <memory>
#include <stack>

#include "state.h"

namespace GioState
{
    typedef std::unique_ptr<State> StateRef;

    class StateMachine
    {
    public:
        StateMachine(){}
        ~StateMachine(){}

        void AddState (StateRef newState, bool isReplacing = true);
        void RemoveState();

        void ProcessStateChanges();

        StateRef &GetActiveState();

    private:
        std::stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;

    };
}