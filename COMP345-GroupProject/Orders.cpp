#include <iostream>
#include <vector>
#include <string>
#include "Orders.h"

using namespace std;

//Order class implementation

//Default constructor
Order::Order() {
    this->description = nullptr;
    this->effect = nullptr;
    this->player = nullptr;
};

//Constructor to initialize an order with its description and effect
Order::Order(const string& description, const string& effect) {
    this->description = new string(description);
    this->effect = new string(effect);
    this->player = nullptr;
};

//Parameterized constructor which initializes an Order with the provided description, effect and player who is giving the order
Order::Order(const string& description, const string& effect, Player& player) {
    this->description = new string(description);
    this->effect = new string(effect);
    this->player = &player;
}

//Copy constructor
Order::Order(const Order& order) {
    this->description = new string(*(order.description));
    this->effect = new string(*(order.effect));
    this->player = order.getPlayer();
}

//Destructor
Order::~Order() {
    delete description;
    delete effect;
    delete player;
}

//Getters and setters for attributes
string* Order::getDescription() const {
    return this->description;
}

string* Order::getEffect() const {
    return this->effect;
}

Player* Order::getPlayer() const {
    return this->player;
}

void Order::setDescription(const string& description) {
    delete this->description;
    this->description = new string(description);
}

void Order::setEffect(const string& effect) {
    delete this->effect;
    this->effect = new string(effect);
}

void Order::setPlayer(Player& player) {
    this->player = &player;
}

//Defining the assignment operator
Order& Order::operator=(const Order& order) {
    if (this != &order) {
        delete this->description;
        delete this->effect;
        this->description = new string(*(order.description));
        this->effect = new string(*(order.effect));
        this->player = order.getPlayer();
    }
    return *this;
}

//Defining the output operator
ostream& operator<<(ostream& strm, const Order& order) {
    strm << *(order.description);
    return strm;
}



//DEPLOY CLASS IMPLEMENTATION

//Default constructor
Deploy::Deploy() : Order("This is a deploy order", "Armies are moved to a target") {
    this->target = nullptr;
    this->armies = 0;
}

//Parameterized Constructor
Deploy::Deploy(Player& player, int& armies, Territory& target) {
    setPlayer(player);
    this->target = &target;
    this->armies = armies;
}

//Copy constructor
Deploy::Deploy(const Deploy& deploy) : Order(deploy) {
    this->target = deploy.target;
    this->armies = deploy.armies;
}

//Destructor
Deploy::~Deploy() {
    delete target;
}

//Checks if a Deploy order is valid
bool Deploy::validate() {
    cout << "Validating Deploy Order..." << endl;
    if (this->target->getTerritoryOwner() == this->getPlayer()) {
        cout << "Order validated" << endl;
        return true;
    }
    else {
        cout << "Invalid Order: target does not belong to player" << endl;
        return false;
    }
}

//Executes a Deploy order
bool Deploy::execute() {
    cout << "Deploy::execute()...." << endl;
    if (this->validate()==true) {
        cout << "Executing Deploy Order..." << endl;
        //If order is validated, armies are added to the target territory
        this->target->addArmies(this->armies);
        cout << *this->getEffect() << endl;
        notify();
    }
    else {
        return false;
    }

}

//Defining the assignment operator
Deploy& Deploy::operator=(const Deploy& deploy) {
    Order::operator=(deploy);
    this->target = deploy.target;
    this->armies = deploy.armies;
    return *this;
}

//Defining the output operator
ostream& operator<<(ostream& strm, const Deploy& deploy) {
    strm << *deploy.getDescription();
    return strm;
}

// ADVANCE CLASS IMPLEMENTATION 

//Default constructor
Advance::Advance() : Order("This is an advance order", "Number of armies are moved from source to target") {
    this->source = nullptr;
    this->target = nullptr;
    this->armies = 0;
}

//Parameterized Constructor
Advance::Advance(Player& player, int& armies, Territory& source, Territory& target) : Advance() {
    setPlayer(player);
    this->source = &source;
    this->target = &target;
    this->armies = armies;
}

//Copy constructor
Advance::Advance(const Advance& advance) : Order(advance) {
    this->source = advance.source;
    this->target = advance.target;
    this->armies = advance.armies;
}

//Destructor
Advance::~Advance() {
    this->source = nullptr;
    this->target = nullptr;
};

