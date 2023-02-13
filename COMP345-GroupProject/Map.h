#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;


class Territory {
private:
    string name;
    int id;
    int x;
    int y;
    int continentId;
    int numberOfArmies;
    list<Territory*> adjacentTerritories;
public:
    Territory(int id, const string& name, int continentId, int x, int y);//Constructor
    Territory();//Default constructor
    Territory(const Territory& territory); // Copy constructor
    int getId() const;
    int getContinentId() const;
    int getNumberOfArmies() const;
    void addAdjacentTerritory(Territory* territory);
    void addArmies(int armies);
    void deleteArmies(int armies);
    void setNumberOfArmies(int armies);
    int getX() const;
    int getY() const;
    const string& getName() const;
    friend std::ostream& operator << (std::ostream& out, const Territory* territory);// Stream insertion operator
    Territory& operator=(const Territory & territory); // Assignment operator
};


class Continent {
private:
    int id;
    string name;
    string color;
    vector<Territory*> territories;
    int numberOfTerritories;
public:
    Continent(int id, const string& name, const string& color);// constructor
    Continent(const Continent& continent);//Copy constructor
    int getId() const;
    const string& getName() const;
    const string& getColor() const;
    int getNumberOfTerritories() const;
    void addTerritory(Territory* territory);
    bool isEmpty() const;
    const vector<Territory*>& getTerritories() const;
    friend std::ostream& operator << (std::ostream& out, const Continent* continent);// Stream insertion operator
    Continent& operator=(const Continent &continent);    // Assignment operator
    
};

class Map {
private:
    vector<Continent*> continents;
    vector<Territory*> territories;
    string name;
public:
    Map(string name);//Contructor
    Map(const Map& map); // Copy constructor
    void addTerritory(Territory* territory);
    void addContinent(Continent* continent);
    Territory* getTerritoryById(int TerritoryId);
    Continent* getContinentById(int continentId);
    void validate();
    const string& getName() const;
    friend std::ostream& operator<<(std::ostream& out, Map* map);// Stream insertion operator
    Map& operator=(const Map &map);// Assignment operator
};

class MapLoader {
public:
    Map*  load(const string &filename);
    MapLoader();
};
#pragma once
