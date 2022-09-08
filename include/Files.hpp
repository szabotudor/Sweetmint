#pragma once
#include<fstream>


namespace swm {
	class File {
		public:
		enum class OpenMode {
			READ,
			WRITE,
			APPEND
		};

		struct Str {
			char* text = nullptr;
			size_t len = 0;
		};

		private:
		char* filePath = nullptr;
		bool isOpen = false;;
		std::ifstream inFile{};
		std::ofstream outFile{};
		OpenMode openMode{};
		Str* returnedString = new Str;
		
		public:
		File(const File&) = delete;
		void operator=(const File&) = delete;

		/**
		 * @brief Create a new File object
		 * 
		 * @param open 
		 * @param file 
		 */
		File(OpenMode openMode = OpenMode::READ, const char* file = nullptr);

		/**
		 * @brief Load a file, and prepare it for reading/writing
		 * 
		 * @param file the path to the file to load
		 */
		void open(OpenMode openMode, const char* file);

		/**
		 * @brief Closes the currently open file
		 * 
		 */
		void close();

		/**
		 * @brief Read a number of bytes directly from a specific position in the file (File must be in OpenMode::READ)
		 * 
		 * @param pos the position to start reading from
		 * @param len the number of bytes to read, or 0 to read the whole file
		 * 
		 * @return a struct containing a pointer to a C string, which will be deleted the next time you read from the file, and the length of the string in bytes
		 */
		Str read(size_t pos, size_t len);

		/**
		 * @brief Write a length of bytes to the file at a specified position
		 * 
		 * @param data a char array to write to the file
		 * @param len the length of the given string to write
		 * @param pos the position in the file to write at, or -1 to not seek in the file
		 */
		void write(char* data, size_t len, int64_t pos = -1);

		~File();
	};
}