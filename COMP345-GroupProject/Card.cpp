#include "Card.h"
#include <iostream>

using namespace std;

Card::Card(const Card & card) {
    this->cardTypes = *new std::vector<std::string>(card.cardTypes);
    this->choice = new std::string(*(card.choice));
}

void Card::initialType() 
{}

std::vector<std::string> *Card::getpointer() {
    return &cardTypes;
}

void Card::printVectorType() {
    cout << "The card types are: " <<endl;
    for (int i = 0; i < cardTypes.size(); i++) {
        cout << cardTypes.at(i) << endl;
    }
}

void Card::setCardType(int i) {
    choice = &cardTypes.at(i);
}

std::string *Card::getCardType() {
    return choice;
}

Deck::Deck()
{}

Deck::~Deck() {
    delete(pointerCard);
}

Deck::Deck(const Deck &deck) {

    this->deck = *new std::vector<Card*> (deck.deck);
    this->pointerCard = new Card(*(deck.pointerCard));
    this->tempCard = new Card(*(deck.tempCard));
}

Deck & Deck::operator=(const Deck &deck) {
    this->deck = *new std::vector<Card*>(deck.deck);
    this->pointerCard = new Card(*(deck.pointerCard));
    this->tempCard = new Card(*(deck.tempCard));
    return *this;
}

void Deck::initialDeck() {

    for (int i = 0; i < 30; i++) {
        pointerCard = new Card;
        if (i < 5) {
            pointerCard -> setCardType(0);
            deck.push_back(pointerCard);
        }
        if (i >= 5 && i < 10) {
			pointerCard->setCardType(1);
			deck.push_back(pointerCard);
		}
		if (i >= 10 && i < 15) {
			pointerCard->setCardType(2);
			deck.push_back(pointerCard);
		}
		if (i >= 15 && i < 20) {
			pointerCard->setCardType(3);
			deck.push_back(pointerCard);
		} 
        if (i >= 20 && i < 25) {
            pointerCard->setCardType(4);
			deck.push_back(pointerCard);
        }
    }
    cout << ("Deck is initialized\n") <<endl;
}

void Deck::printDeckSize() {
    cout << (" The deck currently contains ") << deck.size() << (" cards. \n") << endl;
}

Card* Deck::draw() {
    int temp = (rand() % deck.size());
    tempCard = deck.at(temp);

    deck.erase(deck.begin() + temp);

    return tempCard;
}

void Deck::addCard(Card *add_card) {
    deck.push_back(add_card);
}

Hand::Hand() 
{}

Hand::~Hand()
{}

Hand::Hand(const Hand &hand) {
    this->handCards = *new std::vector<Card*>(hand.handCards);
    this->playingCards = *new std::vector<Card*>(hand.playingCards);
}

Hand &Hand::operator=(const Hand &hand) {
    this->handCards = *new std::vector<Card*>(hand.handCards);
    this->playingCards = *new std::vector<Card*>(hand.playingCards);\
    return *this;
}

void Hand::setHand(Card *card) {
    handCards.push_back(card);
}

void Hand::printHand() {
    if (handCards.size() > 0) {
        cout << (" The Hand cards has ") << handCards.size() << (" cards ") << endl;
        for (int i = 0; i < handCards.size(); i++) {
            cout << "  # " << (i + 1) << " is " << *handCards.at(i)->getCardType() << endl;
        }
    } else {
		cout << (" the hand cards is empty \n") << endl;
	}
}

void Hand::printPlayingCard() {
    if (!playingCards.empty()) {
        cout << (" the play cards order is: ") << endl;
        for (int i = 0; i < playingCards.size(); i++) {
            cout << "  # " << i << " is " << *playingCards.at(i)->getCardType() << endl;
        }
    } else {
		cout << (" the hand cards is empty \n") << endl;
	}
}

void Hand::play(Card* card, Deck* deck) {
    playingCards.push_back(card);
    cardToDeck(deck);

    removePlayingFromHand(card);

    playingCards.pop_back();
}

void Hand::cardToDeck(Deck* deck) {
    for (int i = 0; i < playingCards.size(); i++) {
        deck->addCard(playingCards.at(i));
    }
}

std::vector<Card*>* Hand::getHand() {
    return &handCards;
}

std::vector<Card*>* Hand::getPlayingCard() {
    return &playingCards;
}

void Hand::removePlayingFromHand(Card* card) {
    for (int i = 0; i < handCards.size(); i++) {
        if (*handCards.at(i)->getCardType() == *card->getCardType()) {
            handCards.erase(handCards.begin() + i);
            cout << ("...deleting the card ") << *card->getCardType() << (" of the Hand cards...\n")<<  endl;
			return;
        }
    }
}

void Hand::deletePlayingCards() {
    playingCards.clear();
    cout<< "\n vec_play_cards are cleaned." <<endl;
}
