#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

enum CardType { bomb, reinforcement, blockade, airlift, diplomacy };

class Card {
public:
    Card(CardType type) : type(type) {}

    void play() {
        std::cout << "Playing ";
        switch (type) {
        case bomb:
            std::cout << "bomb";
            break;
        case reinforcement:
            std::cout << "reinforcement";
            break;
        case blockade:
            std::cout << "blockade";
            break;
        case airlift:
            std::cout << "airlift";
            break;
        case diplomacy:
            std::cout << "diplomacy";
            break;
        }
        std::cout << " card." << std::endl;
    }

private:
    CardType type;
};

class Deck {
public:
    Deck() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cards.push_back(Card((CardType)j));
            }
        }
    }

    Card draw() {
        std::uniform_int_distribution<int> distribution(0, cards.size() - 1);
        int index = distribution(generator);
        Card drawn_card = cards[index];
        cards.erase(cards.begin() + index);
        return drawn_card;
    }

private:
    std::vector<Card> cards;
    std::mt19937 generator;
};

class Hand {
public:
    void draw(Deck &deck) {
        Card card = deck.draw();
        cards.push_back(card);
    }

    void play_all() {
        for (Card card : cards) {
            card.play();
        }
        cards.clear();
    }

private:
    std::vector<Card> cards;
};