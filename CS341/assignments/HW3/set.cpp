#include "bitarray.h"
#include "set.h"

    /**
	* Initializing constructor. Builds a BitArray
	* instance of 'size.'
	*/
	Set::Set(int size) : data_(BitArray(size)) {}

	/// Destructor
	Set::~Set() {}

	/**
	* Initializes the underlying BitArray with a
	* character array (word) and the size of the
	* word (int).
    *
	* @param[in]      word		char *
	* @param[in]	   size		int
	*/
	void Set::initialize(char * word, int size) {
		data_.initialize(word, size); 
	}

	/**
	* Returns the cardinality of the set - here the 
	* cardinality is represented by the number of 1's
	* in the underlying BitArray.
	*
	* const - We will not change the underlying BitArray.
	*
	* @return          int
	*/ 
	int Set::getCardinality() const {
		int count = 0;
		for (int i = 0; i < data_.bytes() * BIT_IN_BYTE ; i++) {
			if(data_.get(i)) {
				count++;
			} 
		}
		return count;
	}
	/**
	 * Returns a reference to the underyling BitArray data_
     *
	 * @return          BitArray &
	 */ 
	BitArray & Set::getData() {
		return data_;
	}
	
	/**
	* Computes the Union of "this" set (A) and B.
	* 
	* A = A U B	(A.setUnion(B);)
	*
	* Returns TRUE if successful - false is unable.
	*
	* @param[in]	   Set &
	*
	* @return          bool
	*/ 
	bool Set::setUnion(Set & B) {
		//OR (|) each position in set A and B
		for(int i = 0; i < (data_.bytes() * BIT_IN_BYTE) ; i++) {
			if(data_.get(i) == 1 || B.getData().get(i) == 1) {
				data_.set(i, 1);
			}
		}
		return true;
	}

	//TODO: fix if setIntersection
	/**
	     * Computes the Intersection of "this" set (A) and B.
		 * 
		 * A = A X B	(A.setIntersection(B);)
		 *
		 * Returns TRUE if successful - false is unable.
	     *
		 * @param[in]	   Set &
		 *
	     * @return          bool
	    */ 
	bool Set::setIntersection(Set & B) {
		//AND (&) each position in set A and B
		for(int i = 0; i < (data_.bytes() * BIT_IN_BYTE); i++) {
			if(data_.get(i) != B.getData().get(i)) {
				data_.set(i, 0);
			}
		}
		return true;
	}


