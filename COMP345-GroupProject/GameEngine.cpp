/**
 * @file GameEngine.cpp
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
#include <iostream>
#include <string>
#include "GameEngine.h"

    Game::Game(){
    };
    Game::~Game(){ 
    };
    

// // Global Variables
// bool done = false;                  // Control for while-loops
// const int NUMBER_OF_ORDERS = 3;       // Temporary Variable

// // Functions for [STARTUP] of Game
// void start(){
//     std::cout << std::endl;
//     std::cout << "============================" << std::endl;
//     std::cout << "  STARTING UP WARZONE GAME  " << std::endl;
//     std::cout << "============================" << std::endl;
    
// }
// void mapLoader(){
//     // Load Map
//     // ** Make a call to Class Map::loader();
//     std::cout << "Call to mapLoader()" << std::endl;

//     string map;    
//     std::cout << std::endl << "Select a Map: " << std::endl;
//     std::cin >> map;
//     std::cout << "    Map Selected: " << map << std::endl;

//     bool loadMap = false;       // Temporary variable
//     while(!loadMap){
//         // Call to Map::loader();
//         std::cout << "    Loading the following Map: " << map << std::endl;
//         loadMap = true;
//     }
// }
// bool mapValidate(){
//     // Check if map loaded is valid
//     // ** Make a call to Class Map::validate();
//     std::cout << "Call to mapValidated()"<< std::endl;
//     if (true){   
//         // If map loaded exists, it should be valid
//         return true;
//     }
// }
// int playersAdded(int addPlayer){
//     // ** Make a call to Player() class to create a new Player
//     std::cout << "Call to playersAdded()"<< std::endl;
   
//     do{
//         // Display add Player
//         for(int i = 1; i <= addPlayer; i++){
//             std::cout << "    Players Added: " << i << std::endl;
//         }
//         done = true;
//     } while(!done);
//     return addPlayer;
// }

// // Functions for [PLAY] of Game
// void assignReinforcement(string assignCountries[]){
//     // ** Make a call to Player() class to assign 
//     //    a list of territories to each Player
//     std::cout << "Call to assignReinforcements()" << std::endl;
//     std::cout << "    Assigning lists of territories to each player." << std::endl;
//     // Player::issueOrders();
//     do {
//         for (int i = 0; i < NUMBER_OF_ORDERS; i++){
//             std::cout << "    Assigning Countries ... " << std::endl;
//         }
//         done = true;
//     } while(!done);
// }
// void executeOrder(){
//     // ** Make a call to OrderList::execute();
//     std::cout << "Call to executeOrder()" << std::endl;
//     std::cout << "    Player ______ is executing orders." << std::endl;
//     do {
//         for (int i = 0; i < NUMBER_OF_ORDERS; i++){
//             std::cout << "    Executing Orders ... " << std::endl;
//         }
//         done = true;
//     } while(!done);
// }
// void issueOrder(){
//     // Make a call to Player::issueOrder();
//     std::cout << "Call to issueOrders()" << std::endl;
//     std::cout << "    Player ______ is issuing an order." << std::endl;
//     do {
//         for (int i = 0; i < NUMBER_OF_ORDERS; i++){
//             std::cout << "    Issuing Orders ... " << std::endl;
//         }
//         done = true;
//     } while(!done);
// }
// void win(){
//     std::cout << "Call to win()" << std::endl;
//     std::cout << "    Player _____ wins " << std::endl;
// }