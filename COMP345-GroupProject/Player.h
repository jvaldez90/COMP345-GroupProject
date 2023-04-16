#pragma once
#include <vector>
#include "Map.cpp"
#include "Card.cpp"
#include "Orders.cpp"
#include "PlayerStrategies.h" // Include PlayerStrategies.h

class Player
{
private:
    OrderList *OL;
    Hand *hand;
    std::string *playerName;
    std::vector<Territory *> toDefendList;
    std::vector<Territory *> toAttackList;
    

    // Divide territories method
    void divideTerritories();

    PlayerStrategy *strategy; // Add PlayerStrategy data member

public:
    int reinforcementPool;
    // Constructor
    Player(std::string playerName);

    // Destructor
    ~Player();

    // ToDefend and ToAttack methods
    std::vector<Territory *> territories;
    std::vector<Territory *> toDefend(PlayerStrategy *);
    std::vector<Territory *> toAttack(PlayerStrategy *);
    
    void setAggressive() { setStrategy(new AggressivePlayerStrategy()); }
    
    // IssueOrder method
    void issueOrder(PlayerStrategy *);

    // Accessors
    std::string getName() const { return *playerName; }
    std::vector<Territory *> getTerritories() const { return territories; }
    OrderList *getOL() const { return OL; }
    Hand *getHand() const { return hand; }
    PlayerStrategy *getStrategy() const { return strategy; } // Add accessor for PlayerStrategy

    // Mutators
    void setName(const std::string &newName) { *playerName = newName; }
    void setTerritories(const std::vector<Territory *> &newTerritories) { territories = newTerritories; }
    void setOL(OrderList *newOL) { OL = newOL; }
    void setHand(Hand *newHand) { hand = newHand; }
    void setStrategy(PlayerStrategy *newStrategy) { strategy = newStrategy; } // Add mutator for PlayerStrategy
    
};
