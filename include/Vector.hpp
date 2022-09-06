#pragma once
#include<stdint.h>


namespace swm {
	//=======================
	// VECTOR CLASS TEMPLATE
	//=======================

	template<uint8_t S, class T = float>
	class Vector {
		public:
		T data[S];

		Vector(const Vector<S, T>& v);
		void operator=(const Vector<S, T>& v);
		T& operator[](uint8_t i);

		Vector(T w = (T)0.0f);
		Vector(T* data);

		Vector<S, T> operator+(Vector<S, T> v);
		Vector<S, T> operator-(Vector<S, T> v);
		Vector<S, T> operator*(Vector<S, T> v);
		Vector<S, T> operator/(Vector<S, T> v);

		void operator+=(Vector<S, T> v);
		void operator-=(Vector<S, T> v);
		void operator*=(Vector<S, T> v);
		void operator/=(Vector<S, T> v);

		T length();
		Vector<S, T> normalized();
		void normalize();
	};


	//====================================
	// SPECIFIC VECTOR CLASS DECLARATIONS
	//====================================

	class vec2: public Vector<2, float> {
		public:
		void operator=(const vec2& v);

		float& x = data[0];
		float& y = data[1];
	};

	class vec3: public Vector<3, float> {
		public:
		void operator=(const vec3& v);

		float& x = data[0];
		float& y = data[1];
		float& z = data[2];
	};

	class vec4: public Vector<4, float> {
		public:
		void operator=(const vec4& v);

		float& x = data[0];
		float& y = data[1];
		float& z = data[2];
		float& a = data[3];
	};

	class dvec2: public Vector<2, double> {
		public:
		void operator=(const dvec2& v);

		double& x = data[0];
		double& y = data[1];
	};

	class dvec3: public Vector<3, double> {
		public:
		void operator=(const dvec3& v);

		double& x = data[0];
		double& y = data[1];
		double& z = data[2];
	};

	class dvec4: public Vector<4, double> {
		public:
		void operator=(const dvec4& v);

		double& x = data[0];
		double& y = data[1];
		double& z = data[2];
		double& a = data[3];
	};

	class ivec2: public Vector<2, int32_t> {
		public:
		void operator=(const ivec2& v);

		int32_t& x = data[0];
		int32_t& y = data[1];
	};

	class ivec3: public Vector<3, int32_t> {
		public:
		void operator=(const ivec3& v);

		int32_t& x = data[0];
		int32_t& y = data[1];
		int32_t& z = data[2];
	};

	class ivec4: public Vector<4, int32_t> {
		public:
		void operator=(const ivec4& v);

		int32_t& x = data[0];
		int32_t& y = data[1];
		int32_t& z = data[2];
		int32_t& a = data[3];
	};

	class uivec2: public Vector<2, uint32_t> {
		public:
		void operator=(const uivec2& v);

		uint32_t& x = data[0];
		uint32_t& y = data[1];
	};

	class uivec3: public Vector<3, uint32_t> {
		public:
		void operator=(const uivec3& v);

		uint32_t& x = data[0];
		uint32_t& y = data[1];
		uint32_t& z = data[2];
	};

	class uivec4: public Vector<4, uint32_t> {
		public:
		void operator=(const uivec4& v);

		uint32_t& x = data[0];
		uint32_t& y = data[1];
		uint32_t& z = data[2];
		uint32_t& a = data[3];
	};

	class Color: public Vector<4, uint8_t> {
		public:
		void operator=(const Color& c);

		uint8_t& r = data[0];
		uint8_t& g = data[1];
		uint8_t& b = data[2];
		uint8_t& a = data[3];

		uint8_t& red = data[0];
		uint8_t& green = data[1];
		uint8_t& blue = data[2];
		uint8_t& alpha = data[3];
	};

	class Colorf : public Vector<4, float> {
		public:
		void operator=(const Colorf& c);

		float& r = data[0];
		float& g = data[1];
		float& b = data[2];
		float& a = data[3];

		float& red = data[0];
		float& green = data[1];
		float& blue = data[2];
		float& alpha = data[3];

		Colorf(Color c);
	};
}
