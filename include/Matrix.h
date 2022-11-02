#pragma once
#include "Vector.h"
#include <cstdint>


namespace swm {
	//=======================
	// MATRIX CLASS TEMPLATE
	//=======================

	template<uint8_t i, uint8_t j, class T = float>
	class mat {
		void init(uint8_t& n, T x) {
			((T*)(data))[n] = x;
		}

		template<class ... Ts>
		void init(uint8_t& n, T x, Ts ... xs) {
			((T*)(data))[n] = x;
			init(++n, xs...);
		}
		
		public:
		vec<i, T> data[j];

		mat(const mat<i, j, T>& m);
		mat(mat<i, j, T>& m);
		void operator=(const mat<i, j, T>& m);
		vec<i, T>& operator[](uint8_t x);

		mat(T w = (T)0);
		mat(T* data);

		template<class T_w>
		mat(mat<i, j, T_w>& m) {
			for (uint8_t x = 0; x < i; x++)
				((T*)(data))[x] = ((T*)(m.data))[x];
		}

		template<class ... Ts>
		mat(Ts ... x) {
			static_assert(sizeof...(Ts) == i * j, "Number of elements in matrix initializer is not eual num matrix size");
			uint8_t n = 0;
			init(n, x...);
		}

		inline mat<i, j, T> operator+(mat<i, j, T>& m);
		inline mat<i, j, T> operator-(mat<i, j, T>& m);
		inline mat<i, i, T> operator*(mat<j, i, T>& m);
		inline vec<i, T> operator*(vec<i, T>& v);

		inline mat<i, j, T> operator+(T& w);
		inline mat<i, j, T> operator-(T& w);
		inline mat<i, j, T> operator*(T& w);
		inline mat<i, j, T> operator/(T& w);

		inline void operator+=(mat<i, j, T>& m);
		inline void operator-=(mat<i, j, T>& m);

		inline void operator+=(T& w);
		inline void operator-=(T& w);
		inline void operator*=(T& w);
		inline void operator/=(T& w);
	};


	//=============================
	// CLASS INITIALIZER FUNCTIONS
	//=============================

	template<uint8_t i, uint8_t j, class T>
	mat<i, j, T>::mat(const mat<i, j, T>& m) {
		for (uint8_t x = 0; x < i; x++)
			data[x] = m.data[x];
	}

	template<uint8_t i, uint8_t j, class T>
	mat<i, j, T>::mat(mat<i, j, T>& m) {
		for (uint8_t x = 0; x < i; x++)
			data[x] = m.data[x];
	}

	template<uint8_t i, uint8_t j, class T>
	void mat<i, j, T>::operator=(const mat<i, j, T>& m) {
		for (uint8_t x = 0; x < i; x++)
			data[x] = m.data[x];
	}

	template<uint8_t i, uint8_t j, class T>
	vec<i, T>& mat<i, j, T>::operator[](uint8_t x) {
		if (x < i)
			return data[x];
		else
			throw;
	}

	template<uint8_t i, uint8_t j, class T>
	mat<i, j, T>::mat(T w) {
		for (uint8_t x = 0; x < i; x++) {
			data[x] = vec<i, T>((T)0);
			data[x][x] = w;
		}
	}

	template<uint8_t i, uint8_t j, class T>
	mat<i, j, T>::mat(T* data) {
		memcpy(mat::data, data, i * j * sizeof(T));
	}


	//===========
	// OPERATORS
	//===========

	template<uint8_t i, uint8_t j, class T>
	mat<i, j, T> mat<i, j, T>::operator+(mat<i, j, T>& m) {
		mat<i, j, T> res{*this};
		for (uint8_t x = 0; x < i * j; x++)
			((T*)(res.data))[x] += ((T*)(m.data))[x];
		return res;
	}

	template<uint8_t i, uint8_t j, class T>
	mat<i, j, T> mat<i, j, T>::operator-(mat<i, j, T>& m) {
		mat<i, j, T> res{*this};
		for (uint8_t x = 0; x < i * j; x++)
			((T*)(res.data))[x] -= ((T*)(m.data))[x];
		return res;
	}

	template<uint8_t i, uint8_t j, class T>
	mat<i, i, T> mat<i, j, T>::operator*(mat<j, i, T>& m) {
		mat<i, i, T> res{(T)0};
		for (uint8_t x = 0; x < i; x++)
			for (uint8_t y = 0; y < i; y++)
				for (uint8_t n = 0; n < j; n++)
					res[x][y] += data[x][n] * m.data[n][y];
		return res;
	}

