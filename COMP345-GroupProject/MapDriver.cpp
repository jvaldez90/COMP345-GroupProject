#include  "Map.h"
using namespace std;

int main()
{
    
    MapLoader map;
    map.load("europass.map");
    cout << "This is map one.\n\nThis is map two.";
    map.load("bigeurope.map");
}
