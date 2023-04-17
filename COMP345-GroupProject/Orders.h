#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Map.h"
#include "Player.h"
#include "LoggingObserver.h"

using namespace std;

//Forward declaration
class Player;
class Territory;

class Order : public Subject, public ILoggable {

private:

    string* description; //pointer to a string containing the order description
    string* effect; //pointer to a string containing the order's effect
    Player* player; //pointer to the player issuing the order

public:

    //Default constructor to initialize order.
    Order();

    //Constructor to initialize an order with its description and effect
    Order(const string& description, const string& effect);

    //A parameterized constructor which initializes an order with the provided description, effect and issuing player
    Order(const string& description, const string& effect, Player& player);


    //Copy constructor
    Order(const Order& order);

    //Destructor to avoid memory leaks
    virtual ~Order();

    //Getter for the description of the order
    virtual string* getDescription() const ;

    //Getter for the effect of the order
    virtual string* getEffect() const ;

    //Getter for the player issuing the order
    virtual Player* getPlayer() const ;

    //Setter for the description of the order
    virtual void setDescription(const string& description);

    //Setter for the effect of the order
    virtual void setEffect(const string& effect);

    //Setter for the player issuing the order
    virtual void setPlayer(Player& player);

    //Validate method to check if order if valid
    virtual bool validate()=0;

    //Execute method to execute valid orders
    virtual bool execute()=0;

    //Assignment operator definition
    Order& operator=(const Order& order);

    // Operator << definition 
    friend ostream& operator<<(ostream& strm, const Order& order);

};

class Deploy : public Order {

private:

    Territory* target;
    int armies;

public:

    //Default constructor for Deploy order object
    Deploy();

    /*Parameterized constructor for deploy order containing information on player calling deploy order, its target
    and the number of armies deployed */
    Deploy(Player& player, int& armies, Territory& target);

    //Destructor
    ~Deploy();

    //Copy constructor
    Deploy(const Deploy& deploy);

    //validate method override from base class
    bool validate() override;

    //execute method from base class
    bool execute() override;

    //Assignment operator definition
    Deploy& operator=(const Deploy& deploy);

    //Operator << definition
    friend ostream& operator<<(std::ostream& strm, const Deploy& deploy);

    // Override stringToLog class from Order
    string stringToLog() const override;

};

class Advance : public Order {

private:
    Territory* source;
    Territory* target;
    int armies;

public:
    //Default constructor for Deploy order object
    Advance();

    //Destructor
    ~Advance();

    //Copy constructor
    Advance(const Advance& advance);

    /*Parameterized constructor for advance order containing information on player
    giving the order, the territory from which the order comes from, and the target territory*/
    Advance(Player& player, int armies, Territory& source, Territory& target);

    //validate method override from base class
    bool validate() override;

    //execute method from base class
    bool execute() override;

    //Assignment operator definition
    Advance& operator=(const Advance& advance);

    //Operator << definition
    friend ostream& operator<<(std::ostream& strm, const Advance& advance);

    // Override stringToLog class from Order
    string stringToLog() const override;

};

class Blockade : public Order {

private:
    Territory* target;

public:
    //Default constructor
    Blockade();

    //Parameterized Constructor containing information on player calling the blockade and its target
    Blockade(Player& player, Territory& target);

    //Copy constructor
    Blockade(const Blockade& blockade);

    //Destructor
    ~Blockade();

    //Override validate method from base class
    bool validate() override;

    //Override execute method from base class
    bool execute() override;

    //Defining the output operator
    friend ostream& operator<<(ostream& strm, const Blockade& blockade);

    //Defining the assignment operator
    Blockade& operator=(const Blockade& blockade);

    // Override stringToLog class from Order
    string stringToLog() const override;
};

class Airlift : public Order {

private:
    Territory* source;
    Territory* target;
    int armies;

public:
    //Default constructor
    Airlift();

    //Parameterized Constructor
    Airlift(Player& player, int armies, Territory& source, Territory& target);

    //Copy constructor
    Airlift(const Airlift& airlift);

    //Destructor
    ~Airlift();

    //Checks if a Bomb order is valid
    bool validate() override;

    //Executes a Bomb order
    bool execute() override;

    //Defining the output operator
    friend ostream& operator<<(ostream& strm, const Airlift& airlift);

    //Defining the assignment operator
    Airlift& operator=(const Airlift& airlift);

    // Override stringToLog class from Order
    string stringToLog() const override;
};

class Bomb : public Order {

private:
    Territory* target;

public:
    //Default constructor
    Bomb();

    //Parameterized Constructor
    Bomb(Player& player, Territory& target);

    //Copy constructor
    Bomb(const Bomb& bomb);

    //Destructor
    ~Bomb();

    //Checks if a Bomb order is valid
    bool validate() override;

    //Executes a Bomb order
    bool execute() override;

    //Defining the output operator
    friend ostream& operator<<(ostream& strm, const Bomb& bomb);

    //Defining the assignment operator
    Bomb& operator=(const Bomb& bomb);

    // Override stringToLog class from Order
    string stringToLog() const override;

};

class Negotiate : public Order {

private:
    Player* enemy;

public:
    //Default constructor
    Negotiate();

    //Parameterized Constructor
    Negotiate(Player& player, Player& enemy);

    //Copy constructor
    Negotiate(const Negotiate& negotiate);

    //Destructor
    ~Negotiate();

    //Checks if a Bomb order is valid
    bool validate() override;

    //Executes a Bomb order
    bool execute() override;

    //Defining the output operator
    friend ostream& operator<<(ostream& strm, const Negotiate& negociate);

    //Defining the assignment operator
    Negotiate& operator=(const Negotiate& negociate);

    // Override stringToLog class from Order
    string stringToLog() const override;

};

class OrderList : public Subject, public ILoggable {

private:
    vector<Order*>* orders;

public:
    //Constructor for the orders list
    OrderList();

    //Copy constructor
    OrderList(const OrderList& orders);

    //Destructor for the orders list
    ~OrderList();

    //Move function to move order in the list of orders
    void move(int startPosition, int EndPosition);

    //Remove function to delete an order from the list
    void remove(int position);

    //Getter for orders list
    vector<Order*>* getOrderList() const;

    //Defining the assignment operator
    OrderList& operator=(const OrderList& ordersList);

    //Defining the output operator
    friend ostream& operator<<(ostream& out, const OrderList& orderlist);

    //Method to add order to the orders list
    void add(Order* order);

    // Override from ILoggable
    string stringToLog() const override;
};


