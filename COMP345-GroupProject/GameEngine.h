/**
 * @file GameEngine.h
 * 
 * CONCORDIA UNIVERSITY
 * COMP 345: Advanced Program Design with C++
 * Section S
 * Professor: Amin Ranj Bar
 * 
 * GROUP PROJECT: ASSIGNMENT 1 PART 5: GAME ENGINE
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

class Game {
    public:
        Game();
        enum GameState {
            LOAD_MAP, 
            VALIDATE_MAP, 
            ADD_PLAYER, 
            ASSIGN_COUNTRIES, 
            ISSUE_ORDER, 
            END_ISSUE_ORDERS, 
            EXECUTE_ORDER, 
            END_EXECUTE_ORDERS, 
            WIN,
            END
        };
        void Run (){
            while(_running){
                startUpPhase();
                play();
            }
        }
        ~Game();
    private:
        // Varialbles
        bool _running = true;
        // Functions for [STARTUP] of Game        
        void startUpPhase(){}
        void mapLoaded(){}
        void mapValidated(){}
        void playersAdded(){}

        // Functions for [PLAY] of Game
        void play(){}
        void assingReinforcement(){}
        void issueOrders(){}
        void executeOrderes(){}
        void win(){}

};


// // Functions for STARTUP of Game
// void start();
// void mapLoader();
// bool mapValidate();
// int playersAdded(int addPlayer);

// // Functions for PLAY of Game
// void assignReinforcement(string assignCountries[]);
// void executeOrder();
// void issueOrder();
// void win();


#endif /* GAMEENGINE_H */
