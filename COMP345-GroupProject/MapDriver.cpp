#include  "Map.h"
using namespace std;

int main()
{
    
    MapLoader map;
    Map *mapwarzone;
    mapwarzone=map.load("europass.map");
    for (int i = 0; i <mapwarzone->getContinents().size(); i++)
    {
        std::cout << mapwarzone->getContinents().at(i) << endl;
    }
    for (int i = 0; i < mapwarzone->getTerritories().size(); i++)
    {
        std::cout << mapwarzone->getTerritories().at(i) << endl;
    }
    //bool is_valide = mapwarzone->territory_is_unique();
    //std::cout << is_valide << endl;

    //map.load("bigeurope.map");
}
