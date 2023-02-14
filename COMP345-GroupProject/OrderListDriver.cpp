#include <iostream>
#include <vector>
#include <string>
#include "Orders.h"

using namespace std;

int main()
{
    cout << "Orders List Driver" << endl;

    OrderList* orders_list = new OrderList();
    Deploy* deploy = new Deploy();
    Advance* advance = new Advance();
    Blockade* blockade = new Blockade();
    Bomb* bomb = new Bomb();
    Airlift* airlift = new Airlift();
    Negotiate* negotiate = new Negotiate();

    //add orders
    cout << "Adding orders to the OrdersList..." << endl;
    orders_list->add(deploy);
    orders_list->add(advance);
    orders_list->add(blockade);
    orders_list->add(bomb);
    orders_list->add(airlift);
    orders_list->add(negotiate);
    cout << *orders_list << endl;

    //move orders
    orders_list->move(2, 3);
    cout << "Moving an order from start position 2 to end position 3" << endl;
    cout << *orders_list << endl;

    //remove orders
    orders_list->remove(2);
    cout << "Remove order at position 2" << endl;
    cout << *orders_list << endl;

    //validate orders
    cout << "Verify if order at position 4 is valid" << endl;
    if (orders_list->getOrderList()->at(4)->validate()) {
        cout << "The order is valid" << endl << endl;
    }

    //execute orders
    cout << "Execute order to position 5" << endl;
    orders_list->getOrderList()->at(5)->execute();

    return 0;

}