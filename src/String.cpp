#include<String.hpp>
#include<Utility.hpp>


namespace swm {
	//=====================
	// C STRING OPERATIONS
	//=====================

	Size strlen(const char* s) {
		Size size = 0;
		while (s[++size]);
		return size;
	}

	void strcpy(char* dst, const char* src) {
		Size i = 0;
		while (dst[i] and src[i])
			dst[i] = src[i++];
	}

	void strrev(char *str) {
		Size len = strlen(str);
		char aux = '\0';
		for (Size i = 0; i < len / 2; i++) {
			aux = str[i];
			str[i] = str[len - i];
			str[len - i] = aux;
		}
	}


	//=================================
	// SWEETMINT STRING IMPLEMENTATION
	//=================================

	String::String(const String& s) {
		*this = s;
	}

	void String::operator=(const String& s) {
		if (len != 0)
			delete[] cstr;
		len = s.len;
		cstr = new char[len];
		memcpy(cstr, s.cstr, len);
	}

	String::String(const char* s) {
		len = strlen(s);
		cstr = new char[len];
		memcpy(cstr, s, len);
	}

	String::String(const char c) {
		len = 2;
		cstr = new char[len];
		cstr[0] = c;
	}

	String::String(Size len) {
		String::len = len;
		cstr = new char[len]{'\0'};
	}

	char& String::operator[](Size &i) {
		if (i == len) {
			resizeArray(cstr, len, len + 1);
			i = len++;
		}
		else if (i > len)
			return cstr[0];
		return cstr[i];
	}

	String String::operator+(String& s) {
		String res{len + s.len};
		memcpy(res.cstr, cstr, len);
		memcpy(res.cstr + len, s.cstr, s.len);
		return res;
	}

	void String::operator+=(String &s) {
		*this = *this + s;
	}

	void String::clear() {
		delete[] cstr;
		cstr = nullptr;
		len = 0;
	}

	Size String::length() {
		return len;
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
		String res{i2 - i1 + 1};
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

	String::~String() {
		clear();
	}
}