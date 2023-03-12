/**
 * @file GameEngine.h
 * 
 * CONCORDIA UNIVERSITY
 * COMP 345: Advanced Program Design with C++
 * Section S
 * Professor: Amin Ranj Bar
 * 
 * GROUP PROJECT: ASSIGNMENT 1 PART 5: GAME ENGINE
 *                ASSINGMENT 2 PART 2: GAME ENGINE
 * 
 * @author Joy Anne Valdez
 * Student ID: 26339379
 * 
 * @date 2023-01-26
 * 
 */

#include <string>
using std::string;

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine {
    public:
        GameEngine();
        string command;
        enum GameState {
            loadmap, 
            validatemap, 
            addplayer, 
            assigncountries, 
            issueorder, 
            endissueorders, 
            exeorder, 
            endexeorders, 
            win,
            end,
            play,
            gamestart
        };
        void Run ();
        void Play();
        void Shutdown() { isRunning = false; }
        ~GameEngine();
    private:
        // Private Data Members
        bool isRunning;

        // Functions for [STARTUP] of Game        
        void startUpPhase();
        void mapLoaded();
        void mapValidated();
        void playersAdded();

        // Functions for [PLAY] of Game
        void assignReinforcement();
        void issueOrders();
        void executeOrderes();
        void Win();

};

#endif /* GAMEENGINE_H */
