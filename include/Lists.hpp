#pragma once
#include<Utility.hpp>


namespace swm {
	template<class T, uint16_t blockSize = 256>
	class List {
		struct DataBlock {
			T* data = nullptr;
			uint16_t fill = 0;
		};
		DataBlock* blocks = nullptr;
		uint64_t numBlocks = 0;
		uint64_t elems = 0;

		void forceAddElem(T x) {
			append(x);
		}

		template<class ... Ts>
		void forceAddElem(T x, Ts ... x2) {
			append(x);
			forceAddElem(x2...);
		}

		void addBlock() {
			resizeArray(blocks, numBlocks, numBlocks + 1);
			blocks[numBlocks].data = new T[blockSize];
			blocks[numBlocks].fill = 0;
			numBlocks++;
		}

		public:
		List(const List&) = delete;
		void operator=(const List&) = delete;

		/**
		 * @brief Construct a new List object
		 */
		template<class ... Ts>
		List(Ts ... x) {
			blocks = new DataBlock[1];
			blocks[0].data = new T[blockSize];
			blocks[0].fill = 0;
			memset(blocks[0].data, 0, blockSize * sizeof(T));
			numBlocks = 1;

			forceAddElem(x...);
		}

		/**
		 * @brief Add an element of type 'T' to the list
		 * 
		 * @param x the element to add to the list
		 */
		void append(T x) {
			uint64_t b = elems / blockSize;
			T*& data = blocks[b].data;
			uint16_t& fill = blocks[b].fill;
			
			data[fill] = x;
			elems++;
			fill++;
			if (fill == blockSize)
				addBlock();
		}

		/**
		 * @brief Returns a reference to the element at the given index,
		 * and appends a new element to the list if the index points outside allocated elements
		 * 
		 * @param i the intdex at which the desired element resides
		 * @return the element
		 */
		T& get(uint64_t i) {
			if (i >= elems) {
				append(T{});
				i = elems;
			}
			return blocks[elems / blockSize].data[elems - (elems / blockSize) * blockSize];
		}

		/**
		 * @brief Remove an element from a given position
		 * @param WARNING UNIMPLEMENTED
		 * 
		 * @param pos the position at which the element to be removed resides
		 * (make this parameter negative to start counting from the end of the list)
		 */
		void remove(int64_t pos = -1) {

		}

		/**
		 * @brief Clear all data in the list
		 * 
		 */
		void clear() {
			
		}

		/**
		 * @brief Find how many times a certain object can be found within the list
		 * 
		 * @param x the object to check within the list
		 * @return the number of objects that match the given object
		 */
		uint64_t find(T x) {
			
		}

		~List();
	};
}