//Checks if an Advance order is valid
//MISSING PROPER IMPLEMENTATION FOR VALIDATE AND EXECUTE
bool Advance::validate() {
    cout << "Validating Advance Order..." << endl;
    //Verify if source territory belongs to player issuing orders
    if (this->source->getTerritoryOwner() != this->getPlayer()) {
        cout << "Invalid order: source does not belong to player" << endl;
        return false;
    }
    // Verifying if source is adjacent to target
	for (Territory* adjacent_territory : this->target->get_neighbour_territory()) {
		if (this->source == adjacent_territory) {
			cout << "Order validated";
			return true;
		}
	}
	cout << "Invalid order : Target is not adjacent" << endl;
	return false;
    
}


//Executes an Advance order
bool Advance::execute() {
    cout << "Advance::execute()...." << endl;
    if (this->validate() == true) {
        cout << "Executing Advance Order..." << endl;
        notify();
        //Verify if both target and source belong to issuing player
        if (this->source->getTerritoryOwner() == this->getPlayer() && this->target->getTerritoryOwner() == this->getPlayer()) {
            cout << "Both territories belong to player issuing orders" << endl;
            this->target->addArmies(armies); //Add armies to target territory
            this->source->deleteArmies(armies); //Retrieve armies from source territory
            this->setEffect("army units are moved from the source to the target territory.");
            cout << *this->getEffect() << endl;
        }
        // Still have to implement actual attack mechanism when territories are not owned by same player
        else {

            int attack_armies = this->armies;
            int defend_armies = target->getNumberOfArmies();
            this->source->deleteArmies(attack_armies);
            //cout << "Advance::execute() BEFORE BATTLE | Attacking armies: " << attackingArmies << " | Defending armies: " << defendingArmies << endl;
            for (int i = 0; i < attack_armies; i++) {
                /* For each army, generate a random value up to 100, if 60 of those values are <= 60,
                then we have 60% probability */
                int chanceOfAttack = rand() % 100 + 1;
                //If possibility is 60%, attack is successful, defending army is killed
                if (chanceOfAttack <= 60) {
                    if (defend_armies == 0) {
                        break;
                    }
                    defend_armies--;
                }
            }
            //Same logic here, with 70% probability that defense is successful
            for (int i = 0; i < defend_armies; i++) {
                int chanceOfDefence = rand() % 100 + 1;
                if (chanceOfDefence <= 70) {
                    if (attack_armies == 0) {
                        break;
                    }
                    attack_armies--;
                }
            }
        }

    }
   
}

//Defining the assignment operator
Advance& Advance::operator=(const Advance& advance) {
    Order::operator=(advance);
    this->source = advance.source;
    this->target = advance.target;
    this->armies = advance.armies;
    return *this;
}

//Defining the output operator
ostream& operator<<(ostream& out, const Advance& advance) {
    out << *advance.getDescription();
    return out;
}

string Advance::stringToLog() const {
    return "Advance order has been called";
}


// BLOCKADE CLASS IMPLEMENTATION 

//Default constructor
Blockade::Blockade() : Order("This is a blockade order", "Number of armies are multiplied in a target territory") {
    this->target = nullptr;
}

//Parameterized Constructor
Blockade::Blockade(Player& player, Territory& target) : Blockade() {
    setPlayer(player);
    this->target = &target;
}

//Copy constructor
Blockade::Blockade(const Blockade& blockade) : Order(blockade) {
    this->target = blockade.target;
}

//Destructor
Blockade::~Blockade() {
    this->target = nullptr;
};

//Checks if a Blockade order is valid
bool Blockade::validate() {
    cout << "Validating Blockade Order..." << endl;
    if (this->target->getTerritoryOwner() == this->getPlayer()) {
        cout << "Order validated" << endl;
        return true;
    }
    else {
        cout << "Invalid Order: target does not belong to player" << endl;
        return false;
    }
}

//Executes a Blockade order
bool Blockade::execute() {
    cout << "Blockade::execute()...." << endl;
    notify();
    if (this->validate()) {
        cout << "Executing Blockade Order..." << endl;
        //Double the number of armies on target
        this->target->addArmies(this->target->getNumberOfArmies());
        this->getPlayer()->removeTerritory(*this->target);

        //Missing implementation for neutral player 
        return true;
    }
    else {
        return false;
    }
}

//Defining the assignment operator
Blockade& Blockade::operator=(const Blockade& blockade) {
    Order::operator=(blockade);
    this->target = blockade.target;
    return *this;
}

