#include<Color.hpp>


namespace swm {
	//=========================
	// COLOR CLASS DEFINITIONS
	//=========================
	
	Color::Color(const Color& c) {
		memcpy(data, c.data, 4);
	}

	void Color::operator=(const Color& c) {
		memcpy(data, c.data, 4);
	}

	Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
		Color::r = r;
		Color::g = g;
		Color::b = b;
		Color::a = a;
	}

	Color::Color(uint8_t w) {
		Color::r = w;
		Color::g = w;
		Color::b = w;
		Color::a = 255;
	}

	Color::Color(fColor c) {
		Color::r = (uint8_t)(c.r * 255.0f);
		Color::g = (uint8_t)(c.g * 255.0f);
		Color::b = (uint8_t)(c.b * 255.0f);
		Color::a = (uint8_t)(c.a * 255.0f);
	}

	Color Color::operator+(Color c) {
		Color res{*this};
		res.r += c.r;
		res.g += c.g;
		res.b += c.b;
		res.a += c.a;
		return res;
	}

	Color Color::operator-(Color c) {
		Color res{*this};
		res.r -= c.r;
		res.g -= c.g;
		res.b -= c.b;
		res.a -= c.a;
		return res;
	}

	Color Color::operator*(Color c) {
		Color res{*this};
		res.r *= c.r;
		res.g *= c.g;
		res.b *= c.b;
		res.a *= c.a;
		return res;
	}

	Color Color::operator/(Color c) {
		Color res{*this};
		res.r /= c.r;
		res.g /= c.g;
		res.b /= c.b;
		res.a /= c.a;
		return res;
	}

	void Color::operator+=(Color c) {
		*this = *this + c;
	}

	void Color::operator-=(Color c) {
		*this = *this - c;
	}

	void Color::operator*=(Color c) {
		*this = *this * c;
	}

	void Color::operator/=(Color c) {
		*this = *this / c;
	}

	//===============================
	// FLOAT COLOR CLASS DEFINITIONS
	//===============================

	fColor::fColor(const fColor& c) {
		memcpy(data, c.data, 4 * sizeof(float));
	}

	void fColor::operator=(const fColor& c) {
		memcpy(data, c.data, 4 * sizeof(float));
	}

	fColor::fColor(float r, float g, float b, float a) {
		fColor::r = r;
		fColor::g = g;
		fColor::b = b;
		fColor::a = a;
	}

	fColor::fColor(float w) {
		fColor::r = w;
		fColor::g = w;
		fColor::b = w;
		fColor::a = 1.0f;
	}

	fColor::fColor(Color c) {
		fColor::r = (float)c.r / 255.0f;
		fColor::g = (float)c.g / 255.0f;
		fColor::b = (float)c.b / 255.0f;
		fColor::a = (float)c.a / 255.0f;
	}

	fColor fColor::operator+(fColor c) {
		fColor res{*this};
		res.r += c.r;
		res.g += c.g;
		res.b += c.b;
		res.a += c.a;
		return res;
	}

	fColor fColor::operator-(fColor c) {
		fColor res{*this};
		res.r -= c.r;
		res.g -= c.g;
		res.b -= c.b;
		res.a -= c.a;
		return res;
	}

	fColor fColor::operator*(fColor c) {
		fColor res{*this};
		res.r *= c.r;
		res.g *= c.g;
		res.b *= c.b;
		res.a *= c.a;
		return res;
	}

	fColor fColor::operator/(fColor c) {
		fColor res{*this};
		res.r /= c.r;
		res.g /= c.g;
		res.b /= c.b;
		res.a /= c.a;
		return res;
	}

	void fColor::operator+=(fColor c) {
		*this = *this + c;
	}

	void fColor::operator-=(fColor c) {
		*this = *this - c;
	}

	void fColor::operator*=(fColor c) {
		*this = *this * c;
	}

	void fColor::operator/=(fColor c) {
		*this = *this / c;
	}
}
