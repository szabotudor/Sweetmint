#pragma once


namespace swm {
	/**
	 * @brief Get the length of a C-style string
	 * 
	 * @param s a char array
	 * @return Size 
	 */
	Size strlen(const char* s);

	/**
	 * @brief Copy the data from one C-style string to another
	 * 
	 * @param dst the C-style string to copy the data to
	 * @param src the C-style string to copy the data from
	 */
	void strcpy(char* dst, const char* src);

	/**
	 * @brief Reverse a C-style string
	 * 
	 * @param str the string to reverse
	 */
	void strrev(char* str);

	/**
	 * @brief Check if two C-style strings are equal
	 * 
	 * @param s1 the first strings
	 * @param s2 the second string
	 * @return true if the strings are equal
	 * @return false if the strings contain any different letters, or are not the same size
	 */
	bool streq(const char* s1, const char* s2);


	class String {
		char* cstr = nullptr;
		Size len = 0;
		
		public:
		String(const String& s);
		void operator=(const String& s);

		/**
		 * @brief Construct a new String object from a char array
		 * 
		 * @param s a C-style string
		 */
		String(const char* s);

		/**
		 * @brief Construct a new String object from a single character
		 * 
		 * @param c the character to set the string to
		 */
		String(char& c);

		String();

		char& operator[](Size i);
		String operator+(String s);
		void operator+=(String s);

		bool operator==(String s);

		/**
		 * @brief Clear the string to an empty string
		 */
		void clear();

		/**
		 * @brief Return the length of the string
		 * 
		 * @return the length of the string in bytes 
		 */
		Size length();

		/**
		 * @brief Get a substring between (and including) two indexes
		 * (if the second index is smaller than the first one, the returned string will be reversed)
		 * 
		 * @param i1 the index to the first character to get
		 * @param i2 the index to the last character
		 * @return String
		 */
		String subString(Size i1, Size i2);

		/**
		 * @brief Return a reversed version of the string
		 * 
		 * @return String 
		 */
		String reversed();

		/**
		 * @brief Reverse the string
		 */
		void reverse();

		/**
		 * @brief Extend the string, adding spaces at the end
		 * 
		 * @param i number of characters to add to the string
		 */
		void extend(Size i);

		/**
		 * @brief Return a pointer to the C version of the string
		 */
		char* getCString();

		int32_t toInt32();
		uint32_t toUint32();
		int64_t toInt64();
		uint64_t toUint64();
		float toFloat();
		double toDouble();

		~String();
	};
}