//Defining the output operator
ostream& operator<<(ostream& out, const Blockade& blockade) {
    out << *blockade.getDescription();
    return out;
}

string Blockade::stringToLog() const {
    return "Blockade order has been called";
}



// BOMB CLASS IMPLEMENTATION

//Default constructor
Bomb::Bomb() : Order("This is a bomb order", "Half of the armies removed from target.") {
    this->target = nullptr;
}

//Parameterized Constructor
Bomb::Bomb(Player& player, Territory& target) : Bomb() {
    setPlayer(player);
    this->target = &target;
}

//Copy constructor
Bomb::Bomb(const Bomb& bomb) : Order(bomb) {
    this->target = bomb.target;
}

//Destructor
Bomb::~Bomb() {
    this->target = nullptr;
};

//Checks if a Bomb order is valid
bool Bomb::validate() {
    cout << "Validating Bomb Order..." << endl;
    if (this->target->getTerritoryOwner() == this->getPlayer()) {
        cout << "Invalid order : The target already belongs to the player" << endl;
        return false;
    }
    else {
        for (Territory* adjacent_territory : this->target->get_neighbour_territory()) {
            if (adjacent_territory->getTerritoryOwner() == this->getPlayer()) {
                cout << "Order validated";
                return true;
            }
        }
        cout << "Invalid order : Target is not adjacent" << endl;
        return false;
    }
}

//Executes a Bomb order
bool Bomb::execute() {
    cout << "Blockade::execute()...." << endl;
    notify();
    this->target->setNumberOfArmies(this->target->getNumberOfArmies() / 2);
    this->setEffect("Half of the armies have been removed from the target!");
    cout << *this->getEffect() << endl;

}

//Defining the assignment operator
Bomb& Bomb::operator=(const Bomb& bomb) {
    Order::operator=(bomb);
    this->target = bomb.target;
    return *this;
}

//Defining the output operator
ostream& operator<<(ostream& out, const Bomb& bomb) {
    out << *bomb.getDescription();
    return out;
}

string Bomb::stringToLog() const {
    return "Bomb order has been called";
}


// AIRLIFT CLASS IMPLEMENTATION 

//Default constructor
Airlift::Airlift() : Order("This is an airlift order", "Armies moved from source to target") {
    this->source = nullptr;
    this->target = nullptr;
    this->armies = 0;
}

//Parameterized Constructor
Airlift::Airlift(Player& player, int& armies, Territory& source, Territory& target) : Airlift() {
    setPlayer(player);
    this->source = &source;
    this->target = &target;
    this->armies = armies;
}

//Copy constructor
Airlift::Airlift(const Airlift& airlift) : Order(airlift) {
    this->source = airlift.source;
    this->target = airlift.target;
    this->armies = airlift.armies;
}

//Destructor
Airlift::~Airlift() {
    this->source = nullptr;
    this->target = nullptr;
};

//Checks if an Airlift order is valid
bool Airlift::validate() {
    cout << "Validating Airlift Order..." << endl;
    if (this->source->getTerritoryOwner() != this->getPlayer()) {
        cout << "Invalid order : Source does not belong to player" << endl;
        return false;
    }
    else if (this->target->getTerritoryOwner() != this->getPlayer()) {
        cout << "Invalid order : Target does not belong to player" << endl;
        return false;
    }
    cout << "Order validated" << endl;
    return true;
}

//Executes an Airlift order
bool Airlift::execute() {
    cout << "Airlift::execute()..." << endl;
    notify();
    if (this->validate()) {
        cout << "Executing Airlift Order..." << endl;
        this->source->deleteArmies(armies);
        this->target->addArmies(armies);
        cout << *this->getEffect() << endl;
    }
}
//Defining the assignment operator
Airlift& Airlift::operator=(const Airlift& airlift) {
    Order::operator=(airlift);
    this->source = airlift.source;
    this->target = airlift.target;
    this->armies = airlift.armies;
    return *this;
}

//Defining the output operator
ostream& operator<<(ostream& strm, const Airlift& airlift) {
    strm << *airlift.getDescription();
    return strm;
}

string Airlift::stringToLog() const {
    return "Airlift order has been called";
}


// NEGOTIATE CLASS IMPLEMENTATION

//Default constructor
Negotiate::Negotiate() : Order("This is a negotiate order", "Players are prohibited from attacking each other during this turn") {
    this->enemy = nullptr;
}

