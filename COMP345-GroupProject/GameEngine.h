/**
 * @file GameEngine.h
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
#include <string>
using std::string;

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
// Functions for STARTUP of Game
void start();
void mapLoader();
bool mapValidated();
int playersAdded(int addPlayer);

// Functions for PLAY of Game
void assignReinforcement(string assignCountries[]);
void executeOrder();
void issueOrder();
void win();


#endif /* GAMEENGINE_H */
