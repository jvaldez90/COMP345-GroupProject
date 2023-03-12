/**
 * @file GameEngineDriver.cpp
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
#include "GameEngine.h"
using namespace std;

int main() {



    // bool done = false;
    // do{
    //     // SETTING UP FOR A GAMEPLAY
    //     start();
    //     mapLoader();
    //     mapValidate();
    //     playersAdded(2);


    //     //TESTING VARIABLES
    //     string countries[] = {"France", "England", "Amsterdam"};
    //     int turn = 0;      // Counter for Player turns

    //     // BEGIN GAMEPLAY
    //     do{
    //         std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    //         std::cout << "TURN: ["<< turn << "]"<< std::endl;

    //         assignReinforcement(countries);
    //         executeOrder();
    //         issueOrder();
    //         turn++;
    //     } while(turn < 3);

    //     win();
    //     std::cout << "Do you to play another game? (y/n)" << std::endl;
    //     char result;
    //     std::cin >> result;
    //     switch(result){
    //         case 'y':
    //             std::cout << std::endl;
    //             std::cout << "Restarting the game." << std::endl;
    //             std::cout << std::endl;
    //             break;
    //         case 'n':
    //             std::cout << std::endl;
    //             std::cout << "Thanks for playing. Exiting the Game." << std::endl;
    //             std::cout << std::endl;
    //             done = true;
    //             break;
    //         default:
    //             std::cout << std::endl;
    //             std::cout << "Invalid Resonse. Restarting the Game." << std::endl;
    //             std::cout << std::endl;
    //             result = 'y';
    //             break;
    //     }
    // }while(!done);

    return 0;
}