#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "standardDeck.h"
#include <array>
#include <string>

int main() {

    std::vector<Card> deckVec; //store deck of cards
    
    //create and insert deck of cards into vector
    for (size_t i = 1; i <= 4; i++)
    {
        for (size_t j = 1; j <= 13; j++)
        {
            Card card(i, j);
            card.initialize(i, j);
            deckVec.push_back(card);
            card.~Card();
        }
    }

    //impliment standardDeck.cpp methods
    StandardDeck deck;
    deck.printDeck();
    std::cout << " " << std::endl;
    std::cout << "Is the deck empty?: " << deck.isEmpty() << std::endl;
    std::cout << "Number of Cards: " << deck.getNumCards() << std::endl;
    std::cout << "15th Card: "; deck.displayCard(15);
    std::cout << " " << std::endl;
    deck.shuffle();
    deck.printDeck();

    return 0;
}