#pragma once
#include "Player.h"

class PlayerStrategy
{
public:
    Player* p;
    virtual ~PlayerStrategy() {}
    virtual void issueOrder() = 0;
    virtual std::vector<Territory*> toAttack() = 0;
    virtual std::vector<Territory*> toDefend() = 0;
};

class HumanPlayerStrategy : public PlayerStrategy
{
public:
    // Returns a vector of territories the player plans to attack during their turn
    std::vector<Territory*> toAttack() override;

    // Returns a vector of territories the player plans to defend during their turn
    std::vector<Territory*> toDefend() override;

    // Issues orders for the current player based on their strategy
    void issueOrder() override;

private:
    // Helper function to prompt the human player to select a territory
    Territory* chooseTerritory(std::vector<Territory*>& territories);

    // Helper function to prompt the human player to enter the number of armies to deploy
    int deployment_prompt(Territory* territory);

    // Helper function to prompt the human player to enter the number of armies to advance
    int advance_prompt(Territory* source, Territory* destination);
};

class AggressivePlayerStrategy : public PlayerStrategy
{
public:
    // Returns a list of territories the player plans to attack
    std::vector<Territory*> toAttack() override;

    // Returns a list of territories the player plans to defend
    std::vector<Territory*> toDefend() override;

    // Issues orders for the current player based on their strategy
    void issueOrder() override;

private:

    // Helper function to find a player's strongest territory
    Territory* findStrongestTerritory();

    //Helper function to find the adjacent enemy territories
    Territory* findAdjacentEnemyTerritory(Territory* territory);
};


class BenevolentPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder() override;
    std::vector<Territory*> toAttack() override;
    std::vector<Territory*> toDefend() override;
};

class NeutralPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder() override;
    std::vector<Territory*> toAttack() override;
    std::vector<Territory*> toDefend() override;
};

class CheaterPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder() override;
    std::vector<Territory*> toAttack() override;
    std::vector<Territory*> toDefend() override;
};