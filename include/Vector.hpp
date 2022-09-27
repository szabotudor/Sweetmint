#pragma once
#include<stdint.h>


namespace swm {
	//=======================
	// VECTOR CLASS TEMPLATE
	//=======================

	template<uint8_t S, class T = float>
	class vec {
		void init(uint8_t i, T x) {
			data[i] = x;
		}

		template<class ... Ts>
		void init(uint8_t i, T x, Ts ... next) {
			data[i] = x;
			init(++i, next...);
		}
		
		public:
		T data[S];
		T& x = data[0],
		 & y = data[1],
		 & z = data[2],
		 & w = data[3],

		 & r = data[0],
		 & g = data[1],
		 & b = data[2],
		 & a = data[3];

		vec(const vec<S, T>& v);
		void operator=(const vec<S, T>& v);
		T& operator[](uint8_t i);

		vec(T w = (T)0.0f);
		vec(T* data);
		
		template<class w_T>
		vec(vec<S, w_T> v) {
			for (uint8_t i = 0; i < S; i++)
				data[i] = static_cast<T>(v[i]);
		}

		template<class ... Ts>
		vec(Ts ... x) {
			init(0, x...);
		}

		vec<S, T> operator+(vec<S, T> v);
		vec<S, T> operator-(vec<S, T> v);
		vec<S, T> operator*(vec<S, T> v);
		vec<S, T> operator/(vec<S, T> v);

		void operator+=(vec<S, T> v);
		void operator-=(vec<S, T> v);
		void operator*=(vec<S, T> v);
		void operator/=(vec<S, T> v);

		T length();
		vec<S, T> normalized();
		void normalize();
		vec<S, T> directionTo(vec<S, T> v);
		T distanceTo(vec<S, T> v);
	};


	//====================================
	// SPECIFIC VECTOR CLASS DECLARATIONS
	//====================================

	using vec2 = vec<2, float>;
	using vec3 = vec<3, float>;
	using vec4 = vec<4, float>;

	using dvec2 = vec<2, double>;
	using dvec3 = vec<3, double>;
	using dvec4 = vec<4, double>;

	using ivec2 = vec<2, int32_t>;
	using ivec3 = vec<3, int32_t>;
	using ivec4 = vec<4, int32_t>;

	using uivec2 = vec<2, uint32_t>;
	using uivec3 = vec<3, uint32_t>;
	using uivec4 = vec<4, uint32_t>;

	using ivec2_l = vec<2, int64_t>;
	using ivec3_l = vec<3, int64_t>;
	using ivec4_l = vec<4, int64_t>;

	using uivec2_l = vec<2, uint64_t>;
	using uivec3_l = vec<3, uint64_t>;
	using uivec4_l = vec<4, uint64_t>;
}
