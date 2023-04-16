#include "Player.h"
#include <algorithm>
#include <iostream>

Player::Player(std::string playerName)
{
    this->playerName = new std::string(playerName); // Allocate memory for playerName pointer
    this->hand = new Hand();
    OL = new OrderList();

    // Display of the confirmation that player has been created
    std::cout << "Player " << playerName << " has been created." << std::endl;
}

// Destructor
Player::~Player()
{
    delete hand;
    delete OL;

    std::cout << "A Player has been deleted." << std::endl;
}

// ToDefend method
std::vector<Territory *> Player::toDefend(PlayerStrategy *ps)
{
    return ps->toDefend();
}

// ToAttack method
std::vector<Territory *> Player::toAttack(PlayerStrategy *ps)
{
    return ps->toAttack();
}

// IssueOrder method
void Player::issueOrder(PlayerStrategy *ps)
{
    ps->issueOrder();
}
