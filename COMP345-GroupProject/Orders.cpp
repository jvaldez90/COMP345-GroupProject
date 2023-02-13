#include <iostream>
#include <vector>
#include <string>
#include "Orders.h"

using namespace std;

//Order class implementation

//Default constructor
Order::Order(){
    this->description = nullptr;
    this->effect = nullptr;
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
}

//Destructor
Order::~Order(){
    delete description;
    delete effect;
    delete player;
}

//Getters and setters for attributes
string* Order::getDescription() const{
    return this->description;
}

string* Order::getEffect() const{
    return this->effect;
}

Player* Order::getPlayer() const{
    return this->player;
}

void Order::setDescription(string& description){
    delete this->description;
    this->description = new string(description);
}

void Order::setEffect(string& effect){
    delete this->effect; 
    this->effect = new string(effect);
}

void Order::setPlayer(Player& player){
    delete this->player;
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
	strm << order.description;
	return strm;
}

//DEPLOY CLASS IMPLEMENTATION

//Default constructor
Deploy::Deploy(): Order("This is a deploy order", "Armies are moved to a target") {
    this->target = nullptr;
    this->armies = 0;
}

//Parameterized Constructor
Deploy::Deploy(Player& player, int& armies, Territory& target){
    setPlayer(player);
    this->target = &target;
    this->armies = &armies;
}

//Copy constructor
Deploy::Deploy(const Deploy& deploy): Order(deploy) {
    this->target = deploy.target;
    this->armies = deploy.armies;
}

//Destructor
Deploy::~Deploy(){
    delete target;
    delete armies;
}

//Checks if a Deploy order is valid
bool Deploy::validate() {
    cout << "Validating Deploy Order..." << endl;
    if (this->getDescription()->compare("This is a deploy order")) {
        cout << "This is a valid order" << endl;
        return true;
    }
    else{
    return false;
    }
}

