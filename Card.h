#pragma once
#include <vector>
#include <string>
#include <random>

class Card {
 public:
  explicit Card(const std::string& type) : type_(type) {}
  void play();
  const std::string& getType() const { return type_; }

 private:
  std::string type_;
};

class Deck {
 public:
  Deck();
  Card draw();
  int size() const { return cards_.size(); }

 private:
  std::vector<Card> cards_;
  std::mt19937 generator_;
};

class Hand {
 public:
  void addCard(const Card& card) { cards_.push_back(card); }
  int size() const { return cards_.size(); }
  void playCards();

 private:
  std::vector<Card> cards_;
};
