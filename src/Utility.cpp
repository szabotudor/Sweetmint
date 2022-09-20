#include<Utility.hpp>


namespace swm {
    void memcpy(const void* dst, const void* src, Size len) {
		if (dst > src)
			while (len--)
				*((uint8_t*)dst + len) = *((uint8_t*)src + len);
		else if (dst < src) {
			for (Size l = 0; l < len; l++)
				*((uint8_t*)dst + l) = *((uint8_t*)src + l);
		}
		else
			return;
	}

    void memset(const void* mem, uint8_t val, Size len) {
		while(len--)
			*((uint8_t*)mem + len) = val;
	}
}