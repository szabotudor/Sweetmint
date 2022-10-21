#include "Sweetmint.h"


namespace swm {
	//=====================
	// C STRING OPERATIONS
	//=====================

	Size strlen(const char* s) {
		Size size = 0;
		while (s[size] != '\0')
			size++;
		return size;
	}

	void strcpy(char* dst, const char* src) {
		Size i = 0;
		while (dst[i] != '\0' and src[i] != '\0') {
			dst[i] = src[i];
			i++;
		}
	}

	void strrev(char *str) {
		Size len = (strlen(str) - 1);
		char aux = '\0';
		for (Size i = 0; i <= len / 2; i++) {
			aux = str[i];
			str[i] = str[len - i];
			str[len - i] = aux;
		}
	}

	bool streq(const char *s1, const char *s2) {
		Size len1 = strlen(s1),
			len2 = strlen(s2);
		if (len1 == len2) {
			len1 = 0;
			while (len1 < len2)
				if (s1[len1] != s2[len1])
					return false;
				else
					len1++;
			return true;
		}
		else
			return false;
	}


	//=================================
	// SWEETMINT STRING IMPLEMENTATION
	//=================================

	String::String(const String& s) {
		len = s.len;
		cstr = new char[len];
		memcpy(cstr, s.cstr, len);
	}

	void String::operator=(const String& s) {
		if (cstr != nullptr)
			delete[] cstr;
		len = s.len;
		cstr = new char[len];
		memcpy(cstr, s.cstr, len);
	}

	String::String(const char* s) {
		len = strlen(s) + 1;
		cstr = new char[len];
		memcpy(cstr, s, len);
		cstr[len - 1] = '\0';
	}

	String::String(char& c) {
		len = 2;
		cstr = new char[len];
		cstr[0] = c;
		cstr[1] = '\0';
	}

	String::String() {
		*this = "";
		len = 1;
	}

	char& String::operator[](Size i) {
		if (i >= len) {
			if (i - len < 256)
				extend(i - len + 1);
			else
				return cstr[len - 1];
		}
		return cstr[i];
	}

	String String::operator+(String s) {
		String res{*this};
		res.extend(s.len - 1);
		memcpy(res.cstr + len - 1, s.cstr, s.len);
		return res;
	}

	void String::operator+=(String s) {
		*this = *this + s;
	}

	bool String::operator==(String s) {
		return streq(cstr, s.cstr);
	}

	void String::clear() {
		delete[] cstr;
		cstr = new char[1];
		len = 1;
	}

	Size String::length() {
		return len - 1;
	}

	String String::subString(Size i1, Size i2) {
		bool rev = false;
		if (i1 > i2) {
			rev = true;
			Size aux = i1;
			i1 = i2;
			i2 = aux;
		}
		else if (i1 == i2)
			return String{this->cstr[i1]};
		String res{};
		res.extend(i2 - i1 + 1);
		memcpy(res.cstr, cstr + i1, i2 - i1 + 1);

		if (rev)
			return res.reversed();
		else
			return res;
	}

	String String::reversed() {
		String res{*this};
		strrev(res.cstr);
		return res;
	}

	void String::reverse() {
		*this = this->reversed();
	}

	void String::extend(Size i) {
		char* aux = new char[len + i];
		memcpy(aux, cstr, len - 1);
		memset(aux + len - 1, ' ', i);
		delete[] cstr;
		cstr = aux;
		len += i;
		cstr[len - 1] = '\0';
	}

	char* String::getCString() {
		return cstr;
	}

	int32_t String::toInt32() {
		int32_t res = 0;
		bool neg = (cstr[0] == '-');
		for (uint64_t i = neg; i < len - 1; i++) {
			if (cstr[i] >= '0' and cstr[i] <= '9')
				res = res * 10 + cstr[i] - '0';
			else
				return res;
		}
		if (neg)
			res = -res;
		return res;
	}

	uint32_t String::toUint32() {
		uint32_t res = 0;
		for (uint64_t i = 0; i < len - 1; i++) {
			if (cstr[i] >= '0' and cstr[i] <= '9')
				res = res * 10 + cstr[i] - '0';
			else
				return res;
		}
		return res;
	}

	int64_t String::toInt64() {
		int64_t res = 0;
		bool neg = (cstr[0] == '-');
		for (uint64_t i = neg; i < len - 1; i++) {
			if (cstr[i] >= '0' and cstr[i] <= '9')
				res = res * 10 + cstr[i] - '0';
			else
				return res;
		}
		if (neg)
			res = -res;
		return res;
	}

	uint64_t String::toUint64() {
		uint64_t res = 0;
		for (uint64_t i = 0; i < len - 1; i++) {
			if (cstr[i] >= '0' and cstr[i] <= '9')
				res = res * 10 + cstr[i] - '0';
			else
				return res;
		}
		return res;
	}

	float String::toFloat() {
		float res = 0.0f;
		uint8_t dp = 0;
		bool neg = (cstr[0] == '-');
		for (uint64_t i = neg; i < len - 1; i++) {
			if (cstr[i] >= '0' and cstr[i] <= '9') {
				res = res * 10 + cstr[i] - '0';
			}
			else if (cstr[i] == '.')
				dp = len - i - 2;
			else
				return res;
		}
		while (dp) {
			res /= 10;
			dp--;
		}
		if (neg)
			res = -res;
		return res;
	}

	double String::toDouble() {
		double res = 0.0;
		uint8_t dp = 0;
		bool neg = (cstr[0] == '-');
		for (uint64_t i = neg; i < len - 1; i++) {
			if (cstr[i] >= '0' and cstr[i] <= '9') {
				res = res * 10 + cstr[i] - '0';
			}
			else if (cstr[i] == '.')
				dp = len - i - 2;
			else
				return res;
		}
		while (dp) {
			res /= 10;
			dp--;
		}
		if (neg)
			res = -res;
		return res;
	}

	String::~String() {
		delete[] cstr;
	}
}