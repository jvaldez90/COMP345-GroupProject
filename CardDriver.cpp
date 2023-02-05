#include "Card.h"

int main() {

    Deck deck;

    deck.initialDeck();

    Hand hand;

    deck.printDeckSize();

    cout << "Assigning 5 cards rasndomly into the hand deck\n" <<endl;

    for (int i = 0; i < 5; i++) {
        hand.setHand(deck.draw());
    }

    hand.printHand();
    deck.printDeckSize();

    cout<<(" test to play all Cards of the HandCards...then remove it from HandCards and put the cards into vec_deck_cards \n")<<endl;
	int hand_size = hand.getHand()->size();
	for (int k = 0; k < hand_size; k++) {
		hand.play(hand.getHand()->at(0), &deck);
	}//because the erase method of the vector will auto move the cards

	//print the vec_play_cards
	hand.printPlayingCard();
	//print the current hand cards
	hand.printHand();

	//test the size of current deck
	deck.printDeckSize();

}