#include<Vector.hpp>
#include<cstdint>
#include<memory.h>
#include<math.h>


namespace swm {
	//==========================
	// STANDARD CLASS FUNCTIONS
	//==========================

	template<uint8_t S, class T>
	Vector<S, T>::Vector(const Vector<S, T>& v) {
		memcpy(data, v.data, S * sizeof(T));
	}

	template<uint8_t S, class T>
	void Vector<S, T>::operator=(const Vector<S, T>& v) {
		memcpy(data, v.data, S * sizeof(T));
	}

	template<uint8_t S, class T>
	T& Vector<S, T>::operator[](uint8_t i) {
		return data[i];
	}

	template<uint8_t S, class T>
	Vector<S, T>::Vector(T w) {
		for (uint8_t i = 0; i < S; i++)
			data[i] = w;
	}

	template<uint8_t S, class T>
	Vector<S, T>::Vector(T* data) {
		memcpy(Vector<S, T>::data, data, S * sizeof(T));
	}

	//===========
	// OPERATORS
	//===========

	template<uint8_t S, class T>
	Vector<S, T> Vector<S, T>::operator+(Vector<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] += data[i];
		return v;
	}

	template<uint8_t S, class T>
	Vector<S, T> Vector<S, T>::operator-(Vector<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] -= data[i];
		return v;
	}

	template<uint8_t S, class T>
	Vector<S, T> Vector<S, T>::operator*(Vector<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] *= data[i];
		return v;
	}

	template<uint8_t S, class T>
	Vector<S, T> Vector<S, T>::operator/(Vector<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] /= data[i];
		return v;
	}

	//================
	// SELF OPERATORS
	//================

	template<uint8_t S, class T>
	void Vector<S, T>::operator+=(Vector<S, T> v) {
		*this = *this + v;
	}

	template<uint8_t S, class T>
	void Vector<S, T>::operator-=(Vector<S, T> v) {
		*this = *this - v;
	}

	template<uint8_t S, class T>
	void Vector<S, T>::operator*=(Vector<S, T> v) {
		*this = *this * v;
	}

	template<uint8_t S, class T>
	void Vector<S, T>::operator/=(Vector<S, T> v) {
		*this = *this / v;
	}

	//===================
	// SPECIAL FUNCTIONS
	//===================

	template<uint8_t S, class T>
	T Vector<S, T>::length() {
		T w = (T)0.0f;
		for (uint8_t i = 0; i < S; i++)
			w = (T)sqrt(w * w + data[i] * data[i]);
		return w;
	}

	template<uint8_t S, class T>
	Vector<S, T> Vector<S, T>::normalized() {
		T l = length();
		Vector<S, T> v{*this};
		for (uint8_t i = 0; i < S; i++)
			v[i] /= l;
		return v;
	}

	template<uint8_t S, class T>
	void Vector<S, T>::normalize() {
		*this = this->normalized();
	}

	//=========================================
	// OPERATOR OVERRIDES FOR SPECIFIC CLASSES
	//=========================================

	void vec2::operator=(const vec2& v) {
		x = v.x;
		y = v.y;
	}

	void vec3::operator=(const vec3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}
	void vec4::operator=(const vec4& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		a = v.a;
	}

	void dvec2::operator=(const dvec2& v) {
		x = v.x;
		y = v.y;
	}

	void dvec3::operator=(const dvec3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}
	void dvec4::operator=(const dvec4& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		a = v.a;
	}

	void ivec2::operator=(const ivec2& v) {
		x = v.x;
		y = v.y;
	}

	void ivec3::operator=(const ivec3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}
	void ivec4::operator=(const ivec4& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		a = v.a;
	}

	void uivec2::operator=(const uivec2& v) {
		x = v.x;
		y = v.y;
	}

	void uivec3::operator=(const uivec3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}
	void uivec4::operator=(const uivec4& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		a = v.a;
	}

	void Color::operator=(const Color& c) {
		r = c.r;
		g = c.g;
		b = c.b;
		a = c.a;
	}

	void Colorf::operator=(const Colorf& c) {
		r = c.r;
		g = c.g;
		b = c.b;
		a = c.a;
	}

	Colorf::Colorf(Color c) {
		r = (float)c.r / 255.0f;
		g = (float)c.g / 255.0f;
		b = (float)c.b / 255.0f;
		a = (float)c.a / 255.0f;
	}
}

template class swm::Vector<2, float>;
template class swm::Vector<3, float>;
template class swm::Vector<4, float>;

template class swm::Vector<2, double>;
template class swm::Vector<3, double>;
template class swm::Vector<4, double>;

template class swm::Vector<2, int32_t>;
template class swm::Vector<3, int32_t>;
template class swm::Vector<4, int32_t>;

template class swm::Vector<2, uint32_t>;
template class swm::Vector<3, uint32_t>;
template class swm::Vector<4, uint32_t>;

template class swm::Vector<4, uint8_t>;
