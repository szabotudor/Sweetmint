#pragma once
#include<cstdint>


namespace swm {
	/**
	 * @brief Copy data from one memory location to another
	 * 
	 * @param dst a pointer to the destination memory address
	 * @param src a pointer to the source memory address
	 * @param len the number of bytes to copy
	 */
	void memcpy(const void* dst, const void* src, size_t len);

	/**
	 * @brief Set a block of memory to a given uint8_t value
	 * 
	 * @param mem a pointer to the block to set
	 * @param val the value to give to each byte in the memory
	 * @param len the length of the memory block in bytes
	 */
	void memset(const void* mem, uint8_t val, size_t len);


	template<class T>
	void resizeArray(T*& arr, size_t oldSize, size_t newSize) {
		T* oldArr = arr;
		arr = new T[newSize];
		if (newSize > oldSize) {
			memset(arr + oldSize, 0, (newSize - oldSize) * sizeof(T));
			newSize = oldSize;
		}
		memcpy(arr, oldArr, newSize * sizeof(T));
		delete[] oldArr;
	}
}
