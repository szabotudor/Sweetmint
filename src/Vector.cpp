#include<Vector.hpp>
#include<cstdint>
#include<Utility.hpp>
#include<math.h>


namespace swm {
	//==========================
	// STANDARD CLASS FUNCTIONS
	//==========================

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
		return data[i];
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

	template<uint8_t S, class T>
	template<class w_T>
	vec<S, T>::vec(vec<S, w_T> v) {
		for (uint8_t i = 0; i < S; i++)
			data[i] = static_cast<T>(v[i]);
	}

	//===========
	// OPERATORS
	//===========

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator+(vec<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] += data[i];
		return v;
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator-(vec<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] -= data[i];
		return v;
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator*(vec<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] *= data[i];
		return v;
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator/(vec<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] /= data[i];
		return v;
	}

	//================
	// SELF OPERATORS
	//================

	template<uint8_t S, class T>
	void vec<S, T>::operator+=(vec<S, T> v) {
		*this = *this + v;
	}

	template<uint8_t S, class T>
	void vec<S, T>::operator-=(vec<S, T> v) {
		*this = *this - v;
	}

	template<uint8_t S, class T>
	void vec<S, T>::operator*=(vec<S, T> v) {
		*this = *this * v;
	}

	template<uint8_t S, class T>
	void vec<S, T>::operator/=(vec<S, T> v) {
		*this = *this / v;
	}

	//===================
	// SPECIAL FUNCTIONS
	//===================

	template<uint8_t S, class T>
	T vec<S, T>::length() {
		T w = (T)0.0f;
		for (uint8_t i = 0; i < S; i++)
			w = (T)sqrt(w * w + data[i] * data[i]);
		return w;
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::normalized() {
		T l = length();
		vec<S, T> v{*this};
		for (uint8_t i = 0; i < S; i++)
			v[i] /= l;
		return v;
	}

	template<uint8_t S, class T>
	void vec<S, T>::normalize() {
		*this = this->normalized();
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::directionTo(vec<S, T> v) {
		vec<S, T> res = v - (*this);
		return res.normalized();
	}

	template<uint8_t S, class T>
	T vec<S, T>::distanceTo(vec<S, T> v) {
		vec<S, T> res = v - (*this);
		return res.length();
	}
}
