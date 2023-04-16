#include "PlayerStrategies.h";

// Human Player
void HumanPlayerStrategy::issueOrder()
{
}

std::vector<Territory *> HumanPlayerStrategy::toAttack()
{
}

std::vector<Territory *> HumanPlayerStrategy::toDefend()
{
}

// Agressive player
void AggressivePlayerStrategy::issueOrder()
{
}

std::vector<Territory *> AggressivePlayerStrategy::toAttack()
{
}

std::vector<Territory *> AggressivePlayerStrategy::toDefend()
{
}

// Benevolent player
void BenevolentPlayerStrategy::issueOrder()
{
    // Find the weakest territory
    Territory *weakestTerritory = nullptr;
    int minArmies = INT_MAX;

    for (auto &territory : p->getTerritories())
    {
        if (territory->getNumberOfArmies() < minArmies)
        {
            minArmies = territory->getNumberOfArmies();
            weakestTerritory = territory;
        }
    }

    // Deploy reinforcement armies to the weakest territory
    if (weakestTerritory != nullptr)
    {
        int reinforcementArmies = p->reinforcementPool;
        p->getOL()->add(new Deploy(*p, reinforcementArmies, *weakestTerritory));
        p->reinforcementPool = 0;
    }

    // Find the strongest friendly territory adjacent to the weakest territory
    Territory *strongestFriendly = nullptr;
    int maxArmies = -1;

    for (auto &adjacentTerritory : weakestTerritory->get_neighbour_territory())
    {
        if (adjacentTerritory->getPlayer() == p && adjacentTerritory->getNumberOfArmies() > maxArmies)
        {
            maxArmies = adjacentTerritory->getNumberOfArmies();
            strongestFriendly = adjacentTerritory;
        }
    }

    // Advance armies from the strongest friendly territory to the weakest territory for protection
    if (strongestFriendly != nullptr)
    {
        int armiesToMove = max(1, strongestFriendly->getNumberOfArmies() / 2);
        p->getOL()->add(new Advance(*p, armiesToMove, *strongestFriendly, *weakestTerritory));
    }
}

std::vector<Territory *> BenevolentPlayerStrategy::toAttack()
{
    return std::vector<Territory *>();
}

std::vector<Territory *> BenevolentPlayerStrategy::toDefend()
{
    // Get a copy of the player's territories
    std::vector<Territory *> defendList = p->getTerritories();

    // Sort the territories by the number of armies, with the weakest territories first
    std::sort(defendList.begin(), defendList.end(), [](Territory *a, Territory *b)
              { return a->getNumberOfArmies() < b->getNumberOfArmies(); });

    return defendList;
}

void NeutralPlayerStrategy::issueOrder()
{
    std::cout << "No orders will be issued since player is Neutral." << std::endl;
}

std::vector<Territory *> NeutralPlayerStrategy::toAttack()
{
    return std::vector<Territory *>();
}

std::vector<Territory *> NeutralPlayerStrategy::toDefend()
{
    return p->getTerritories();
}

// Cheater player
void CheaterPlayerStrategy::issueOrder()
{
    // Conquer all adjacent enemy territories
    for (auto &territory : p->getTerritories())
    {
        for (auto &adjacentTerritory : territory->get_neighbour_territory())
        {
            if (adjacentTerritory->getPlayer() != p)
            {
                // Double the number of armies in the territory being attacked
                int newArmies = adjacentTerritory->getNumberOfArmies() * 2;
                p->getOL()->add(new Advance(*p, newArmies, *territory, *adjacentTerritory));

                // Change ownership of the conquered territory to the Cheater player
                adjacentTerritory->setPlayer(p);
            }
        }
    }
}

std::vector<Territory *> CheaterPlayerStrategy::toAttack()
{
    std::vector<Territory *> attackableTerritories;

    // Iterate through all territories owned by the Cheater player
    for (auto &territory : p->getTerritories())
    {
        // Find all adjacent territories that are not owned by the Cheater player
        for (auto &adjacentTerritory : territory->get_neighbour_territory())
        {
            if (adjacentTerritory->getPlayer() != p)
            {
                attackableTerritories.push_back(adjacentTerritory);
            }
        }
    }

    return attackableTerritories;
}

std::vector<Territory *> CheaterPlayerStrategy::toDefend()
{
    // cheater will defend all his territories
    return p->getTerritories();
}
