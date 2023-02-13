#pragma once

#include <string>
#include <vector>

class Card
{
public:
    Card() : choice(new std::string)
    {
        cardTypes.push_back("bomb");
        cardTypes.push_back("reinforcement");
        cardTypes.push_back("blockade");
        cardTypes.push_back("airlift");
        cardTypes.push_back("diplomacy");
    }
    ~Card() { delete choice; }

    Card(const Card &card);

    std::vector<std::string> *getpointer();

    void initialType();

    void printVectorType();

    void setCardType(int i);

    std::string *getCardType();

private:
    std::vector<std::string> cardTypes;
    std::string *choice;
};

class Deck : public Card
{

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
    std::vector<Card *> deck;
    Card *pointerCard;
    Card *tempCard;
};

class Hand : public Deck
{

public:
    Hand();
    ~Hand();

    Hand(const Hand &hand);

    Hand &operator=(const Hand &hand);

    void setHand(Card *card);

    void printHand();

    void printPlayingCard();

    void play(Card *card, Deck *deck);

    void cardToDeck(Deck *deck);

    std::vector<Card *> *getHand();

    std::vector<Card *> *getPlayingCard();

    void removePlayingFromHand(Card *card);

    void deletePlayingCards();

private:
    std::vector<Card *> handCards;
    std::vector<Card *> playingCards;
};