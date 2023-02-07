/**
 * @file GameEngine.cpp
 * 
 * CONCORDIA UNIVERSITY
 * COMP 345: Advanced Program Design with C++
 * Section S
 * Professor: Amin Ranj Bar
 * 
 * GROUP PROJECT: ASSIGNMENT 1
 * 
 * @author Joy Anne Valdez
 * Student ID: 26339379
 *
 * @date 2023-01-26
 *  
 */
#include <iostream>
#include <string>
#include "GameEngine.h"


// Functions for [STARTUP] of Game
void start(){
    std::cout << "============================" << std::endl;
    std::cout << "  STARTING UP WARZONE GAME  " << std::endl;
    std::cout << "============================" << std::endl;
    
}
void mapLoader(){
    // Load Map
    // Make a call to Class Map::loader();
    std::cout << "Call to mapLoader()" << std::endl;

    string map;    
    std::cout << std::endl << "Select a Map: " << std::endl;
    std::cin >> map;
    std::cout << "Map Selected: " << map << std::endl;
    /*   PSEUDOCODE
     while(!loadMap){
        Map::loader();
     } 
     */
}
bool mapValidate(){
    // Check if map loaded is valid
    // Make a call to Class Map::validate();
    std::cout << "Call to mapValidated()"<< std::endl;
    if (true){ 
        return true;
    }
}
int playersAdded(int addPlayer){
    // Make a call to Player() class to create a new Player
    std::cout << "Call to playersAdded()"<< std::endl;
    std::cout << "    Players Added: " << addPlayer << std::endl;
    /*  PSEUDOCODE
    do{
        // add Player
    } while(!done);
    */
    return addPlayer;
}

// Functions for [PLAY] of Game
void assignReinforcement(string assignCountries[]){
    // Make a call to Player() class to assign list 
    // of territories to each Player
    std::cout << "Call to assignReinforcements()" << std::endl;
    std::cout << "Assigning lists of territories to each player." << std::endl;
    // issueOrders();
}
void executeOrder(){
    // Make a call to OrderList::execute();
    std::cout << "Call to executeOrder()" << std::endl;
    std::cout << "Player ______ is executing orders." << std::endl;
    /* PSEUDOCODE
    do {
        executeOrder();
    } while(!done);
    */
   // if (done) then end executeOrder();
}
void issueOrder(){
    // Make a call to Player::issueOrder();
    std::cout << "Call to issueOrders()" << std::endl;
    std::cout << "Player ______ is issuing an order." << std::endl;
    /* PSEUDOCODE
    do {
        issueOrder();
    } while(!done);
    */
   // if (done) then end issueOrders();
}
void win(){
    std::cout << "Call to win()" << std::endl;
    std::cout << "Player _____ wins " << std::endl;
    // PSEUDOCODE
    // if user wants to play again
    //     call start();
    // else exit game
}