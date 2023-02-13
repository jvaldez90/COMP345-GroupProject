#include "Player.h"
#include <algorithm>
#include <iostream>

// Constructor
Player::Player(std::string playerName)
{
    this->playerName = playerName;
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

    std::cout << "A Player has been deleted." std::endl;
}

// divideTerritories method that randomizes the list of territories and assigns it to Defend and to Attack
void Player::divideTerritories()
{
    std::vector<Territory *> dividedTerritories = this->territories;
    std::random_shuffle(dividedTerritories.begin(), dividedTerritories.end());

    int half = dividedTerritories.size() / 2;

    toDefendList = std::vector<Territory *>(dividedTerritories.begin(), dividedTerritories.begin() + half);
    toAttackList = std::vector<Territory *>(dividedTerritories.begin() + half, dividedTerritories.end());
}

// ToDefend method
std::vector<Territory *> Player::toDefend()
{
    if (toDefendList.empty())
    {
        divideTerritories();
    }
    return toDefendList;
}

// ToAttack method
std::vector<Territory *> Player::toAttack()
{
    if (toAttackList.empty())
    {
        divideTerritories();
    }
    return toAttackList;
}

// IssueOrder method
void Player::issueOrder(std::string orderType)
{
    Order *newOrder = nullptr;
    if (orderType = "deploy")
    {
        newOrder = new Deploy();
    }
    else if (orderType = "advance")
    {
        newOrder = new Advance();
    }
    else if (orderType = "bomb")
    {
        newOrder = new Bomb();
    }
    else if (orderType = "blockade")
    {
        newOrder = new Blockade();
    }
    else if (orderType = "airlift")
    {
        newOrder = new Airlift();
    }
    else if (orderType = "neogtiate")
    {
        newOrder = new Negotiate();
    }
    else
    {
        std::cout << "Invalid order type, please try again." << std::endl;
    }

    this->OL->addOrder(newOrder);
}