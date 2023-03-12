/**
 * @file GameEngine.cpp
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
#include <iostream>
#include <string>
#include "GameEngine.h"


    GameEngine::GameEngine(){
        isRunning = true;
    };
    GameEngine::~GameEngine(){ 
    };
    void GameEngine::Run(){
        while(isRunning){
                GameEngine::startUpPhase();
                GameEngine::Play();
            }
    }
    void GameEngine::startUpPhase(){
        std::cout << std::endl << std::endl;
        std::cout << "GameEngine::startUpPhase()" << std::endl;
        std::cout << "============================" << std::endl;

        // GAME SET UP
        // While command is a valid GameState
        {
            // Loop  loadmap command 
            GameEngine::mapLoaded();

            // validatemap command
            GameEngine::mapValidated();

            // Loop addPlayer command
            GameEngine::playersAdded();
        }
        // assigncountries command
    }
    void GameEngine::Play(){
        // While-loop
        GameEngine::assignReinforcement();
        {
            // Loop issueorder command
            GameEngine::issueOrders();
            // endissueorders command to end loop

            // Loop exeorder command
            GameEngine::executeOrderes();
            // endexeorders command to end loop

            // win command to end loop
        }
        
        GameEngine::Win();
    }
    void GameEngine::Win(){
        // if play command
        // GameEngine::startUpPhase();
        // else end command
        GameEngine::Shutdown();
    }
    void GameEngine::mapLoaded(){
        std::cout << std::endl << std::endl;
        std::cout << "GameEngine::mapLoaded()" << std::endl;
        std::cout << "============================" << std::endl;
    }
    void GameEngine::mapValidated(){
        std::cout << std::endl << std::endl;
        std::cout << "GameEngine::mapValidated()" << std::endl;
        std::cout << "============================" << std::endl;
    }
    void GameEngine::playersAdded(){
        std::cout << std::endl << std::endl;
        std::cout << "GameEngine::playersAdded()" << std::endl;
        std::cout << "============================" << std::endl;

    }
    void GameEngine::assignReinforcement(){
        std::cout << std::endl << std::endl;
        std::cout << "GameEngine::assignReinforcement()" << std::endl;
        std::cout << "============================" << std::endl;
    }
    void GameEngine::issueOrders(){
        std::cout << std::endl << std::endl;
        std::cout << "GameEngine::issueOrders()" << std::endl;
        std::cout << "============================" << std::endl;
    }
    void GameEngine::executeOrderes(){
        std::cout << std::endl << std::endl;
        std::cout << "GameEngine::executeOrders()" << std::endl;
        std::cout << "============================" << std::endl;
    }