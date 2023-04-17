#include "PlayerStrategies.h";
#include <algorithm>
#include <iostream>

// HumanPlayerStrategy methods implementation

#include <iostream>
// Method to choose a territory from the player's territory list
Territory* HumanPlayerStrategy :: chooseTerritory(std::vector<Territory*>& territories)
{
    std::cout << "Select a territory :\n";
    for (int i = 0; i < territories.size(); i++)
    {
        std::cout << i + 1 << ". " << territories[i]->getName() << " : " << territories[i]->getNumberOfArmies() << " armies\n";
    }
    //Read choice from user
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    // Checking for choice validity
    while (choice < 1 || choice > territories.size())
    {
        std::cout << "Invalid selection, please try again.\n";
        std::cin.ignore();
        std::cin >> choice;
    }

    return territories[choice - 1]; // return chosen territory at the right index
}

//Method that prompts the user for a number of armies to move to a territory
int HumanPlayerStrategy::deployment_prompt(Territory* territory)
{
    std::cout << "Enter the number of armies to deploy to " << territory->getName() << ":\n";

    int deployment; // number of armies player chooses to deploy
    int available_deploys = p->reinforcementPool; // number of available armies to be deployed
    std::cin >> deployment;
    //Clear the buffer to not read any leftover characters in the next prompt
    std::cin.ignore();


    //Error checking for value entered
    while (deployment < 1 || deployment > available_deploys)
    {
        std::cout << "Invalid deployment, please try again.\n";
        std::cin.ignore();
        std::cin >> deployment;
    }

    return deployment;
}
//Method that prompts the user for a number of armies to move from source to target
int HumanPlayerStrategy::advance_prompt(Territory* source, Territory* target)
{
    std::cout << "Enter the number of armies to move from " << source->getName() << " to " << target->getName() << ":\n";

    int armies;
    std::cin >> armies;
    std::cin.ignore();

    while (armies < 1 || armies > source->getNumberOfArmies())
    {
        std::cout << "Invalid number of armies, please try again.\n";
        std::cin.ignore();
        std::cin >> armies;
    }

    return armies;
}
// Access list of territories to attack
std::vector<Territory*> HumanPlayerStrategy::toAttack()
{
    return std::vector<Territory*>();
}
//Access list of territories to defend
std::vector<Territory*> HumanPlayerStrategy::toDefend()
{
    return std::vector<Territory*>();
}

void HumanPlayerStrategy::issueOrder()
{
    std::cout << "It's your turn, " << p->getName() << ".\n";

    // Prompt the player to select an action to perform
    std::cout << "Select an action to perform:\n";
    std::cout << "1. Deploy\n";
    std::cout << "2. Advance\n";
    std::cout << "3. Blockade\n";
    std::cout << "4. Bomb\n";
    std::cout << "5. Airlift\n";
    std::cout << "6. Negotiate\n";


    int selection;
    std::cin >> selection;
    std::cin.ignore();
    //Switch case that handles strategy behaviour depending on user choice
    switch (selection)
    {
    // In the case of choice 1, its a deploy order, the player deploys a number of armies from his pool to a territory of his choice
    case 1:
    {
        std::vector<Territory*> territories = p->getTerritories();
        Territory* territory_chosen = chooseTerritory(territories);
        int deployment = deployment_prompt(territory_chosen);

        // Deploy the reinforcement armies to the selected territory
        p->getOL()->add(new Deploy(*p, deployment, *territory_chosen));
        p->reinforcementPool -= deployment;
        break;
    }
    // Advance order, territories are chosen, prompt method is called to choose number of armies, Advance object is created
    case 2:
    {
        // Prompt the player to select a territory to advance armies from and a neighboring territory to advance armies to
        std::vector<Territory*> territories = p->getTerritories();
        Territory* selectedTerritory = chooseTerritory(territories);

        std::vector<Territory*> neighbors = selectedTerritory->get_neighbour_territory();
        Territory* selectedNeighbor = chooseTerritory(neighbors);

        int armiesToMove = advance_prompt(selectedTerritory, selectedNeighbor);

        // Advance armies from the selected territory to the selected neighbor territory
        p->getOL()->add(new Advance(*p, armiesToMove, *selectedTerritory, *selectedNeighbor));
        break;
    }

    // Blockade order, territory is chosen to double the armies on, Blockade object is created
    case 3:
    {
        // Prompt the player to select a territory to blockade
        std::vector<Territory*> territories = p->getTerritories();
        Territory* selectedTerritory = chooseTerritory(territories);

        p->getOL()->add(new Blockade(*p, *selectedTerritory));

    }

    // Bomb order, user and enemy territories are chosen, Bomb object is created
    case 4:
    {
         // Prompt the player to select a territory to bomb
         std::vector<Territory*> territories = p->getTerritories();
         Territory* selectedTerritory = chooseTerritory(territories);

         // Prompt the player to select an enemy territory adjacent to the selected territory
         std::vector<Territory*> neighbors = selectedTerritory->get_neighbour_territory();
         std::vector<Territory*> enemies;
         // Sort through the neighbour territories, those not owned by user are enemy territories and are added to list
         for (auto& neighbor : neighbors)
            {
              if (neighbor->getPlayer() != p)
               {
                 enemies.push_back(neighbor);
               }
            }
         Territory* selectedEnemyTerritory = chooseTerritory(enemies);
         p->getOL()->add(new Bomb(*p, *selectedEnemyTerritory));

    }

    // Airlift order, territories are chosen from user list, prompt method is used for chosen number of armies, Airlift object is created
    case 5 :
    {
        // Prompt the player to select a source territory to airlift armies from
        std::vector<Territory*> territories = p->getTerritories();
        Territory* sourceTerritory = chooseTerritory(territories);

        // Prompt the player to select a target territory to airlift armies to
        std::vector<Territory*> neighbors = sourceTerritory->get_neighbour_territory();
        Territory* targetTerritory = chooseTerritory(neighbors);

        //We can use advance_prompt here, since we are moving a number of armies from territory to territory
        int armiesToMove = advance_prompt(sourceTerritory, targetTerritory);
        p->getOL()->add(new Airlift(*p, armiesToMove ,*sourceTerritory,*targetTerritory));


    }
    case 6: 
    {
        //Not sure how to implemement Negotiate here, lack of time
    }
    // If choice is not valid, try again
    default : 
    {
        std::cout << "Invalid selection, please try again.\n";
        issueOrder();
        break;
    }

    }
}



