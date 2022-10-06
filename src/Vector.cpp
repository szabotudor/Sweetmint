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
	vec<S, T>::vec(vec<S, T>* v) {
		memcpy(data, v->data, S * sizeof(T));
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

	//===========
	// OPERATORS
	//===========

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator+(vec<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] = data[i] + v.data[i];
		return v;
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator-(vec<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] = data[i] - v.data[i];
		return v;
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator*(vec<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] = data[i] * v.data[i];
		return v;
	}

	template<uint8_t S, class T>
	vec<S, T> vec<S, T>::operator/(vec<S, T> v) {
		for (uint8_t i = 0; i < S; i++)
			v.data[i] = data[i] * v.data[i];
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
		T w = static_cast<T>(0.0f);
		for (uint8_t i = 0; i < S; i++)
			w += data[i] * data[i];
		return (T)sqrt(w);
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
			res += data[i] * data[i];
		return res;
	}
}

template class swm::vec<2, float>;
template class swm::vec<3, float>;
template class swm::vec<4, float>;

template class swm::vec<2, double>;
template class swm::vec<3, double>;
template class swm::vec<4, double>;

template class swm::vec<2, int32_t>;
template class swm::vec<3, int32_t>;
template class swm::vec<4, int32_t>;

template class swm::vec<2, uint32_t>;
template class swm::vec<3, uint32_t>;
template class swm::vec<4, uint32_t>;

template class swm::vec<2, int64_t>;
template class swm::vec<3, int64_t>;
template class swm::vec<4, int64_t>;

template class swm::vec<2, uint64_t>;
template class swm::vec<3, uint64_t>;
template class swm::vec<4, uint64_t>;
