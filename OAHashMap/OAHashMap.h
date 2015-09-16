

class OAHashMapException
{
};


template<typename T>
class OAHashMap
{
public:

	//===================================================================
	// Constructor
	// Pre: -
	// Post: The hash map is initiated to hold 's' entries, and is initially
	//		 empty
	//===================================================================
	OAHashMap(size_t s) : size(s), nEntriesUsed(0)
	{
		map = new MapEntry<T>[size];
	}

	//===================================================================
	// Destructor
	// Pre: -
	// Post: Hash map is deallocated
	//===================================================================
	~OAHashMap()
	{
		delete[] map;
	}


	//===================================================================
	// search
	// Pre: -
	// Post: Returns true if 'key' is found in the map, false otherwise
	//===================================================================
	bool search(const T& key)
	{
		size_t dummy;
		return findIndex(key, dummy);
	}


	//===================================================================
	// insert()
	// Pre: -
	// Post: If key is in map, nothing is done. Otherwise, if there is room 
	//		 for key in the map it is inserted. Otherwise an exception is 
	//		 thrown
	//===================================================================
	void insert(const T& key)
	{
		size_t index = 0;
		if (findIndex(key, index)) return;	// Key already in map - return

		// INV: key not in map

		if (nEntriesUsed == size) throw OAHashMapException();	// Map is full - no room for key

		index = hash(key);
		
		while (map[index].state == MapEntry<T>::OCCUPIED) index = (index+1) % size;	// Linear probing

		// Open address found - insert key
		map[index].key = key;
		map[index].state = MapEntry<T>::OCCUPIED;

		++nEntriesUsed;
	}


	//===================================================================
	// remove()
	// Pre: -
	// Post: If key is in map, it is removed.
	//===================================================================
	void remove(const T& key)
	{
		size_t index;

		if (findIndex(key, index))
		{
			map[index].state = MapEntry<T>::INVALID;
			--nEntriesUsed;
		}
	}


	//===================================================================
	// getLoadFactor()
	// Pre: -
	// Post: The load factor of the hash map is returned
	//===================================================================
	double getLoadFactor()
	{
		return (double)nEntriesUsed / size;
	}

private:

	// Internal class to hold map entries
	template<typename T>
	class MapEntry
	{
	public:
		enum AddressState
		{
			OCCUPIED,
			INVALID,
			PRISTINE
		};

		MapEntry(const T& k = T()) : key(k), state(PRISTINE) {}
		T key;
		AddressState state;
	};


	//===================================================================
	// findIndex()
	// Pre: -
	// Post: If key is in the map, the index of key is written to index and true is returned
	//		 If key is NOT in map, index is garbage and false is returned
	//===================================================================
	bool findIndex(const T& key, size_t& index)
	{
		size_t firstIndex = hash(key);
		size_t probeIndex = firstIndex;

		while (true)
		{
			if (map[probeIndex].state == MapEntry<T>::PRISTINE)
				return false;

			if (map[probeIndex].key == key)
			{
				index = probeIndex;
				return true;
			}
			
			probeIndex = (probeIndex + 1) % size;

			if (probeIndex == firstIndex)
			{
				return false;
			}
		}
	}

	size_t hash(const T& key)
	{
		return 0;
	}

	MapEntry<T>* map;
	size_t size;
	size_t nEntriesUsed;
};