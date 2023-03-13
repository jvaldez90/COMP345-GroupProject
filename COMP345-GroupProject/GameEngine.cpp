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
// #include "Card.h"
// #include "Map.h"
// #include "Orders.h"
// #include "Player.h"

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
        case GameEngine::ASSIGNCOUNTRIES: cout << "assigncountries";    break;
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
    // While command is are valid GameCommands and GameStates
    do {
        if (command == "start") {
            std::cout << "\t" << START << " command entered." << std::endl;
            std::cout << "\tCurrently in " << START << " state." << std::endl;
        }
        std::cout << "Enter command loadmap: "<< std::endl;
        std::cin >> command;

        if (command == "loadmap"){
            std::cout << "\t" << LOADMAP << " command entered." << std::endl;
            std::cout << "\tCurrently in " << MAPLOADED << " state." << std::endl;

            GameEngine::mapLoaded();
        }
        std::cout << "Enter command validatemap: "<< std::endl;
        std::cin >> command;
        if (command == "validatemap"){
            std::cout << "\t" << VALIDATEMAP << " command entered." << std::endl;
            std::cout << "\tCurrently in " << MAPVALIDATED << " state." << std::endl;
        }
        std::cout << "Enter command addplayer: "<< std::endl;
        std::cin >> command;
        if (command == "addplyer"){
            std::cout << "\t" << ADDPLAYER << " command entered." << std::endl;
            std::cout << "\tCurrently in " << PLAYERSADDED << " state. " << std::endl;

            GameEngine::playersAdded();
        }
        command = "gamestart";

    } while (command == "start" || command == "loadmap" || command == "validatemap" || command == "addplayer");
    
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
        GameEngine::executeOrders();
        // endexeorders command to end loop

        // win command to end loop
    }
    
    GameEngine::Win();
}
void GameEngine::Win(){
    std::cout << std::endl;
    std::cout << "GameEngine::Win()" << std::endl;
    std::cout << "============================" << std::endl;
    // if play command
    // GameEngine::startUpPhase();
    // else end command
    std::cout << std::endl;
    std::cout << "GameEngine::ExitProgram()" << std::endl;
    std::cout << "============================" << std::endl;
    GameEngine::ExitProgram();
}
void GameEngine::mapLoaded(){
    std::cout << std::endl;
    std::cout << "GameEngine::mapLoaded()" << std::endl;
    std::cout << "============================" << std::endl;
    
    std::cout << "Enter a map file name: ";
    std::cin >> command;
    // MapLoader map;
    // map.load(command);

    GameEngine::MapValidated(command);
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