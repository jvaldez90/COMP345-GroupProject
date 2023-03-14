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
#include "Player.h"

// SWITCH CASES FOR ENUMERATIONS
// Reference: https://en.cppreference.com/w/cpp/language/enum

//      SWTICH CASES FOR GAME COMMANDS ENUMERATIONS
std::ostream& operator<<(std::ostream& cout, GameEngine::GameCommands gc){
    switch(gc){
        case GameEngine::LOADMAP: cout << "loadmap";         break;
        case GameEngine::VALIDATEMAP: cout << "validatemap"; break;
        case GameEngine::ADDPLAYER: cout << "addplayer";     break;
        case GameEngine::GAMESTART: cout << "gamestart";     break;
        case GameEngine::REPLAY: cout << "replay";           break;
        case GameEngine::QUIT: cout << "quit";               break;
        case GameEngine::ISSUEORDER: cout << "issueorder";   break;
        case GameEngine::ENDISSUEORDERS: cout << "endissueorders";      break;
        case GameEngine::EXEORDER: cout << "exeorder";       break;
        case GameEngine::ENDEXEORDERS: cout << "endexeorders"; break;
        default: cout << "Invalid command.";                 break;
    }
    return cout;
}
//      SWITCH CASES FOR GAME STATES ENUMERATIONS
std::ostream& operator<<(std::ostream& cout, GameEngine::GameStates gs){
switch(gs){
    case GameEngine::START: cout << "start";                break;
    case GameEngine::MAPLOADED: cout << "maploaded";        break;
    case GameEngine::MAPVALIDATED: cout << "mapvalidate";   break;
    case GameEngine::PLAYERSADDED: cout << "playersadded";  break;
    case GameEngine::ASSIGNREINFORCEMENT: cout << "assignreinforcement";    break;
    case GameEngine::WIN: cout << "win";                    break;
    default: cout << "Invalid command.";                    break;
}
return cout;
}

