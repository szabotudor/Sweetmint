#pragma once


namespace swm {
	class Color;
	class fColor;

	class Color {
		public:
		uint8_t data[4]{255};
		uint8_t& r = data[0],
			& g = data[1],
			& b = data[2],
			& a = data[3];
		
		Color(const Color& c);
		void operator=(const Color& c);
		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
		Color(uint8_t w = 255);
		Color(fColor c);

		Color operator+(Color c);
		Color operator-(Color c);
		Color operator*(Color c);
		Color operator/(Color c);
		void operator+=(Color c);
		void operator-=(Color c);
		void operator*=(Color c);
		void operator/=(Color c);
	};

	class fColor {
		public:
		float data[4]{1.0f};
		float& r = data[0],
			& g = data[1],
			& b = data[2],
			& a = data[3];
		
		fColor(const fColor& c);
		void operator=(const fColor& c);
		fColor(float r, float g, float b, float a = 1.0f);
		fColor(float w = 1.0f);
		fColor(Color c);

		fColor operator+(fColor c);
		fColor operator-(fColor c);
		fColor operator*(fColor c);
		fColor operator/(fColor c);
		void operator+=(fColor c);
		void operator-=(fColor c);
		void operator*=(fColor c);
		void operator/=(fColor c);
	};
}
