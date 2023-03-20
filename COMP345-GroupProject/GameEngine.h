/**
 * @file GameEngine.h
 * 
 * CONCORDIA UNIVERSITY
 * COMP 345: Advanced Program Design with C++
 * Section S
 * Professor: Amin Ranj Bar
 * 
 * GROUP PROJECT: ASSIGNMENT 1 PART 5: GAME ENGINE
 *                ASSINGMENT 2 PART 2: GAME STARTUP PHASE
 * 
 * @author Joy Anne Valdez
 * Student ID: 26339379
 * 
 * @date 2023-01-26
 * 
 */

#include <string>
#include <vector>
// #include "Player.h"
#include "Map.h"
using std::string;

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine {
    public:
        GameEngine();
        std::string command;
        std::vector<std::string> *p;
        // vector<Player> *p;
        Map *playingMap;
        
        enum GameCommands {
            LOADMAP, 
            VALIDATEMAP, 
            ADDPLAYER, 
            GAMESTART,
            REPLAY,
            QUIT,
            ISSUEORDER, 
            ENDISSUEORDERS, 
            EXEORDER, 
            ENDEXEORDERS
        };
        enum GameStates {
            START,
            MAPLOADED, 
            MAPVALIDATED,
            PLAYERSADDED,
            ASSIGNREINFORCEMENT,
            WIN
        };
        void Run ();
        void Play();
        void ExitProgram() { isRunning = false; }
        
        // Functions for [PLAY] of Game
        void assignReinforcement();
        void issueOrders();
        void executeOrders();
        void Win();

        ~GameEngine();

    private:
        // Private Data Members
        int playerCounter;
        bool isRunning;
        
        void InvalidCommand();

        // Functions for [START] of Game        
        void startUpPhase();
        void mapLoaded();
        void MapValidated(std::string& command);
        void playersAdded();
};

#endif /* GAMEENGINE_H */
