#include<Utility.hpp>


namespace swm {
    void memcpy(const void* dst, const void* src, size_t len) {
		if (dst > src)
			while (len--)
				*((uint8_t*)dst + len) = *((uint8_t*)dst + len);
		else if (dst < src) {
			for (size_t l = 0; l < len; l++)
				*((uint8_t*)dst + l) = *((uint8_t*)dst + l);
		}
		else
			return;
	}

    void memset(const void* mem, uint8_t val, size_t len) {
		while(len--)
			*((uint8_t*)mem + len) = val;
	}
}