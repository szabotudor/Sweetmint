#pragma once
#include<cstdint>


namespace swm {
	//=======================
	// VECTOR CLASS TEMPLATE
	//=======================

	template<uint8_t S, class T = float>
	class vec {
		void init(uint8_t& i, T x) {
			data[i] = x;
		}

		template<class ... Ts>
		void init(uint8_t& i, T x, Ts ... next) {
			data[i] = x;
			init(++i, next...);
		}
		
		public:
		T data[S];

		vec(const vec<S, T>& v);
		void operator=(const vec<S, T>& v);
		inline T& operator[](uint8_t i);

		vec(T w = (T)0.0f);
		vec(T* data);
		
		template<class w_T>
		vec(vec<S, w_T> v) {
			for (uint8_t i = 0; i < S; i++)
				data[i] = static_cast<T>(v[i]);
		}

		template<class ... Ts>
		vec(Ts ... x) {
			static_assert(sizeof...(Ts) <= S, "Too many arguments for vector init");
			uint8_t i = 0;
			init(i, x...);
		}

		inline vec<S, T> operator+(vec<S, T>& v);
		inline vec<S, T> operator-(vec<S, T>& v);
		inline vec<S, T> operator*(vec<S, T>& v);
		inline vec<S, T> operator/(vec<S, T>& v);

		inline void operator+=(vec<S, T>& v);
		inline void operator-=(vec<S, T>& v);
		inline void operator*=(vec<S, T>& v);
		inline void operator/=(vec<S, T>& v);

		T length();
		vec<S, T> normalized();
		void normalize();
		vec<S, T> directionTo(vec<S, T> v);
		T distanceTo(vec<S, T> v);
		T dot(vec<S, T> v);
	};


	//=============================
	// CLASS INITIALIZER FUNCTIONS
	//=============================

	template<uint8_t S, class T>
	vec<S, T>::vec(const vec<S, T>& v) {
		memcpy(data, v.data, S * sizeof(T));
	}

	template<uint8_t S, class T>
	void vec<S, T>::operator=(const vec<S, T>& v) {
		memcpy(data, v.data, S * sizeof(T));
	}

	template<uint8_t S, class T>
	T& vec<S, T>::operator[](uint8_t i) {
		if (i < S)
			return data[i];
		else
			throw;
	}

	template<uint8_t S, class T>
	vec<S, T>::vec(T w) {
		for (uint8_t i = 0; i < S; i++)
			data[i] = w;
	}

	template<uint8_t S, class T>
	vec<S, T>::vec(T* data) {
		memcpy(vec<S, T>::data, data, S * sizeof(T));
	}

