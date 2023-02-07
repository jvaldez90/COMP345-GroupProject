/**
 * @file GameEngineDriver.cpp
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
#include "GameEngine.h"
using namespace std;

int main() {
    // SETTING UP FOR A GAMEPLAY
    start();
    mapLoader();
    mapValidate();
    playersAdded(2);


    //TESTING VARIABLES
    string countries[] = {"France", "England", "Amsterdam"};
    int turn = 0;      // Counter for Player turns

    // BEGIN GAMEPLAY
    do{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "TURN: ["<< turn << "]"<< std::endl;
        assignReinforcement(countries);
        executeOrder();
        issueOrder();
        turn++;
    } while(turn < 6);
    

    win();

    return 0;
}