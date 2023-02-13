#pragma once
#include <vector>
#include "Map.h"
#include "Card.h"
#include "Orders.h"

class Player
{
private:
    OrderList *OL();
    std::vector<Territory *> territories;
    Hand *hand;
    std::string *playerName;

    // Divide territories method
    void divideTerritories();

public:
    // Constructor
    Player(std::string) {}

    // Destructor
    ~Player();

    // ToDefend and ToAttack methods
    std::vector<Territory *> toDefend();
    std::vector<Territory *> toAttack();

    // IssueOrder method
    void issueOrder(std::string);

    // Accessors
    std::string getName() const { return *name; }
    std::vector<Territory *> getTerritories() const { return territories; }
    OrderList *getOL() const { return OL; }
    Hand *getHand() const { return hand; }

    // Mutators
    void setName(const std::string &newName) { *name = newName; }
    void setTerritories(const std::vector<Territory *> &newTerritories) { territories = newTerritories; }
    void setOL(OrderList *newOL) { OL = newOL; }
    void setHand(Hand *newHand) { hand = newHand; }
};