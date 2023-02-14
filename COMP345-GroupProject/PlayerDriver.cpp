#include "Player.cpp"

int main()
{
    // Create Player
    Player *p1 = new Player("John Doe");

    Territory *t1 = new Territory(1, "USA", 1, 2, 3);
    Territory *t2 = new Territory(2, "Mexico", 1, 7, 6);
    Territory *t3 = new Territory(3, "Canada", 1, 3, 5);
    Territory *t4 = new Territory(4, "France", 2, 76, 43);
    Territory *t5 = new Territory(5, "Germany", 2, 34, 22);
    Territory *t6 = new Territory(6, "Italy", 2, 78, 53);
    Territory *t7 = new Territory(7, "Japan", 3, 2, 34);
    Territory *t8 = new Territory(8, "China", 3, 55, 32);
    Territory *t9 = new Territory(9, "India", 3, 34, 34);
    Territory *t10 = new Territory(10, "Brazil", 4, 13, 2);

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

    std::cout << "Deleting player..." << std::endl;
    delete p1;
}
