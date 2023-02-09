#include "Card.h"
#include <iostream>

void Card::play() {
  std::cout << "Playing " << type_ << " card" << std::endl;
}

Deck::Deck() : generator_(std::random_device()()) {
  cards_.emplace_back("bomb");
  cards_.emplace_back("reinforcement");
  cards_.emplace_back("blockade");
  cards_.emplace_back("airlift");
  cards_.emplace_back("diplomacy");
}

Card Deck::draw() {
  std::uniform_int_distribution<> distribution(0, cards_.size() - 1);
  int index = distribution(generator_);
  Card card = cards_[index];
  cards_.erase(cards_.begin() + index);
  return card;
}

void Hand::playCards() {
  for (Card& card : cards_) {
    card.play();
  }
  cards_.clear();
}