// Aggressive player methods implementation
Territory* AggressivePlayerStrategy::findStrongestTerritory()
{
    Territory* strongestTerritory = nullptr;
    int maxArmies = 0;
    //Sort through territories and compare army quantity, set strongest territory accordingly
    for (auto& territory : p->getTerritories())
    {
        if (territory->getNumberOfArmies() > maxArmies)
        {
            maxArmies = territory->getNumberOfArmies();
            strongestTerritory = territory;
        }
    }

    return strongestTerritory;
}

// List of territories to attack
std::vector<Territory*> AggressivePlayerStrategy::toAttack()
{
    std::vector<Territory*> attackList;

    // Identify all attackable territories adjacent to the player's territories
    for (auto& territory : p->getTerritories())
    {
        //Loop through neighbour territories, if not owned by user and number of armies is lower, it is attackable
        for (auto& adjacentTerritory : territory->get_neighbour_territory())
        {
            if (adjacentTerritory->getPlayer() != p && adjacentTerritory->getNumberOfArmies() < territory->getNumberOfArmies())
            {
                attackList.push_back(adjacentTerritory);
            }
        }
    }

    return attackList;
}
// List of territories to defend
std::vector<Territory*> AggressivePlayerStrategy::toDefend()
{
    std::vector<Territory*> defendList = p->getTerritories();

    // Sort the territories by the number of armies, since we want the strongest territories to be attacked first
    std::sort(defendList.begin(), defendList.end(), [](Territory* a, Territory* b)
        { 
            return a->getNumberOfArmies() > b->getNumberOfArmies(); 
        });

    return defendList;
}

void AggressivePlayerStrategy::issueOrder()
{
        // Deploy armies to strongest territory
        Territory* strongestTerritory = findStrongestTerritory();
        // If territory exists and already has armies (at least 1), deploy all reinforcement armies there with a deploy order
        if (strongestTerritory != nullptr && p->reinforcementPool > 0)
        {
            p->getOL()->add(new Deploy(*p, p->reinforcementPool, *strongestTerritory));
            p->reinforcementPool = 0;
        }

        // Advance armies to attack enemy territories
        for (auto& territory : p->getTerritories())
        {
            // Choose territory and find adjacent enemy territories to attack,deploy advance order on it
            Territory* target = findAdjacentEnemyTerritory(territory);
            if (target != nullptr)
            {
                p->getOL()->add(new Advance(*p, territory->getNumberOfArmies() - 1, *territory, *target));
            }
        }
    }

    

// Benevolent player
void BenevolentPlayerStrategy::issueOrder()
{
    // Find the weakest territory
    Territory* weakestTerritory = nullptr;
    int minArmies = INT_MAX;

    for (auto& territory : p->getTerritories())
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
    Territory* strongestFriendly = nullptr;
    int maxArmies = -1;

    for (auto& adjacentTerritory : weakestTerritory->get_neighbour_territory())
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

std::vector<Territory*> BenevolentPlayerStrategy::toAttack()
{
    return std::vector<Territory*>();
}

std::vector<Territory*> BenevolentPlayerStrategy::toDefend()
{
    // Get a copy of the player's territories
    std::vector<Territory*> defendList = p->getTerritories();

    // Sort the territories by the number of armies, with the weakest territories first
    std::sort(defendList.begin(), defendList.end(), [](Territory* a, Territory* b)
        { return a->getNumberOfArmies() < b->getNumberOfArmies(); });

    return defendList;
}

void NeutralPlayerStrategy::issueOrder()
{
    std::cout << "No orders will be issued since player is Neutral." << std::endl;
}

std::vector<Territory*> NeutralPlayerStrategy::toAttack()
{
    return std::vector<Territory*>();
}

std::vector<Territory*> NeutralPlayerStrategy::toDefend()
{
    return p->getTerritories();
}

// Cheater player
void CheaterPlayerStrategy::issueOrder()
{
    // Conquer all adjacent enemy territories
    for (auto& territory : p->getTerritories())
    {
        for (auto& adjacentTerritory : territory->get_neighbour_territory())
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

std::vector<Territory*> CheaterPlayerStrategy::toAttack()
{
    std::vector<Territory*> attackableTerritories;

    // Iterate through all territories owned by the Cheater player
    for (auto& territory : p->getTerritories())
    {
        // Find all adjacent territories that are not owned by the Cheater player
        for (auto& adjacentTerritory : territory->get_neighbour_territory())
        {
            if (adjacentTerritory->getPlayer() != p)
            {
                attackableTerritories.push_back(adjacentTerritory);
            }
        }
    }

    return attackableTerritories;
}

std::vector<Territory*> CheaterPlayerStrategy::toDefend()
{
    // cheater will defend all his territories
    return p->getTerritories();
}