#include "Card.h"
#include "Card.cpp"

int main() {
  Deck deck;
  Hand hand;
  for (int i = 0; i < 5; i++) {
    hand.addCard(deck.draw());
  }
  hand.playCards();
  return 0;
}