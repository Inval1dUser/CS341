#include "dictionary.h"
#include "set.h"

#include <ostream>

        /// Constructor
        Dictionary::Dictionary() : lookupTable_(new int[DICTIONARY_SIZE]) {}                        
		
		/// Destructor
		Dictionary::~Dictionary() {
			delete []lookupTable_;
		} 
		//copy constructor 
		Dictionary::Dictionary (const Dictionary & dict) : lookupTable_(dict.lookupTable_) {}

		void Dictionary::initialize(char * word, int size) {
			data_ = BitArray(size);
			data_.initialize(word, size);
			buildLookupTable();
		}
		
		int Dictionary::rank_range(int start, int end, int bit) {
			int count = 0;
			for(int i = start; i < end; i++) {
				if(data_.get(i) == bit) count++;
			}
			return count;
		}   

		int Dictionary::select_range(int start, int end, int k, int bit) {
			int count = 0;
			for(int i = start; i < end; i++) {
				if(data_.get(i) == bit) {
					count++;
					if(count == k) return i;
				}
			}
			return 0;
		}

		int Dictionary::rank(int end, int bit) {
			int count = 0;
			for(int i = 0; i < end; i++) {
				if(data_.get(i) == bit) {
					count++;
				}
			}
			return count;
		}

		int Dictionary::select(int k, int bit) {
			int count = 0;
			for(int i = 0; i < data_.bytes() * BIT_IN_BYTE; i++) {
				if(data_.get(i) == bit) {
					count++;
					if(count == k) return i;
				}
			}
			return 0;
		}

		void Dictionary::printLookupTable(std::ostream & output) {
			for (int i = 0; i < DICTIONARY_SIZE; i++)
			{
				output << "lookupTable_[" << i << "]: " << lookupTable_[i] << std::endl;
			}
			output << "\n";
		}

		//Build lookup table
		void Dictionary::buildLookupTable() {
			for (int i = 0; i < DICTIONARY_SIZE; i++) {
				lookupTable_[i] = data_.get(i);
			}
		}