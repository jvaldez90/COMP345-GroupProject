#include "Player.h"
#include "PlayerStrategies.h"

int main()
{

    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");

    Territory *t1 = new Territory(1, "USA", 1, 2, 3);
    Territory *t2 = new Territory(2, "Mexico", 1, 7, 6);
    Territory *t3 = new Territory(3, "Canada", 1, 3, 5);
    Territory *t4 = new Territory(4, "France", 2, 76, 43);
    Territory *t5 = new Territory(5, "Germany", 2, 34, 22);
    Territory *t6 = new Territory(6, "Italy", 2, 78, 53);
    Territory *t7 = new Territory(7, "Japan", 3, 2, 34);
    Territory *t8 = new Territory(8, "China", 3, 55, 32);
    Territory *t9 = new Territory(9, "India", 3, 34, 34);

    // Add territories to players territories
    p1.getTerritories().push_back(t1);
    p1.getTerritories().push_back(t2);
    p1.getTerritories().push_back(t3);
    p2.getTerritories().push_back(t4);
    p2.getTerritories().push_back(t5);
    p2.getTerritories().push_back(t6);
    p3.getTerritories().push_back(t7);
    p3.getTerritories().push_back(t8);
    p3.getTerritories().push_back(t9);

    p1.setStrategy(new BenevolentPlayerStrategy());
    p2.setStrategy(new NeutralPlayerStrategy());
    p3.setStrategy(new CheaterPlayerStrategy());

    // Display the territories in the defend list
    std::cout << "Territories to defend:" << std::endl;
    for (Territory *territory : p1.getStrategy()->toDefend())
    {
        std::cout << territory->getName() << std::endl;
    }

    // Display the territories in the attack list
    std::cout << "Territories to attack:" << std::endl;
    for (Territory *territory : p1.getStrategy()->toAttack())
    {
        std::cout << territory->getName() << std::endl;
    }

    p1.issueOrder(p1.getStrategy());
    p2.issueOrder(p2.getStrategy());
    p3.issueOrder(p3.getStrategy());

    p1.setStrategy(new CheaterPlayerStrategy());

    // Display the territories in the defend list
    std::cout << "Territories to defend:" << std::endl;
    for (Territory *territory : p1.getStrategy()->toDefend())
    {
        std::cout << territory->getName() << std::endl;
    }

    // Display the territories in the attack list
    std::cout << "Territories to attack:" << std::endl;
    for (Territory *territory : p1.getStrategy()->toAttack())
    {
        std::cout << territory->getName() << std::endl;
    }

    p1.issueOrder(p1.getStrategy());

    return 0;
}
