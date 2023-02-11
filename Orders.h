#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class Player;
//class Territory;

class Order {

    private :

    string* description; //pointer to a string containing the order description
    string* effect; //pointer to a string containing the order's effect
    Player* player; //pointer to the player issuing the order

    public :

    //Default constructor to initialize order.
    Order();

    //Constructor to initialize an order with its description and effect
    Order(string& description, string& effect, Player& player);

    //Destructor to avoid memory leaks
    ~Order();

    //Getter for the description of the order
    string* getDescription();

    //Getter for the effect of the order
    string* getEffect();

    //Getter for the player issuing the order
    Player* getPlayer();

    //Setter for the description of the order
    void setDescription(string& description);

    //Setter for the effect of the order
    void setEffect(string& effect);

    //Setter for the player issuing the order
    void setPlayer(Player& player);

    //Validate method to check if order if valid
    virtual bool validate();

    //Execute method to execute valid orders
    virtual bool execute();

    //Assignment operator definition
    Order& operator=(const Order &order);

    // Operator << definition 
    friend std::ostream& operator <<(std::ostream &strm, const Order &order);

};

class Deploy : public Order {

    private :

    //Territory* target;
    //int* armies;

    public :

    //Default constructor for Deploy order object
    Deploy(); 

    /*Parameterized constructor for deploy order containing information on player calling deploy order, its target
    and the number of armies deployed */
    //Deploy(Player& player, int& armies, Territory& target);

    //Destructor
    ~Deploy();

    //Copy constructor
    Deploy(const Deploy& deploy);

    //validate method override from base class
    bool validate() override;

    //execute method from base class
    bool execute() override;

    //Assignment operator definition
    Deploy& operator=(const Deploy &deploy);

    //Operator << definition
    friend std::ostream& operator<<(std::ostream &strm, const Deploy &deploy);

};

class Advance : public Order {

    private : 
    //Territory* source; 
    //Territory* target;
    //int* armies;

    public :
    //Default constructor for Deploy order object
    Advance(); 

    //Destructor
    ~Advance();

    //Copy constructor
    Advance(const Advance& advance);

    /*Parameterized constructor for advance order containing information on player 
    giving the order, the territory from which the order comes from, and the target territory*/
    //Advance(Player& player, int& armies, Territory& source, Territory& target);

    //validate method override from base class
    bool validate() override;

    //execute method from base class
    bool execute() override;

    //Assignment operator definition
    Advance& operator=(const Advance &advance);

    //Operator << definition
    friend std::ostream& operator<<(std::ostream &strm, const Advance& advance);

};

class Blockade : public Order {

    private:
    //Territory* target;

    public:
    //Default constructor
    Blockade();

    //Parameterized Constructor containing information on player calling the blockade and its target
    //Blockade(Player& player, Territory& target);

    //Copy constructor
    Blockade(const Blockade& blockade);

    //Destructor
    ~Blockade();

    //Override validate method from base class
    bool validate() override;

    //Override execute method from base class
    bool execute() override;

    //Defining the output operator
    friend ostream & operator<<(ostream &strm, const Blockade& blockade);

    //Defining the assignment operator
    Blockade& operator=(const Blockade& blockade);
};

class Airlift : public Order {

    private:
    //Territory* source;
    //Territory* target;
    //int* armies;

    public:
    //Default constructor
    Airlift();

    //Parameterized Constructor
    //Airlift(Player& player, int& armies, Territory& source, Territory& target);

    //Copy constructor
    Airlift(const Airlift& airlift);

    //Destructor
    ~Airlift();

    //Checks if a Bomb order is valid
    bool validate() override;

    //Executes a Bomb order
    bool execute() override;

    //Defining the output operator
    friend ostream & operator<<(ostream &strm, const Airlift& airlift);

    //Defining the assignment operator
    Airlift& operator=(const Airlift& airlift);
};

class Bomb : public Order {

    private:
    //Territory* source;
    //Territory* target;
    //int* armies;

    public:
    //Default constructor
    Bomb();

    //Parameterized Constructor
    //Bomb(Player& player, Territory& source, Territory& target);

    //Copy constructor
    Bomb(const Bomb& bomb);

    //Destructor
    ~Bomb();

    //Checks if a Bomb order is valid
    bool validate() override;

    //Executes a Bomb order
    bool execute() override;

    //Defining the output operator
    friend ostream & operator<<(ostream &strm, const Bomb& bomb);

    //Defining the assignment operator
    Bomb& operator=(const Bomb& bomb);

};

class Negociate : public Order {

    private:
    //Territory* source;
    //Territory* target;
    //int* armies;

    public:
    //Default constructor
    Negociate();

    //Parameterized Constructor
    //Negociate(Player& player, Territory& source, Territory& target);

    //Copy constructor
    Negociate(const Negociate& negociate);

    //Destructor
    ~Negociate();

    //Checks if a Bomb order is valid
    bool validate() override;

    //Executes a Bomb order
    bool execute() override;

    //Defining the output operator
    friend ostream & operator<<(ostream &strm, const Negociate& negociate);

    //Defining the assignment operator
    Negociate& operator=(const Negociate& negociate);

};

class OrderList{

    private : 
    list<Order*> orders;

    public : 
    //Constructor for the orders list
    OrderList();

    //Copy constructor
    OrderList(const OrderList& o_list);

    //Destructor for the orders list
    ~OrderList();

    //Move function to move order in the list of orders
    void move(int startPosition, int EndPosition);

    //Remove function to delete an order from the list
    void remove(int position);

    //Getter for orders list
    vector<Order*> getOrderList();

    //Add an order to the vector by providing an Order
    void addOrder(Order* order);

    //Defining the output operator
    friend ostream & operator<<(ostream& out, const OrderList& orderlist);

    //Defining the assignment operator
    OrderList& operator=(const OrderList& orderList);


};

