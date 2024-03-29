#include "Map.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
class player;

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
    id = 0;
    name ="";
    continentId = 0;
    numberOfArmies = 0;
    x = 0;
    y = 0;
}
Territory::~Territory()
{
    delete player;
}
Territory::Territory(const string& name) :name(name)
{
    id = 0;
    continentId = 0;
    numberOfArmies = 0;
    x = 0;
    y = 0;
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
Player* Territory::getPlayer() {
    return player;
}

void Territory::setPlayer(Player* player)
{
    this->player = player;
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

vector<Territory*> Territory::get_neighbour_territory()
{
    return adjacentTerritories;
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

std::ostream& operator<<(std::ostream& out, const Territory* territory) {
    out << "Country Id: " << territory->getId() << " ";
    out << "Name: " << territory->getName() << " ";
    out << "Continent Id: " << territory->getContinentId() << " ";
    out << "X: " << territory->getX() << " ";
    out << "Y: " << territory->getY() << " ";
    return out;
}

/**
 * default constructor of Continent class
 * @param id Id of the continent
 * @param name Name of the continent
 * @param color Color of the continent
 */
Continent::Continent()
{
    id = 0;
    name = "";
    color = "";
    numberOfTerritories = 0;
}
Continent::~Continent()
{
    for (auto territory : territories) {
        delete territory;
    }
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
Continent::Continent(const string& name) :name(name)
{
    id = 0;
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
/**
* Stream insertion operator for continent
*/
std::ostream& operator<<(std::ostream& out, const Continent* continent) {
    out << "Id: " << continent->getId() << " ";
    out << "Continent: " << continent->getName()<< " ";
    out << "Color: " << continent->getColor() << " ";
    return out;
}

std::ostream& operator<<(std::ostream& out, Map* map)
{
    for (int i = 0; i < map->getContinents().size(); i++)
    {
        out << map->getContinents().at(i) << " ";
    }
    for (int i = 0; i < map->getTerritories().size(); i++)
    {
        out << map->getTerritories().at(i) << " ";
    }
    return out;
}

Map::Map()
{
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

void Map::removeTerritory(Territory* territory) {
    vector<Territory*>::iterator pos;
    for (int i = 0; i < territories.size() - 1; i++)
    {
        for (int j = i + 1; i < territories.size(); j++)
        {
            if (territories.at(i)->getId() == territories.at(j)->getId()) {
                pos = territories.begin() + j;
            }
        }
    }
    territories.erase(pos);
}

void Map::addContinent(Continent* continent) {
    continents.emplace_back(continent);
}

vector<Territory*> Map::getTerritories()
{
    return territories;
}

Continent* Map::getContinentById(int continentId) {
    return continents[continentId-1];
}

vector<Continent*> Map::getContinents() {

    return continents;
}
Territory* Map::getTerritoryById(int territoryId) {
    return territories[territoryId - 1];
}
Map::~Map()
{
    for (auto territory : territories) {
        delete territory;
    }
    for (auto continent : continents) {
        delete continent;
    }
}
const string & Map::getName() const {
    return name;
}
/**
* @ return 1 or 0 for uniqueness in territory
*/
bool Map::territory_is_unique()
{
    vector<int> ids;
    bool unique = true;
    for (int i = 0; i <continents.size(); i++)
    {
        Continent* temp = continents.at(i);

        for (int j = 0; j < (temp->getTerritories()).size(); j++)
        {
            Territory* terri = (temp->getTerritories().at(i));
            ids.push_back(terri->getId());
        }
    }
    
    for (int i = 0; i <ids.size()-1; i++)
    {
        for (int j = i+1; i <ids.size(); j++)
        {
            if (ids.at(i) == ids.at(j)) {
                return false;
            }
        }
    }
    return unique;
}
/**
* Depth first search algorithm for searching all vertices of a graph
*/
void Map::dfs(Territory* territory, bool visited[], int& number_of_visited_territories)
{
    //First territory is visited
    visited[territory->getId() - 1] = true;
    number_of_visited_territories++;
    for (Territory* neighbour : territory->get_neighbour_territory()) {
        //Neighbor has not been visited 
        if (!visited[neighbour->getId() - 1]) {
            dfs(neighbour, visited, number_of_visited_territories);
        }
    }
}

bool Map::map_connected_graph() {

    bool connected = false;
    const int number_of_territories = territories.size();
    bool* visited = new bool[number_of_territories] { false };
    Territory* visited_territory = territories[0];
    visited[visited_territory->getId() - 1] = true;
    int number_of_visited_territories = 1;
    dfs(visited_territory, visited, number_of_visited_territories);
    if (number_of_visited_territories == number_of_territories) {
        connected = true;
    }
    return connected;
}

bool Map::continents_is_connected_subgraph() {
    bool connected = false;
    const int number_of_territories = territories.size();
    bool* visited = new bool[number_of_territories] { false }; 
    int number_of_visited_territories = 0;
    for (int i = 0; i < continents.size(); i++)
    {
        Continent* temp = continents.at(i);

        for (int j = 0; j < (temp->getTerritories()).size(); j++)
        {
            dfs((temp->getTerritories()).at(j), visited, number_of_visited_territories);
            if (number_of_visited_territories == (temp->getTerritories()).size()) {
                connected = true;
            }
        }
    }
    return connected;
}
Map& Map::operator=(const Map& other) {
    name = other.name;
    return *this;
}

bool Map::validate(){

    if (map_connected_graph()) {
        std::cout << "The map is a connected graph." << std::endl;
    }
    else {
        throw std::invalid_argument("the map is not a connected graph.");
    }
    if (continents_is_connected_subgraph()) {
        std::cout << "Continents are connected subgraphs." << std::endl;
    }
    else {
        throw std::invalid_argument("Continents are not connected subgraphs.");
    }
    if (territory_is_unique()) {
        std::cout << "Each country belongs to one and only one continent." << std::endl;
    }
    else {
        throw std::invalid_argument("each country is not unique");
    }

    if (map_connected_graph() && continents_is_connected_subgraph() && territory_is_unique()){
        std::cout << "The map is valid" << std::endl;
        return true;
    }
    else {
        throw std::invalid_argument("The map is not valid");
        return false;
    }
}
MapLoader::MapLoader() {
    this->map = new Map();
};

void MapLoader::parseContinent(const string& filename) {
    ifstream file(filename);
    file.open("../" + filename);
    int index = 0;
    string endLine;
    while (getline(file, endLine)) {
        if (endLine.find("[continents]") != string::npos) {
            break;
        }
    }
    while (getline(file, endLine)) {
        if (endLine.empty()) {
            break;
        }
        index++;
        stringstream ss(endLine);
        string name;
        string color;
        int x;
        ss >> name >> x >> color;
        map->addContinent(new Continent(index,name,color)); 
    }
    file.close();
}

void MapLoader::parseCountries(const string& filename) {
    ifstream file(filename);
    file.open("../" + filename);
    int idTerritory = 0;
    string endLine;
    while (getline(file, endLine)) {
        if (endLine.find("[countries]") != string::npos) {
            break;
        }
    }
    while (getline(file, endLine)) {
        
        if (endLine.empty()) {
            break;
        }
        idTerritory++;
        //system("PAUSE");
        stringstream ss(endLine);
        int iteration;
        string name;
        int idContinent, x, y;
        ss >> iteration>> name >> idContinent >> x >> y;
        map->addTerritory(new Territory(idTerritory,name, idContinent,x,y));
    }
    file.close();
}

void MapLoader::parseBorders(const string& filename) {
    ifstream file(filename);
    file.open("../" + filename);
    string endLine;
    string territoryId;
    string x;
    const char delimiter = ' ';
    vector<int>ids;
    while (getline(file, endLine)) {
        if (endLine.find("[borders]") != string::npos) {
            break;
        }
    }
    while (getline(file, endLine)) {

        if (endLine.empty()) {
            break;
        }
        stringstream ss(endLine);
        ss >> territoryId;
        size_t index= endLine.find(territoryId);
        if (index != string::npos)
            endLine.erase(index, territoryId.length());
       
        ids=split(endLine, " ");
        for ( int i = 0;  i <ids.size();  i++)
        {
            //To do  
        }
        //int idTerritory, idAdjacentTerritory;
        //stringstream ss(endLine);
        //std::cout << "line data: " + endLine << endl;
        /*ss >> idTerritory >> idAdjacentTerritory;
        while (ss >> idAdjacentTerritory) {
            map->getTerritoryById(idTerritory)->addAdjacentTerritory(map->getTerritoryById(idAdjacentTerritory));
            if (ss.peek() == delimiter) {
                ss.ignore();
            }
        }*/
    }
    file.close();
}
vector<int> MapLoader::split(string str, string delimiter) {

    string token;
    size_t pos;
    vector<int>adjancentIds;
    int id;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        
        token = str.substr(0, pos);
        if (token !="") {
            id = stoi(token);
            adjancentIds.emplace_back(id);
        }
        str.erase(0, pos + delimiter.length());
    }
    adjancentIds.emplace_back(stoi(str));
    return adjancentIds;
}

Map* MapLoader::load(const string& filename) {
    ifstream file(filename);
    file.open("../" + filename);
    parseContinent(filename);
    parseCountries(filename);
    parseBorders(filename);
    return map;
}


 







