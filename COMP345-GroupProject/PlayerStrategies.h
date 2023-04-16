#pragma once
#include "Player.h"

class PlayerStrategy
{
public:
    Player *p;
    virtual ~PlayerStrategy() {}
    virtual void issueOrder() = 0;
    virtual std::vector<Territory *> toAttack() = 0;
    virtual std::vector<Territory *> toDefend() = 0;
};

class HumanPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder() override;
    std::vector<Territory *> toAttack() override;
    std::vector<Territory *> toDefend() override;
};

class AggressivePlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder() override;
    std::vector<Territory *> toAttack() override;
    std::vector<Territory *> toDefend() override;
};

class BenevolentPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder() override;
    std::vector<Territory *> toAttack() override;
    std::vector<Territory *> toDefend() override;
};

class NeutralPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder() override;
    std::vector<Territory *> toAttack() override;
    std::vector<Territory *> toDefend() override;
};

class CheaterPlayerStrategy : public PlayerStrategy
{
public:
    void issueOrder() override;
    std::vector<Territory *> toAttack() override;
    std::vector<Territory *> toDefend() override;
};
