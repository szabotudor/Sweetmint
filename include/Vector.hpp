#pragma once
#include<cstdint>
#include<stdint.h>
#include"String.hpp"


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

		vec(const vec<S, T>& v);
		vec(vec<S, T>* v);
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
			static_assert(sizeof...(Ts) <= S, "Too many arguments for vector init");
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
		T dot(vec<S, T> v);
	};


	//====================================
	// SPECIFIC VECTOR CLASS DECLARATIONS
	//====================================

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

	class ivec2 : public vec<2, int32_t> {
		public:
		using vec<2, int32_t>::vec;

		int32_t& x = data[0],
			& y = data[1];
	};
	class ivec3 : public vec<3, int32_t> {
		public:
		using vec<3, int32_t>::vec;

		int32_t& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class ivec4 : public vec<4, int32_t> {
		public:
		using vec<4, int32_t>::vec;

		int32_t& x = data[0],
			& y = data[1],
			& z = data[2],
			& w = data[3];
	};

	class uivec2 : public vec<2, uint32_t> {
		public:
		using vec<2, uint32_t>::vec;

		uint32_t& x = data[0],
			& y = data[1];
	};
	class uivec3 : public vec<3, uint32_t> {
		public:
		using vec<3, uint32_t>::vec;

		uint32_t& x = data[0],
			& y = data[1],
			& z = data[2];
	};
	class uivec4 : public vec<4, uint32_t> {
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
}
