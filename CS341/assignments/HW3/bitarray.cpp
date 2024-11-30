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
	BitArray::BitArray(int size) : LENGTH(size), data_(new char[size]), BYTES((size + BIT_IN_BYTE - 1) / BIT_IN_BYTE) {
		for(int i = 0; i < BYTES; i++) {
			data_[i] = 0;
		}
	}     
			
	/**
	* Copy constructor
	*
	* We need this because we have dynamically allocated
	* memory on this Class.
	*/
	BitArray::BitArray(const BitArray & array) : LENGTH(array.length()), BYTES(array.bytes()), data_(array.data_){}
	

	/**
	* Initializes the BitArray with a character array 
	* (word) and the size of the word (int).
	*/		
	void BitArray::initialize(char * word, int size) {
		for(int i = 0; i < size; i++) {
			data_[i] = word[i];
		}
	}
			
			/// Destructor
	BitArray::~BitArray() {
		delete []data_;
	}                            

	/**
	* Returns TRUE if the bit at the specified position
	* is set (1), FALSE otherwise.
	*/ 
	bool BitArray::get(int position) const {
		int byte = position / BIT_IN_BYTE;
		int bit = position % BIT_IN_BYTE;
		if(data_[byte] & (1 << bit)) {
			return true;
		} else {
			return false;
		} 
	}

	/**
	* Flips the bit at the specified position: 1->0, 0->1.
	* Returns TRUE if successful - FALSE otherwise.
	*/
	bool BitArray::flip(int position) {
		if (position < 0 || position >= LENGTH) {
        return false;  // Invalid position
    	}

		int ByteIndex = position / BIT_IN_BYTE;
		int BitIndex = position % BIT_IN_BYTE;
		int temp = data_[ByteIndex];
		data_[ByteIndex] ^= (1 << BitIndex);
		return (temp == data_[ByteIndex]);
	}

	/**
	* Sets a bit value (default: 1) at the specified position.
	* Returns TRUE if successful - FALSE otherwise.
	*/
	bool BitArray::set(int position, int bit) {
		int ByteIndex = position / BIT_IN_BYTE; //Byte location
		int BitIndex = position % BIT_IN_BYTE; //Bit location in Byte
		int temp = data_[ByteIndex];
		
		if(data_[ByteIndex] != bit)
		data_[ByteIndex] ^= (1 << BitIndex);
		return (temp == data_[ByteIndex]);

		return true;
	}

	/**
	* Returns the character in the byte (8 bits)
	* within the BitArray given a specified position.
	*/ 
	char BitArray::get8(int position) const {
		return data_[position];
	}

	/**
	     * Flips the 1's and 0's in the BitArray.
	    */
	void BitArray::complement() {
		//TODO: make upper limit not hardcoded
		for (int i = 0; i < BYTES * BIT_IN_BYTE ; i++) 
		{
			int ByteIndex = i / BIT_IN_BYTE;
			int BitIndex = i % BIT_IN_BYTE;
			data_[ByteIndex] ^= (1 << BitIndex);
		}
	}

	/**
     * Sets all of the bits to 0.
	 */
	void BitArray::clear() {
		for (int i = 0; i < BYTES * BIT_IN_BYTE ; i++) 
		{
			int ByteIndex = i / BIT_IN_BYTE;
			data_[ByteIndex] = 0;
		}
	}

	/**
	     * Sets the character in given byte with a specified
		 * index for the character array.
	*/ 
	void BitArray::set8(char c, int index) {
		data_[index] = c;
	}
	/*
       .-.      _______                             .  '  *   .  . '
      {}``; |==|_______D                              .  * * -+-  
      / ('        /|\                             .    * .    '  *
  (  /  |        / | \                                * .  ' .  . 
   \(_)_]]      /  |  \                            *   *  .   .
                                                     '   *
	*/
	
			
