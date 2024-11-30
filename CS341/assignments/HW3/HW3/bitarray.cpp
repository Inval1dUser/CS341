#include "bitarray.h"
#include <bitset>
			
	//
	// void print()
	//
	void BitArray::print()
	{	
		std::cout << "|";
		
		for (int i=0; i < BYTES; i++)
		{
			std::bitset<BIT_IN_BYTE> bits = data_[i];
			std::cout << bits << "|";
		}
		
		std::cout << std::endl;	
	} 

	/**
	 * Initializing constructor.
	 *
	 * @param[in]      size		int		DEFAULT = 0
	*/
	BitArray::BitArray(int size) : LENGTH(size), data_(new char[size]) {
		BYTES = (size + BIT_IN_BYTE - 1) / BIT_IN_BYTE;

		for(int i = 0; i < BYTES; i++) {
			data_[i] = 0;
		}
	}     
			
			/**
			* Copy constructor
			*
			* We need this because we have dynamically allocated
			* memory on this Class.
			*
			* const - We will NOT change the source BitArray.
			*
			* @param[in]     array         The source BitArray.
			*/
	BitArray::BitArray(const BitArray & array) : LENGTH(array.length()), BYTES(array.bytes()){
		//insert data into copy of bit array
		for(int i = 0; i < LENGTH; i++) {			
			data_[i] = array.data_[i];
		}
	}

			/**
			 * Initializes the BitArray with a character array 
			 * (word) and the size of the word (int).
			 *
			 * @param[in]      word		char *
			 * @param[in]	   size		int
			*/		
	void BitArray::initialize(char * word, int size) {
		for(int i = 0; i < size; i++) {
			data_[i] = word[i];
		}
	}
			
			/// Destructor
	BitArray::~BitArray() {}                            

			/**
			 * Returns TRUE if the bit at the specified position
			 * is set (1), FALSE otherwise.
			 *
			 * const - We will NOT change the value of the bit.
			 *
			 * @param[in]	   int
			 *
			 * @return          bool
			*/ 
	bool BitArray::get(int position) const {
		if(data_[position] == 1) {
			return true;
		} else {
			return false;
		} 
	}
			
