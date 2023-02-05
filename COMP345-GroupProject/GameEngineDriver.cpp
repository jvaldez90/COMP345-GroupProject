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
    start();
    mapLoader();
    mapValidated();
    playersAdded(2);

    //TESTING VARIABLES
    string countries[] = {"France", "England", "Amsterdam"};

    assignReinforcement(countries);
    executeOrder();
    issueOrder();
    win();

    return 0;
}