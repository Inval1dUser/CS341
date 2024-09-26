#include "card.h"
#include <iostream>
#include <string>

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

//default constructor
Card::Card() {}

//Initializing Constructor
Card::Card(int suit, int face) : suitVal_(suit), faceVal_(face) {} 

//Destructor
Card::~Card() {}

// Getters
std::string Card::getSuit() const {
    return SUIT[suitVal_];
}

std::string Card::getFace() const {
    return FACE[faceVal_];
}

// Print
std::string Card::print() const {
    return getFace() + " of " + getSuit();
}

// Initialize
void Card::initialize(int suit, int face) {
    suitVal_ = suit;
    faceVal_ = face;
}