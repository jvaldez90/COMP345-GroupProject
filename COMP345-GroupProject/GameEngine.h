/**
 * @file GameEngine.h
 *
 * CONCORDIA UNIVERSITY
 * COMP 345: Advanced Program Design with C++
 * Section S
 * Professor: Amin Ranj Bar
 *
 * GROUP PROJECT: ASSIGNMENT 1 PART 5: GAME ENGINE
 *                ASSINGMENT 2 PART 2: GAME STARTUP PHASE
 *                ASSIGNMENT 3 PART 2: TOURNAMENT MODE
 *
 * @author Joy Anne Valdez
 * Student ID: 26339379
 *
 * @date 2023-01-26
 *
 */

#include <string>
#include <vector>
#include "Player.h"
// Modifications made by me
#include "LoggingObserver.h"
using std::string;

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine : public Subject, public ILoggable
{
public:
    // Modifications made by me
    void Notify(ILoggable *) override;
    std::string stringToLog() override;

    GameEngine();
    std::string command;
    std::vector<Player *> P;
    std::vector<Map *> M;
    Map *playingMap;

    enum GameCommands
    {
        LOADMAP,
        VALIDATEMAP,
        ADDPLAYER,
        GAMESTART,
        REPLAY,
        QUIT,
        ISSUEORDER,
        ENDISSUEORDERS,
        EXEORDER,
        ENDEXEORDERS,
        PLAY,
        TOURNAMENT
    };
    enum GameStates
    {
        START,
        MAPLOADED,
        MAPVALIDATED,
        PLAYERSADDED,
        ASSIGNREINFORCEMENT,
        WIN
    };
    void Run();
    void Play();
    void ExitProgram() { isRunning = false; }
    void Tournament(std::vector<Map *> &M, std::vector<Player *> &P, int G, int D);

    // Functions for [PLAY] of Game
    void assignReinforcement(std::vector<Player *> &P);
    void issueOrders(std::vector<Player *> &P);
    void executeOrders(std::vector<Player *> &P);
    void Win(std::vector<Player *> &P);

    ~GameEngine();

private:
    // Private Data Members
    int playerCounter;
    bool isRunning;

    void InvalidCommand();

    // Functions for [START] of Game
    void startUpPhase();
    void mapLoaded();
    void MapValidated(std::string &command);
    void playersAdded();
};

#endif /* GAMEENGINE_H */
