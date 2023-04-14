#pragma once
#include "Player.h"

class PlayerStrategy
{
public:
    virtual ~PlayerStrategy() {}
    virtual void issueOrder(Player *player, std::string orderType) = 0;
    virtual std::vector<Territory *> toAttack(Player *player) = 0;
    virtual std::vector<Territory *> toDefend(Player *player) = 0;
};

class HumanPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder(Player *player, std::string orderType) override;
    std::vector<Territory *> toAttack(Player *player) override;
    std::vector<Territory *> toDefend(Player *player) override;
};

class AggressivePlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder(Player *player, std::string orderType) override;
    std::vector<Territory *> toAttack(Player *player) override;
    std::vector<Territory *> toDefend(Player *player) override;
};

class BenevolentPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder(Player *player, std::string orderType) override;
    std::vector<Territory *> toAttack(Player *player) override;
    std::vector<Territory *> toDefend(Player *player) override;
};

class NeutralPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder(Player *player, std::string orderType) override;
    std::vector<Territory *> toAttack(Player *player) override;
    std::vector<Territory *> toDefend(Player *player) override;
};

class CheaterPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder(Player *player, std::string orderType) override;
    std::vector<Territory *> toAttack(Player *player) override;
    std::vector<Territory *> toDefend(Player *player) override;
};

