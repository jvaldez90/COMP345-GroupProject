/**
 * @file GameEngine.cpp
 * 
 * CONCORDIA UNIVERSITY
 * COMP 345: Advanced Program Design with C++
 * Section S
 * Professor: Amin Ranj Bar
 * 
 * GROUP PROJECT: ASSIGNMENT 1 PART 5: GAME ENGINE
 *                ASSIGNMENT 2 PART 2: GAME STARTUP PHASE
 *                ASSIGNMENT 3 PART 2: TOURNAMENT MODE
 * 
 * @author Joy Anne Valdez
 * Student ID: 26339379
 *
 * @date 2023-01-26
 *  
 */
#include <iostream>
#include <string>
#include <vector>
#include "GameEngine.h"

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
        case GameEngine::TOURNAMENT: cout << "tournament";   break;
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
    std::cout << "~GameEngine() Destructor" << std::endl;
};

// MAIN GAME LOOP
void GameEngine::Run(){
    std::cout << std::endl;
    std::cout << "================" << std::endl;
    std::cout << "  WARZONE GAME  " << std::endl;
    std::cout << "================" << std::endl;

    // User selects between PLAY and TOURNAMENT Modes
    std::cout << std::endl;
    std::cout << "SELECT A MODE: play | tournament" << std::endl;
    std::cin >> command;

    if (command == "tourmanent"){
        std::cout << std::endl;
        std::cout << TOURNAMENT << " was selected" << std::endl;
        GameEngine::Tourmanent();
    } else {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Entering play mode" << std::endl;
        std::cout << std::endl;

        while(isRunning){
            GameEngine::startUpPhase();
            GameEngine::Play();
        }

    }

}
// startUpPhase()
void GameEngine::startUpPhase(){
    GameEngine::playerCounter = 0;
    // GAME STARTUP
    // While commands are valid GameCommands and GameStates
    while (command != "gamestart"){ 
        std::cout << std::endl;
        std::cout << "GameEngine::startUpPhase()" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "Enter command start: ";
        do { // START STATE
            std::cin >> command;
            
            while (command == "start") {
                std::cout << "\t" << START << " command entered." << std::endl;
                std::cout << "\tCurrently in " << START << " state." << std::endl;
                std::cout << "\nEnter command loadmap: "<< std::endl;
                std::cin >> command;
            }
            if (command != "start" &&  command != "loadmap"){
                GameEngine::InvalidCommand();
            }

            // MAP LOADED STATE
            while (command == "loadmap"){
                std::cout << "\t" << LOADMAP << " command entered." << std::endl;
                std::cout << "\tCurrently in " << MAPLOADED << " state." << std::endl;

                GameEngine::mapLoaded();

                std::cout << "\nEnter command validatemap\n\t" 
                          << "if done loading map\n\t"
                          << "else enter command loadmap: " << std::endl;
                std::cin >> command;

                if (command != "loadmap" && command != "validatemap"){
                    GameEngine::InvalidCommand();
                }
            }
            // MAP VALIDATED STATE
            if (command == "validatemap"){
                std::cout << "\t" << VALIDATEMAP << " command entered." << std::endl;
                std::cout << "\tCurrently in " << MAPVALIDATED << " state." << std::endl;

                std::cout << "\nEnter command addplayer: "<< std::endl;
                std::cin >> command;

                if (command != "addplayer"){
                    GameEngine::InvalidCommand();
                    command = "validatemap";
                }
            }
            // ADD PLAYER STATE
            while (command == "addplayer"){
                std::cout << "\t" << ADDPLAYER << " command entered." << std::endl;
                std::cout << "\tCurrently in " << PLAYERSADDED << " state. " << std::endl;
                
                if (GameEngine::playerCounter <= 1){
                    std::cout << "\nGAME REQUIREMENTS: \n\t"
                              << "2 - 6 Players are nedded to start the game.\n\t" 
                              << "Adding 2 players." << std::endl;
                    GameEngine::playersAdded();
                    GameEngine::playersAdded();
                    
                } else if (GameEngine::playerCounter > 5){
                    std::cout << "\n!!!!! WARNING !!!!!" << std::endl;
                    std::cout << "\nCannot add any more players" << std::endl;
                    std::cout << "Setting command to gamestart" << std::endl;
                    command = "gamestart";
                    break;

                } else {
                    GameEngine::playersAdded();
                }
                std::cout << std:: endl
                          << "\nEnter command gamestart\n\t" 
                          << "if done adding players\n\t"
                          << "else enter command addplayer: " << std::endl;
                std::cin >> command;
                
                if (command != "addplayer" && command != "gamestart"){
                    GameEngine::InvalidCommand();
                }
     
            }
        } while(command != "gamestart");
    }
}
// Play()
void GameEngine::Play(){
    // PLAY INITIALIZATION
    std::cout << "\nINITIALIZING GAME SET UP" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Farily distributing all territories to the players" << std::endl;
        
    // Get Number of Territories in Map 
    std::cout << std::endl;
    int totalNumberTerritories = playingMap->getTerritories().size();
    
    std::cout << "\nTotal Number of territories in the map: " << totalNumberTerritories << std::endl;

    // Then divide total map territories among the number of players
    int initialTerritories = totalNumberTerritories / GameEngine::playerCounter;
    std::cout << "Number of Players playing: " << GameEngine::playerCounter << std::endl;
    std::cout << "Each player initially recieves [" << initialTerritories << "] number of territories" <<std::endl;

    // Assign to all players an even amount of territories
    std::cout << std::endl;
    for (int i=0; i < GameEngine::playerCounter; i++){
        // In vector<Player> p assign initial number of territories from playingMap to each player 
        //Create lst of territories
        // call to Player::setTerritories
    }
    std::cout << std::endl;
    // Sorting the order in which player will take turns
    std::cout << "\nDetermining the order of play of the players in the game." << std::endl;
    std::cout << std::endl;

    std::vector<string> *playerOrder; // A Vector<string> indicating which players get to play in which order.

    // Round robin
    for (int i = 0; i< GameEngine::playerCounter; i++){
            playerOrder->push_back("Player_"+ std::to_string(i));
    }    
    // Assign Initial armies to players
    std::cout << "Giving 50 initial armies to the players, " 
              << "which are placed in their respective reinforcement pool" << std::endl;
              
    std::cout << std::endl;
    for (int i = 0; i < GameEngine::playerCounter; i++){
        std::cout << "PLAYER_" << i+1 << " gets 50 intial armies." << std::endl;
        std::cout << "\tFOR-LOOP logic p(i)->assign(50 armies)" << std::endl;
    }// Player needed variable int armies

    std::cout << std::endl;
    std::cout << "Letting each player draw 2 initial cards from the deck" << std::endl;
    for (int i=0; i< GameEngine::playerCounter; i++){
        std::cout << "PLAYER_" << i+1 << " draws 2 inital cards." << std::endl;
        std::cout << "\tCall to Card* Deck::draw()" << std::endl;

    }

    // BEGINNING OF GAME PLAY
    std::cout << "\tCurrently in " << ASSIGNREINFORCEMENT << " state.\n" << std::endl;
    GameEngine::assignReinforcement();

    std::cout << "Setting command to issueorder" << std::endl;
    command = "issueorder";
    // Do-while loop
    do{
        // Loop issueorder command
        while (command == "issueorder"){
            std::cout << "\tCurrently in " << ISSUEORDER << "s state." << std::endl;
            
            GameEngine::issueOrders();

            std::cout << std::endl;
            std::cout << "\nEnter command endissueorders\n\t" 
                      << "if done issuing orders\n\t"
                      << "else enter command issueorder: " << std::endl;
            std::cin >> command;
            if(command == "issueorder") {
                std::cout << "\t" << ISSUEORDER << " command entered." << std::endl;
            } else if (command != "issueorder" && command != "endissueorders"){
                GameEngine::InvalidCommand();
                command = "issueorder";
            }
        }
        // endissueorders command to end loop
        command = "exeorder";

        // Loop exeorder command
        while (command == "exeorder"){
            std::cout << "\tCurrently in " << EXEORDER << "s state." << std::endl;

            GameEngine::executeOrders();

            std:: cout << "\nEnter command endexeorders or win\n\t"
                       << "if done executing orders\n\t"
                       << "else enter command exeorder: " << std::endl;
            std::cin >> command;
            if (command == "exeorder"){
                std::cout << EXEORDER << " command entered." << std::endl;
            } else if (command == "win"){
                std::cout << WIN << " command entered." << std::endl;
            } else if (command != "endexeorders" && command != "exeorder" && command != "win"){
                GameEngine::InvalidCommand();
                command = "exeorder";
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

            std::cout << std::endl;
            std:: cout << "Enter command replay\n\t"
                       << "if to play game again\n\t"
                       << "else enter command quit: " << std::endl;
            std::cin >> command;
            if (command != "replay" && command != "win" && command != "quit"){
                GameEngine::InvalidCommand();
            }
        }
    }while(
        command == "issueorder" || command == "endissueorders" || command == "exeorder" ||
        command == "endexeorders" || command == "win");
    
    if (command == "replay"){          // Return to START state
        GameEngine::startUpPhase();

    }else if (command == "quit"){
        p = nullptr;
        playingMap = nullptr;
        generateOrder = nullptr;
        playerOrder = nullptr;

        delete p;
        delete playingMap;
        delete generateOrder;
        delete playerOrder;

        GameEngine::ExitProgram();
    }
}
// Win()
void GameEngine::Win(){
    std::cout << std::endl;
    std::cout << "GameEngine::Win()" << std::endl;
    std::cout << "============================" << std::endl;

    std::cout << std::endl;
    std::cout << "PLAYER_ wins"<< std::endl;
    std::cout << std::endl;
}
// mapLoaded()
void GameEngine::mapLoaded(){
    std::cout << std::endl;
    std::cout << "GameEngine::mapLoaded()" << std::endl;
    std::cout << "============================" << std::endl;
    
    std::cout << "Enter a map file name: ";
    std::cin >> command;

    std::cout << std::endl;
    std::cout << "LOADING " << command << std::endl;
    std::cout << "CHECKING if " << command << " is a valid map ..." << std::endl;

    GameEngine::MapValidated(command);
}
// MapValidated()
void GameEngine::MapValidated(std::string& command){

    std::cout << std::endl;
    std::cout << "GameEngine::MapValidated()" << std::endl;
    std::cout << "============================" << std::endl;

    std::cout << std::endl;
    MapLoader map;
    playingMap = map.load(command);
    bool isValid = playingMap->validate();
    if (isValid == true){
        std::cout << command << " is a VALID map." << std::endl
    } else {
        std::cout << command << " is NOT a VALID map." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "GameEngine::MapValidated() has finished validating map." << std::endl;
}
//playersAdded()
void GameEngine::playersAdded(){

    std::cout << std::endl;
    std::cout << "GameEngine::playersAdded()" << std::endl;
    std::cout << "============================" << std::endl;
    
    std::string newPlayer = "PLAYER_" + std::to_string(GameEngine::playerCounter + 1);
    std::cout << newPlayer << " has been added." << std::endl;
    GameEngine::playerCounter++;
    std::cout << "Current number of players: " << GameEngine::playerCounter << std::endl;
    
    // Creating an instance object of type Player and push new player into vector<Player>
    std::cout << std::endl;
    Player *currentPlayer = new Player(newPlayer);
    p->push_back(*currentPlayer);
}
// assignReinforcement()
void GameEngine::assignReinforcement(){

    std::cout << std::endl;
    std::cout << "GameEngine::assignReinforcement()" << std::endl;
    std::cout << "============================" << std::endl;

    std::cout << std::endl;
    std::cout << "Current PLAYER_ calls:" << std::endl;
    std::cout << "\tPlayer::divideTerritories()" << std::endl;
}

// PART 3: ORDERS EXECUTION PHASE

//issueOrders() PHASE
void GameEngine::issueOrders(){
    std::cout << std::endl;
    std::cout << "GameEngine::issueOrders()" << std::endl;
    std::cout << "============================" << std::endl;

    std::cout << std::endl;
    std::cout << "Current PLAYER_ calls: " << std::endl;
    std::cout << "\tPlayer::issueOrder(std::string orderType)" << std::endl;
    //Round Robins
    // for loop or while loop
}
//executeOrders() PHASE
void GameEngine::executeOrders(){
    std::cout << std::endl;
    std::cout << "GameEngine::executeOrders()" << std::endl;
    std::cout << "============================" << std::endl;


    std::cout << std::endl;
    std::cout << "Current PLAYER_ calls: " << std::endl;
    std::cout << "\tPlayer::toAttack()" << std::endl;
    std::cout << "\tPlayer::toDefend()" << std::endl;
    //for loop or while loop
}
// InvalidCommand()
void GameEngine::InvalidCommand(){
    std::cout << "Invalid command entered. Try again." << std::endl;
}

// TOURNAMENT MODE
void GameEngine::Tourmanent(){
    std::cout << std::endl;
    std::cout << "TOURNAMENT MODE" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << std::endl;
    /*
        Allow a user to enter inputs for the following parameters
        M = List of map files           => LIST
        P = List of player strategies   => LIST
        G = number of games             => INT
        D = number of turns             => INT
    */
    /* PSEUDOCODE
    for (int i = 0; i < M.size(); i++){
        // Create a map object and validate map file
        Map M[i];
        for (int j = 0; j < G; j++){        // FOR-LOOP for tournament games
            for (int k = 0; k < D; k++){    // FOR-LOOP for number of turns
                
            }
        }
    }
    */
}