	template<uint8_t i, uint8_t j, class T>
	vec<i, T> mat<i, j, T>::operator*(vec<i, T>& v) {
		vec<i, T> res{(T)0};
		for (uint8_t x = 0; x < i; x++)
			for (uint8_t y = 0; y < j; y++)
				res[x] += data[x][y] * v[y];
		return res;
	}

	template<uint8_t i, uint8_t j, class T>
	mat<i, j, T> mat<i, j, T>::operator+(T& w) {
		mat<i, j, T> res{*this};
		for (uint8_t x = 0; x < i * j; x++)
			((T*)(this->data))[x] += w;
		return res;
	}

	template<uint8_t i, uint8_t j, class T>
	mat<i, j, T> mat<i, j, T>::operator-(T& w) {
		mat<i, j, T> res{*this};
		for (uint8_t x = 0; x < i * j; x++)
			((T*)(this->data))[x] -= w;
		return res;
	}

	template<uint8_t i, uint8_t j, class T>
	mat<i, j, T> mat<i, j, T>::operator*(T& w) {
		mat<i, j, T> res{*this};
		for (uint8_t x = 0; x < i * j; x++)
			((T*)(this->data))[x] *= w;
		return res;
	}

	template<uint8_t i, uint8_t j, class T>
	mat<i, j, T> mat<i, j, T>::operator/(T& w) {
		mat<i, j, T> res{*this};
		for (uint8_t x = 0; x < i * j; x++)
			((T*)(this->data))[x] /= w;
		return res;
	}


	//================
	// SELF OPERATORS
	//================

	template<uint8_t i, uint8_t j, class T>
	void mat<i, j, T>::operator+=(mat<i, j, T>& m) {
		*this = *this + m;
	}

	template<uint8_t i, uint8_t j, class T>
	void mat<i, j, T>::operator-=(mat<i, j, T>& m) {
		*this = *this - m;
	}

	template<uint8_t i, uint8_t j, class T>
	void mat<i, j, T>::operator+=(T& w) {
		*this = *this + w;
	}

	template<uint8_t i, uint8_t j, class T>
	void mat<i, j, T>::operator-=(T& w) {
		*this = *this - w;
	}

	template<uint8_t i, uint8_t j, class T>
	void mat<i, j, T>::operator*=(T& w) {
		*this = *this * w;
	}

	template<uint8_t i, uint8_t j, class T>
	void mat<i, j, T>::operator/=(T& w) {
		*this = *this / w;
	}


	//===================================
	// SPECIFIC MATRIX CLASS DEFINITIONS
	//===================================

	using mat2 = mat<2, 2, float>;
	using mat3 = mat<3, 3, float>;
	using mat4 = mat<4, 4, float>;

	using dmat2 = mat<2, 2, double>;
	using dmat3 = mat<3, 3, double>;
	using dmat4 = mat<4, 4, double>;

	using i8mat2 = mat<2, 2, int8_t>;
	using i8mat3 = mat<3, 3, int8_t>;
	using i8mat4 = mat<4, 4, int8_t>;
	using ui8mat2 = mat<2, 2, uint8_t>;
	using ui8mat3 = mat<3, 3, uint8_t>;
	using ui8mat4 = mat<4, 4, uint8_t>;

	using i16mat2 = mat<2, 2, int16_t>;
	using i16mat3 = mat<3, 3, int16_t>;
	using i16mat4 = mat<4, 4, int16_t>;
	using ui16mat2 = mat<2, 2, uint16_t>;
	using ui16mat3 = mat<3, 3, uint16_t>;
	using ui16mat4 = mat<4, 4, uint16_t>;

	using i32mat2 = mat<2, 2, int32_t>;
	using i32mat3 = mat<3, 3, int32_t>;
	using i32mat4 = mat<4, 4, int32_t>;
	using ui32mat2 = mat<2, 2, uint32_t>;
	using ui32mat3 = mat<3, 3, uint32_t>;
	using ui32mat4 = mat<4, 4, uint32_t>;

	using i64mat2 = mat<2, 2, int64_t>;
	using i64mat3 = mat<3, 3, int64_t>;
	using i64mat4 = mat<4, 4, int64_t>;
	using ui64mat2 = mat<2, 2, uint64_t>;
	using ui64mat3 = mat<3, 3, uint64_t>;
	using ui64mat4 = mat<4, 4, uint64_t>;

	using imat2 = i32mat2;
	using imat3 = i32mat3;
	using imat4 = i32mat4;
	using uimat2 = ui32mat2;
	using uimat3 = ui32mat3;
	using uimat4 = ui32mat4;
}
