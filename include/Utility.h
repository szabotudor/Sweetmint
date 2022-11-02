#pragma once
#include <cstdint>


namespace swm {
	using Size = uint64_t;


	/**
	 * @brief Copy data from one memory location to another
	 * 
	 * @param dst a pointer to the destination memory address
	 * @param src a pointer to the source memory address
	 * @param len the number of bytes to copy
	 */
	void memcpy(const void* dst, const void* src, Size len);

	/**
	 * @brief Set a block of memory to a given uint8_t value
	 * 
	 * @param mem a pointer to the block to set
	 * @param val the value to give to each byte in the memory
	 * @param len the length of the memory block in bytes
	 */
	void memset(const void* mem, uint8_t val, Size len);


	template<class T>
	void resizeArray(T*& arr, Size oldSize, Size newSize) {
		T* oldArr = arr;
		arr = new T[newSize];
		if (newSize > oldSize) {
			memset(arr + oldSize, 0, (newSize - oldSize) * sizeof(T));
			newSize = oldSize;
		}
		memcpy(arr, oldArr, newSize * sizeof(T));
		if (oldSize > 0)
			delete[] oldArr;
	}

	template<class T>
	T min(T a, T b) {
		if (a < b)
			return a;
		else
			return b;
	}

	template<class T, class ... Ts>
	T min(T a, Ts ... b) {
		return min(a, min(b...));
	}

	template<class T>
	T max(T a, T b) {
		if (a > b)
			return a;
		else
			return b;
	}

	template<class T, class ... Ts>
	T max(T a, Ts ... b) {
		return max(a, max(b...));
	}
}
