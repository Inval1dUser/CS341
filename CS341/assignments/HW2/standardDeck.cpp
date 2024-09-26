#include "standardDeck.h"
#include "card.h"
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

		// Default constructor.
		StandardDeck::StandardDeck() : deck_(new Card[DECK_SIZE]), numCards_(DECK_SIZE) {
			for (int i = 0; i < DECK_SIZE; i++) {
				int suit = (i / 13) + 1; // Suit (1-4)
				int face = (i % 13) + 1; // Face (1-13)
				deck_[i].initialize(suit, face);
			}
		}
		
		/// Default destructor.
		StandardDeck::~StandardDeck() {
			delete[] deck_;
		}

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
        bool StandardDeck::isEmpty() {
			return numCards_ == 0;
		}

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		int StandardDeck::getNumCards() {
			return numCards_;
        }

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		void StandardDeck::displayCard(int i) {
			std::cout << deck_[i].print() << std::endl;
        }

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		void StandardDeck::printDeck() {
			for (size_t i = 0; i <  numCards_; i++)
			{
				std::cout << deck_[i].print() << std::endl;
			}
        }

		bool StandardDeck::addCard(Card c) {
			
		}
		//generate a random number (randInt) between 0 and vecSize, swap deck_[i] and deck_[randInt] until i reaches 52
		void StandardDeck::shuffle() {
			for (size_t i = 0; i < 52; i++)
			{
				int randInt = rand() % 52; //random int between 0 and 52
				std::swap(deck_[i], deck_[randInt]);
			}
		}

		void StandardDeck::initializeDeck() {

		}