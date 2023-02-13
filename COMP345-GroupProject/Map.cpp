#include "Map.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/***
* Constructor of Territory class
* @param id Id of the territory
* @param name Name of the territory
* @param continentID ContinentId 
* @param x x-coordinate
* @param y y-coordinate
*/
Territory::Territory(int id, const string& name, int continentId, int x,int y)
    : id(id), name(name),continentId(continentId), numberOfArmies(0), x(x), y(y) {
}
/**
* Default constructor of Territory class
*/
Territory::Territory() {

}
/**
 * Copy constructor of territory class
 */
Territory::Territory(const Territory& territory) : id(territory.id), name(territory.name),continentId(territory.continentId),x(territory.x), y(territory.y) { 
   
    continentId = territory.continentId;
    adjacentTerritories = territory.adjacentTerritories;
    numberOfArmies = 0;
}
/**
* @return The territory's Id
*/
int Territory::getId() const {
    return this->id;
}

/**
* @return The continent's Id
*/
int Territory::getContinentId() const {
    return continentId;
}

/**
* @return Territory's name
*/
const string &Territory::getName() const {
    return name;
}
/**
* @param set the number of armies
*/
void Territory::setNumberOfArmies(int armies) { 
    numberOfArmies = armies;
}

/**
 * @return The number of armies
 */
int Territory::getNumberOfArmies() const {
    return numberOfArmies;
}
/**
* @return x-coordinate of the territory
*/
int Territory::getX() const {
    return x;
}
/**
* @return y-coordinate of the territory
*/
int Territory::getY() const {
    return y;
}
/**
 * @param Increase the number of armies
 */
void Territory::addArmies(int armies) {
    numberOfArmies += armies;
}

/**
 * @param Decrease the number of armies
 */
void Territory::deleteArmies(int armies) {
    numberOfArmies -= armies;
}

/**
 * @param Add an adjacent territory to the list of territories
 */
void Territory::addAdjacentTerritory(Territory* territory) {
    adjacentTerritories.emplace_back(territory); 

}
/**
* Assignment operator for territory
*/
Territory& Territory::operator=(const Territory& other) {
    id = other.id;
    name = other.name;
    continentId = other.continentId;
    x = other.x;
    y = other.y;
    return *this;
}


/**
 * Constructor of Continent class
 * @param id Id of the continent
 * @param name Name of the continent
 * @param color Color of the continent
 */
Continent::Continent(int id, const string& name, const string& color):id(id), name(name), color(color) {
    numberOfTerritories = 0;
}
    


/**
 * Copy constructor of the Continent class
 */
Continent::Continent(const Continent& continent) : id(continent.id),name(continent.name), color(continent.color){ 
    territories = continent.territories;
}
/**
* @return The continent's id
*/
int Continent::getId() const {
    return id;
}

/**
 * @return the name of the continent
 */
const string & Continent::getName() const {
    return name;
}

/**
 * @return the color of the continent
 */
const string & Continent::getColor() const {
    return color;
}

/**
 * @return the number of territories
 */
int Continent::getNumberOfTerritories() const {
    return numberOfTerritories;
}

/**
 * @return  vector of the territories
 */
const vector<Territory*>& Continent::getTerritories() const {
    return territories;
}

void Continent::addTerritory(Territory* territory) {
    territories.emplace_back(territory);
}

bool Continent::isEmpty() const {
    return territories.empty();
}

Continent& Continent::operator=(const Continent& other) {
    id = other.id;
    name = other.name;
    color = other.color;
    return *this;
}

Map::Map(string name) : name(name) {
}
/**
* Copy constructor for map
*/
Map::Map(const Map& map) : name(map.name) {
    continents = map.continents;
    territories = map.territories;
    
}
void Map::addTerritory(Territory* territory) {
    territories.emplace_back(territory);
}

void Map::addContinent(Continent* continent) {
    continents.emplace_back(continent);
}

Continent* Map::getContinentById(int continentId) {
    return continents[continentId-1];
}

Territory* Map::getTerritoryById(int territoryId) {
    return territories[territoryId - 1];
}
const string & Map::getName() const {
    return name;
}

Map& Map::operator=(const Map& other) {
    name = other.name;
    return *this;
}

void Map::validate(){

    for (const auto& continent : continents) {
        if (continent->isEmpty()) {
            cout << "Doesn't have any territories";
                break;
        }
    }
    cout << "The continent is not empty";
}

MapLoader::MapLoader() {};

Map* MapLoader::load(const string& filename) {
    
    Map* map = new Map(filename);
    ifstream file(filename);
    file.open("../" + filename);
    string endLine;
    while (std::getline(file, endLine)) {

        if (endLine.empty() || endLine.front() ==';') {
            continue;
        }
        cout << endLine<<endl;
    }
    file.close();
    return map;
}










