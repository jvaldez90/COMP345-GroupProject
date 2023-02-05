#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm> 
#include <iostream>


using namespace std;

class Card {

    public:
        Card();
        ~Card();

        Card(const Card &card);

        void initialType();

        vector<string> *getpointer();

        void printVectorType();

        void setCardType(int i);

        string *getCardType();

    private:
        std::vector<std::string> cardTypes = {"bomb", "reinforcement", "blockade", "airlift", "diplomacy"};
        string *choice;
};


class Deck : public Card {

    public:
        Deck();
        ~Deck();

        Deck(const Deck &deck);

        Deck &operator=(const Deck &deck); 

        void initialDeck();

        void printDeck();

        void printDeckSize();

        Card *draw();

        void addCard(Card *add_card);

    private:
        vector<Card *> deck;
        Card *pointerCard;
        Card *tempCard;

};


class Hand : public Deck {

    public:
        Hand();
        ~Hand();

        Hand(const Hand *hand);

        Hand &operator = (const Hand &hand);

        void setHand(Card *card);

        void printHand();

        void printPlayingCard();

        void play(Card *card, Deck *deck);

        void cardToDeck(Deck *deck);

        vector<Card *> *getHand();

        vector<Card *> *getPlayingCard();

        void removePlayingFromHand(Card *card);

        void deletePlayingCards();

    private:
        vector<Card *> handCards;
        vector<Card *> playingCards;

};