	//===========
	// OPERATORS
	//===========

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator+(vec<S, T>& v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] = data[i] + v.data[i];
		return v;
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator-(vec<S, T>& v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] = data[i] - v.data[i];
		return v;
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator*(vec<S, T>& v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] = data[i] * v.data[i];
		return v;
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator/(vec<S, T>& v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] = data[i] * v.data[i];
		return v;
	}

	//================
	// SELF OPERATORS
	//================

	template<uint8_t S, class T>
	void vec<S, T>::operator+=(vec<S, T>& v) {
		*this = *this + v;
	}

	template<uint8_t S, class T>
	void vec<S, T>::operator-=(vec<S, T>& v) {
		*this = *this - v;
	}

	template<uint8_t S, class T>
	void vec<S, T>::operator*=(vec<S, T>& v) {
		*this = *this * v;
	}

	template<uint8_t S, class T>
	void vec<S, T>::operator/=(vec<S, T>& v) {
		*this = *this / v;
	}

	//===================
	// SPECIAL FUNCTIONS
	//===================

	template<uint8_t S, class T>
	T vec<S, T>::length() {
		return (T)sqrt(this->dot(*this));
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::normalized() {
		return *this / length();
	}

	template<uint8_t S, class T>
	void vec<S, T>::normalize() {
		*this = this / length();
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::directionTo(vec<S, T> v) {
		return (v - (*this)).normalized();
	}

	template<uint8_t S, class T>
	T vec<S, T>::distanceTo(vec<S, T> v) {
		return (v - (*this)).length();
	}

	template<uint8_t S, class T>
	T vec<S, T>::dot(vec<S, T> v) {
		T res = 0.0f;
		for (uint8_t i = 0; i < S; i++)
			res += data[i] * v.data[i];
		return res;
	}


	//===================================
	// SPECIFIC VECTOR CLASS DEFINITIONS
	//===================================

	class vec2 : public vec<2, float> {
		public:
		using vec<2, float>::vec;

		float& x = data[0],
			& y = data[1];
	};
	class vec3 : public vec<3, float> {
		public:
		using vec<3, float>::vec;

		float& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class vec4 : public vec<4, float> {
		public:
		using vec<4, float>::vec;

		float& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};

	class dvec2 : public vec<2, double> {
		public:
		using vec<2, double>::vec;

		double& x = data[0],
			& y = data[1];
	};
	class dvec3 : public vec<3, double> {
		public:
		using vec<3, double>::vec;

		double& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class dvec4 : public vec<4, double> {
		public:
		using vec<4, double>::vec;

		double& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};

	class i8vec2 : public vec<2, int8_t> {
		public:
		using vec<2, int8_t>::vec;

		int8_t& x = data[0],
			& y = data[1];
	};
	class i8vec3 : public vec<3, int8_t> {
		public:
		using vec<3, int8_t>::vec;

		int8_t& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class i8vec4 : public vec<4, int8_t> {
		public:
		using vec<4, int8_t>::vec;

		int8_t& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};

	class ui8vec2 : public vec<2, uint8_t> {
		public:
		using vec<2, uint8_t>::vec;

		uint8_t& x = data[0],
			& y = data[1];
	};
	class ui8vec3 : public vec<3, uint8_t> {
		public:
		using vec<3, uint8_t>::vec;

		uint8_t& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class ui8vec4 : public vec<4, uint8_t> {
		public:
		using vec<4, uint8_t>::vec;

		uint8_t& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};

	class i16vec2 : public vec<2, int16_t> {
		public:
		using vec<2, int16_t>::vec;

		int16_t& x = data[0],
			& y = data[1];
	};
	class i16vec3 : public vec<3, int16_t> {
		public:
		using vec<3, int16_t>::vec;

		int16_t& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class i16vec4 : public vec<4, int16_t> {
		public:
		using vec<4, int16_t>::vec;

		int16_t& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};

	class ui16vec2 : public vec<2, uint16_t> {
		public:
		using vec<2, uint16_t>::vec;

		uint16_t& x = data[0],
			& y = data[1];
	};
	class ui16vec3 : public vec<3, uint16_t> {
		public:
		using vec<3, uint16_t>::vec;

		uint16_t& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class ui16vec4 : public vec<4, uint16_t> {
		public:
		using vec<4, uint16_t>::vec;

		uint16_t& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};

	class i32vec2 : public vec<2, int32_t> {
		public:
		using vec<2, int32_t>::vec;

		int32_t& x = data[0],
			& y = data[1];
	};
	class i32vec3 : public vec<3, int32_t> {
		public:
		using vec<3, int32_t>::vec;

		int32_t& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class i32vec4 : public vec<4, int32_t> {
		public:
		using vec<4, int32_t>::vec;

		int32_t& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};

	class ui32vec2 : public vec<2, uint32_t> {
		public:
		using vec<2, uint32_t>::vec;

		uint32_t& x = data[0],
			& y = data[1];
	};
	class ui32vec3 : public vec<3, uint32_t> {
		public:
		using vec<3, uint32_t>::vec;

		uint32_t& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class ui32vec4 : public vec<4, uint32_t> {
		public:
		using vec<4, uint32_t>::vec;

		uint32_t& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};

	class livec2 : public vec<2, int64_t> {
		public:
		using vec<2, int64_t>::vec;

		int64_t& x = data[0],
			& y = data[1];
	};
	class livec3 : public vec<3, int64_t> {
		public:
		using vec<3, int64_t>::vec;

		int64_t& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class livec4 : public vec<4, int64_t> {
		public:
		using vec<4, int64_t>::vec;

		int64_t& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};

	class luivec2 : public vec<2, uint64_t> {
		public:
		using vec<2, uint64_t>::vec;

		uint64_t& x = data[0],
			& y = data[1];
	};
	class luivec3 : public vec<3, uint64_t> {
		public:
		using vec<3, uint64_t>::vec;

		uint64_t& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class luivec4 : public vec<4, uint64_t> {
		public:
		using vec<4, uint64_t>::vec;

		uint64_t& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};


	using ivec2 = i32vec2;
	using ivec3 = i32vec3;
	using ivec3 = i32vec3;
	using uivec2 = ui32vec2;
	using uivec3 = ui32vec3;
	using uivec3 = ui32vec3;
}