GameEngine::GameEngine(){       // Default Constructor
    isRunning = true;
};
GameEngine::~GameEngine(){      // Destructor
};
void GameEngine::Run(){
    while(isRunning){
            GameEngine::startUpPhase();
            GameEngine::Play();
        }
}
void GameEngine::startUpPhase(){
    std::cout << std::endl;
    std::cout << "GameEngine::startUpPhase()" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Enter command start: ";
    std::cin >> command;

    // GAME STARTUP
    // While commands are valid GameCommands and GameStates
    do { // START STATE
        if (command == "start") {
            std::cout << "\t" << START << " command entered." << std::endl;
            std::cout << "\tCurrently in " << START << " state." << std::endl;
            std::cout << "Enter command loadmap: "<< std::endl;
            std::cin >> command;
        } 
        // MAP LOADED STATE
        while (command == "loadmap"){
            std::cout << "\t" << LOADMAP << " command entered." << std::endl;
            std::cout << "\tCurrently in " << MAPLOADED << " state." << std::endl;

            GameEngine::mapLoaded();

            std::cout << "Enter command validatemap\n\t" 
                      << "if done loading map\n\t"
                      << "else enter command loadmap: " << std::endl;
            std::cin >> command;
        }
        // MAP VALIDATED STATE
        if (command == "validatemap"){
            std::cout << "\t" << VALIDATEMAP << " command entered." << std::endl;
            std::cout << "\tCurrently in " << MAPVALIDATED << " state." << std::endl;


            std::cout << "Enter command addplayer: "<< std::endl;
            std::cin >> command;
        }
        // ADD PLAYER STATE
        while (command == "addplayer"){
            std::cout << "\t" << ADDPLAYER << " command entered." << std::endl;
            std::cout << "\tCurrently in " << PLAYERSADDED << " state. " << std::endl;

            GameEngine::playersAdded();

            std::cout << "Enter command gamestart\n\t" 
                      << "if done adding players\n\t"
                      << "else enter command addplayer: " << std::endl;
            std::cin >> command;
        }
    } while (command == "start" || command == "loadmap" || command == "validatemap" || command == "addplayer");
    
    // assigncountries command
}
void GameEngine::Play(){
    // While-loop
    std::cout << "\tCurrently in " << ASSIGNREINFORCEMENT << " state." << std::endl;
    GameEngine::assignReinforcement();
    std::cout << "Setting command to issueorder" << std::endl;
    command = "issueorder";
    do{
        // Loop issueorder command
        while (command == "issueorder"){
            std::cout << "\tCurrently in " << ISSUEORDER << "s state." << std::endl;
            
            GameEngine::issueOrders();

            std::cout << "Enter command endissueorders\n\t" 
                      << "if done issuing orders\n\t"
                      << "else enter command issueorder: " << std::endl;
            std::cin >> command;
            if(command == "issueorder") {
                std::cout << "\t" << ISSUEORDER << " command entered." << std::endl;
            }
        }
        // endissueorders command to end loop
        command = "exeorder";

        // Loop exeorder command
        while (command == "exeorder"){
            std::cout << "\tCurrently in " << EXEORDER << "s state." << std::endl;

            GameEngine::executeOrders();

            std:: cout << "Enter command endexeorders or win\n\t"
                       << "if done executing orders\n\t"
                       << "else enter command exeorder: " << std::endl;
            std::cin >> command;
            if (command == "exeorder"){
                std::cout << EXEORDER << " command entered." << std::endl;
            } else if (command == "win"){
                std::cout << WIN << " command entered." << std::endl;
            }
        }
        // endexeorders command to end loop
        if(command == "endexeorders"){
            std::cout << "\tCurrently in " << ASSIGNREINFORCEMENT << " state." << std::endl;
            GameEngine::assignReinforcement();
            command = "issueorder";
        }
        else if (command == "win"){
            // win command to end loop
             std::cout << "\tCurrently in " << WIN << " state." << std::endl;
            GameEngine::Win();
            std:: cout << "Enter command replay\n\t"
                       << "if to play game again\n\t"
                       << "else enter command quit: " << std::endl;
            std::cin >> command;
        }
    }while(
        command == "issueorder" ||
        command == "endissueorders" ||
        command == "exeorder" ||
        command == "endexeorders" ||
        command == "win"
        );
    
    if (command == "replay"){
        GameEngine::startUpPhase();
    }else if (command == "quit"){
        GameEngine::ExitProgram();
    }
}
void GameEngine::Win(){
    std::cout << std::endl;
    std::cout << "GameEngine::Win()" << std::endl;
    std::cout << "============================" << std::endl;
}
void GameEngine::mapLoaded(){
    std::cout << std::endl;
    std::cout << "GameEngine::mapLoaded()" << std::endl;
    std::cout << "============================" << std::endl;
    
    // std::cout << "Enter a map file name: ";
    // std::cin >> command;
    // MapLoader map;
    // map.load(command);

    // GameEngine::MapValidated(command);
}
void GameEngine::MapValidated(std::string command){
    std::cout << std::endl;
    std::cout << "GameEngine::MapValidated()" << std::endl;
    std::cout << "============================" << std::endl;

    // Map::validate();

}
void GameEngine::playersAdded(){
    std::cout << std::endl;
    std::cout << "GameEngine::playersAdded()" << std::endl;
    std::cout << "============================" << std::endl;

}
void GameEngine::assignReinforcement(){
    std::cout << std::endl;
    std::cout << "GameEngine::assignReinforcement()" << std::endl;
    std::cout << "============================" << std::endl;
}
void GameEngine::issueOrders(){
    std::cout << std::endl;
    std::cout << "GameEngine::issueOrders()" << std::endl;
    std::cout << "============================" << std::endl;
}
void GameEngine::executeOrders(){
    std::cout << std::endl;
    std::cout << "GameEngine::executeOrders()" << std::endl;
    std::cout << "============================" << std::endl;
}