#pragma once
#include <vector>
#include "Map.cpp"
#include "Card.cpp"
#include "Orders.cpp"

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

public:
    // Constructor
    Player(std::string playerName);

    // Destructor
    ~Player();

    // ToDefend and ToAttack methods
    std::vector<Territory *> territories;
    std::vector<Territory *> toDefend();
    std::vector<Territory *> toAttack();

    // IssueOrder method
    void issueOrder(std::string);

    // Accessors
    std::string getName() const { return *playerName; }
    std::vector<Territory *> getTerritories() const { return territories; }
    OrderList *getOL() const { return OL; }
    Hand *getHand() const { return hand; }

    // Mutators
    void setName(const std::string &newName) { *playerName = newName; }
    void setTerritories(const std::vector<Territory *> &newTerritories) { territories = newTerritories; }
    void setOL(OrderList *newOL) { OL = newOL; }
    void setHand(Hand *newHand) { hand = newHand; }
};
