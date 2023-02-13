#include "Player.cpp"
#include "Orders.cpp"
#include "Cards.cpp"
#include "Map.cpp"

int main()
{
    // Create Player
    Player *p1 = new Player("John Doe");

    Territory *t1 = new Territory("USA", "North America");
    Territory *t2 = new Territory("Mexico", "North America");
    Territory *t3 = new Territory("Canada", "North America");
    Territory *t4 = new Territory("France", "Europe");
    Territory *t5 = new Territory("Germany", "Europe");
    Territory *t6 = new Territory("Italy", "Europe");
    Territory *t7 = new Territory("Japan", "Asia");
    Territory *t8 = new Territory("China", "Asia");
    Territory *t9 = new Territory("India", "Asia");
    Territory *t10 = new Territory("Brazil", "South America");

    // Add territories to players territories
    p1->territories.push_back(t1);
    p1->territories.push_back(t2);
    p1->territories.push_back(t3);
    p1->territories.push_back(t4);
    p1->territories.push_back(t5);
    p1->territories.push_back(t6);
    p1->territories.push_back(t7);
    p1->territories.push_back(t8);
    p1->territories.push_back(t9);
    p1->territories.push_back(t10);

    // Call the toDefend and toAttack method and create respective lists
    std::vector<Territory *> defendList = p1->toDefend();
    std::vector<Territory *> attackList = p1->toAttack();

    // Display the territories in the defend list
    std::cout << "Territories to defend:" << std::endl;
    for (Territory *territory : defendList)
    {
        std::cout << territory->getName() << std::endl;
    }

    // Display the territories in the attack list
    std::cout << "Territories to attack:" << std::endl;
    for (Territory *territory : attackList)
    {
        std::cout << territory->getName() << std::endl;
    }

    // Issue order
    p1->issueOrder("deploy");
    p1->issueOrder("negotiate");
    p1->issueOrder("bomb");

    // Get the orders list from the player object
    std::vector<Order *> OL = player.getOL();

    // Display the orders list
    std::cout << "Orders List: " << std::endl;
    for (int i = 0; i < OL.size(); i++)
    {
        std::cout << i + 1 << ". " << OL[i]->getType() << std::endl;
    }
}