//Parameterized Constructor
Negotiate::Negotiate(Player& player, Player& enemy) : Negotiate() {
    setPlayer(player);
    this->enemy = &enemy;
}

//Copy constructor
Negotiate::Negotiate(const Negotiate& negotiate) : Order(negotiate) {
    this->enemy = negotiate.enemy;
}

//Destructor
Negotiate::~Negotiate() {
    this->enemy = nullptr;
};

//Checks if a Negotiate order is valid
bool Negotiate::validate() {
    cout << "Negotiate::execute()..." << endl;
    notify();
    if (this->enemy == this->getPlayer()) {
        cout << "Invalid order : Target is the player issuing the order" << endl;
        return false;
    }
    return true;
}

//Executes a Negotiate order
bool Negotiate::execute() {
    cout << "Negotiate::execute()..." << endl;
    //Temporary implementation, still have to code the behavior to label the attacks as invalid
    if (this->validate() == true) {
        cout << "For the remainder of the turn, any attack between " << this->getPlayer()->getName() << " and " << this->enemy->getName() << " will be invalid" << endl;
    }
}

//Defining the assignment operator
Negotiate& Negotiate::operator=(const Negotiate& negotiate) {
    Order::operator=(negotiate);
    this->enemy = negotiate.enemy;
    return *this;
}

//Defining the output operator
ostream& operator<<(ostream& strm, const Negotiate& negotiate) {
    strm << *negotiate.getDescription();
    return strm;
}

string Negotiate::stringToLog() const {
    return "Negotiate order has been called";
}

//ORDERS LIST CLASS IMPLEMENTATION

//Default constructor
OrderList::OrderList() {
    this->orders = new vector<Order*>();
}

//Copy constructor
OrderList::OrderList(const OrderList& orders_list) : OrderList() {
    for (int i = 0; i < orders_list.getOrderList()->size(); i++) {
        Order* order = orders_list.orders->at(i);
        this->add(order);
    }
}

//Destructor
OrderList::~OrderList() {
    //deallocate each individual order
    for (Order* order : *this->orders) {
        delete order;
    }
    //Deallocate the pointer to the list itself
    delete this->orders;
    //Set the pointer to the list to null to avoid wild pointers 
    this->orders = nullptr;
}

//Move an Order in the vector to a new index by providing its current index and the index it should be moved to
void OrderList::move(int startPosition, int endPosition) {
    //Making sure the indexes fit within the range of the list
    if (startPosition < this->orders->size() && endPosition < this->orders->size() && startPosition >= 0 && endPosition >= 0) {
        //Get the element to be moved
        Order* order_to_move = this->orders->at(startPosition);
        //Remove order from the start index and insert it at the wanted index
        this->orders->erase(this->orders->begin() + startPosition);
        this->orders->insert(this->orders->begin() + endPosition, order_to_move);
    }
    else {
        cout << "The index inputed is invalid, please try again" << endl;
    }
}

//Deletes an order from the list at an index 
void OrderList::remove(const int index_removed) {
    //Verify if index given is within range of the list
    if (index_removed >= 0 && index_removed < this->orders->size()) {
        //Deallocating the pointer to the object
        delete this->orders->at(index_removed);
        //Delete the object itself
        this->orders->erase(this->orders->begin() + index_removed);
    }
    else {
        //Index is not within range
        cout << "Your index is invalid, please try again" << endl;
    }
}

//Getter for the vector of orders
vector<Order*>* OrderList::getOrderList() const {
    return this->orders;
}

//Add an order to the vector by providing an Order
void OrderList::add(Order* order) {
    this->orders->push_back(order);
    notify();
}

OrderList& OrderList::operator=(const OrderList& list) {
    if (this != &list) {
        //remove orders from LHS
        for (int pos = 0; pos < this->orders->size(); pos++) {
            this->remove(pos);
        }
        //add all orders from RHS to LHS
        for (int i = 0; i < list.getOrderList()->size(); i++) {
            Order* o = list.orders->at(i);
            this->add(o);
        }
    }
    return *this;
}

// Defining the output operator
ostream & operator<<(ostream & strm, const OrderList& list) {
    for (Order* order : *(list.orders)) {
        strm << *order << endl;
    }
    return strm;
}

// Method Override from 
string OrderList::stringToLog() const {
    vector<Order*>::iterator it = orders->end() - 1;
    return "Order has been added to the order list with the following effect: " + *(*it)->getEffect() + ". " + *(*it)->getDescription();;
}