//Executes a Deploy order
bool Deploy::execute() {
    cout << "Deploy::execute()...."<< endl;
    if (this->validate()) {
        cout<<"Executing Deploy order..."<<endl;
        cout << this->getEffect() << endl;
        return true;
    }
    else{
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
Advance::Advance(): Order("This is an advance order", "Number of armies are moved from source to target") {
    this->source = nullptr;
    this->target = nullptr;
    this->armies = 0;
}

//Parameterized Constructor
Advance::Advance(Player& player, int& armies, Territory& source, Territory& target): Advance() {
    setPlayer(player);
    this->source = &source;
    this->target = &target;
    this->armies = &armies;
}

//Copy constructor
Advance::Advance(const Advance& advance): Order(advance) {
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
bool Advance::validate() {
    cout << "Validating Advance Order..." << endl;
    if (this->getDescription()->compare("This is an Advance order")) {
        cout << "This is a valid order" << endl;
        return true;
    }
    else{
    return false;
    }
}

//Executes an Advance order
bool Advance::execute() {
    cout << "Advance::execute()...." << endl;
    if (this->validate()) {
        cout << "Executing Advance Order..." << endl;
        cout<<this->getEffect()<<endl;
        return true;
    }
    else{
        return false;
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

// BLOCKADE CLASS IMPLEMENTATION 

//Default constructor
Blockade::Blockade(): Order("This is a blockade order", "Number of armies are multiplied in a target territory") {
    this->target = nullptr;
}

//Parameterized Constructor
Blockade::Blockade(Player& player,Territory& target): Blockade() {
    setPlayer(player);
    this->target = &target;
}

//Copy constructor
Blockade::Blockade(const Blockade& blockade): Order(blockade) {
    this->target = blockade.target;
}

//Destructor
Blockade::~Blockade() {
    this->target = nullptr;
};

//Checks if a Blockade order is valid
bool Blockade::validate() {
    cout << "Validating Blockade Order..." << endl;
    if (this->getDescription()->compare("This is a blockade order")) {
        cout << "This is a valid order" << endl;
        return true;
    }
    else{
    return false;
    }
}

//Executes a Blockade order
bool Blockade::execute() {
    cout << "Blockade::execute()...."<< endl;
    if (this->validate()) {
        cout << "Executing Blockade Order..." << endl;
        cout<<this->getEffect()<<endl;
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


// BOMB CLASS IMPLEMENTATION

//Default constructor
Bomb::Bomb(): Order("This is a bomb order", "Half of the armies removed from target.") {
    this->target = nullptr;
}

//Parameterized Constructor
Bomb::Bomb(Player& player, Territory& target): Bomb() {
    setPlayer(player);
    this->target = &target;
}

//Copy constructor
Bomb::Bomb(const Bomb& bomb): Order(bomb) {
    this->target = bomb.target;
}

//Destructor
Bomb::~Bomb() {
    this->target = nullptr;
};

//Checks if a Bomb order is valid
bool Bomb::validate() {
    cout << "Validating Bomb Order..." << endl;
    if (this->getDescription()->compare("This is a bomb order")) {
        cout << "This is a valid order" << endl;
        return true;
    }
    else{
    return false;
    }
}

//Executes a Bomb order
bool Bomb::execute() {
    cout << "Blockade::execute()...."<< endl;
    if (this->validate()) {
        cout << "Executing Bomb Order..." << endl;
        cout<<this->getEffect()<<endl;
        return true;
        
    }
    else{
        return false;
    } 
    
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

// AIRLIFT CLASS IMPLEMENTATION 

//Default constructor
Airlift::Airlift(): Order("This is an airlift order", "Armies moved from source to target") {
    this->source = nullptr;
    this->target = nullptr;
    this->armies = 0;
}

//Parameterized Constructor
Airlift::Airlift(Player& player, int& armies, Territory& source, Territory& target): Airlift() {
    setPlayer(player);
    this->source = &source;
    this->target = &target;
    this->armies = &armies;
}

//Copy constructor
Airlift::Airlift(const Airlift& airlift): Order(airlift) {
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
    if (this->getDescription()->compare("This is an airlift order")) {
        cout << "This is a valid order" << endl;
        return true;
    }
    else{
        return false;
    }
}

//Executes an Airlift order
bool Airlift::execute() {
    cout << "Airlift::execute()..."<< endl;
    if (this->validate()) {
        cout << "Executing Airlift Order..." << endl;
        cout << this->getEffect() << endl;
        return true;
      
    }
    else{
        return false;
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

// NEGOTIATE CLASS IMPLEMENTATION

//Default constructor
Negotiate::Negotiate(): Order("This is a negotiate order", "Players are prohibited from attacking each other during this turn") {
    this->enemy = nullptr;
}

//Parameterized Constructor
Negotiate::Negotiate(Player& player, Player& enemy) : Negotiate() {
    setPlayer(player);
    this->enemy = &enemy;
}

//Copy constructor
Negotiate::Negotiate(const Negotiate& negotiate): Order(negotiate) {
    this->enemy = negotiate.enemy;
}

//Destructor
Negotiate::~Negotiate() {
    this->enemy = nullptr;
};

//Checks if a Negotiate order is valid
bool Negotiate::validate() {
    cout << "Validating Negotiate Order..." << endl;
    if (this->getDescription()->compare("This is a negotiate order")) {
        cout << "This is a valid order" << endl;
        return true;
    }
    else{
    return false;
    }
}

//Executes a Negotiate order
bool Negotiate::execute() {
    cout << "Negotiate::execute()..."<< endl;
    if (this->validate()) {
        cout << "Executing Negotiate Order..." << endl;
        cout<<this->getEffect()<<endl;
        return true;
    }
    else{
        return false;
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

//ORDERS LIST CLASS IMPLEMENTATION

//Default constructor
OrderList::OrderList() {
    this->orders = new vector<Order*>();
}

//Copy constructor
OrderList::OrderList(const OrderList& orders_list): OrderList() {
    for (int i = 0; i < orders_list.getOrderList()->size(); i++) {
       Order* order = orders_list.orders->at(i);
       this->addOrder(order);
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
        //Get the element we want to move
        Order* order_to_move = this->orders->at(startPosition);
        //Remove order from the start index and insert it at the wanted index
        this->orders->erase(this->orders->begin() + startPosition);
        this->orders->insert(this->orders->begin() + endPosition,order_to_move);
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
    } else {
        //Index is not within range
        cout << "Your index is invalid, please try again" << endl;
    }
}

//Getter for the vector of orders
vector<Order*>* OrderList::getOrderList() const {
    return this->orders;
}

