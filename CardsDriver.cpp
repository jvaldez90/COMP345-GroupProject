#include <iostream>
#include "Cards.h"

int main() {
    Deck deck;
    Hand hand;
    for (int i = 0; i < 5; i++) {
        hand.draw(deck);
    }
    hand.play_all();
    return 0;
}
