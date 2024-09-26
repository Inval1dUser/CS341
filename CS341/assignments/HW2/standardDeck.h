#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include "card.h"

#define DECK_SIZE 52

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck
{
	public:
		/// Default constructor.
		StandardDeck();
		
		/// Default destructor.
		~StandardDeck();

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		bool isEmpty();	

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		void printDeck();	

		/**
		 * return TRUE if the Card c can be added to the end of the Deck, 
		 * otherwise it will return FALSE.
		 * 
		 * @param[Card c]
		 * @return Boolean 
		 */
		bool addCard(Card c); 

		/**
		 * Using random sort from CS 248 perform at-least three (3) x the 
		 * number of cards in the deck swaps.
		 * 
		 * @return void
		 */
		void shuffle();

		/**
		 * populates the StandardDeck Card array with the
		 * appropriate 52 cards.
		 * 
		 * @return void
		 */
		void initializeDeck();
   		
	protected: 
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.h
		int numCards_;	// Stores the number of Cards currently in the deck.
};

#endif