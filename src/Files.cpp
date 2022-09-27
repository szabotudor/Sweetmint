#include<Files.hpp>
#include<Utility.hpp>
#include<String.hpp>
#include <ios>


namespace swm {
	File::File(OpenMode openMode, const char* file) {
		if (file != nullptr)
			open(openMode, file);
	}
	
	void File::open(OpenMode openMode, const char* file) {
		if (isOpen)
			close();
		
		size_t len = strlen(file);
		filePath = new char[len];
		memcpy(filePath, file, len);
		File::openMode = openMode;
		isOpen = true;

		#if LINUX
		switch (openMode) {
		case OpenMode::READ:
			inFile = std::ifstream(file, std::ios_base::openmode::_S_bin);
			break;
		
		case OpenMode::WRITE:
			outFile = std::ofstream(file, std::ios_base::openmode::_S_bin);
			break;
		
		case OpenMode::APPEND:
			outFile = std::ofstream(file, std::ios_base::openmode::_S_bin | std::ios_base::openmode::_S_app);
			break;
		
		default:
			break;
		}
		#elif WIN32
		switch (openMode) {
		case OpenMode::READ:
			inFile = std::ifstream(file, std::ios::binary);
			break;
		
		case OpenMode::WRITE:
			outFile = std::ofstream(file, std::ios::binary);
			break;
		
		case OpenMode::APPEND:
			outFile = std::ofstream(file, std::ios::binary | std::ios::app);
			break;
		
		default:
			break;
		}
		#endif
	}

	void File::close() {
		if (isOpen) {
			switch (openMode) {
			case OpenMode::READ:
				inFile.close();
				break;
			
			case OpenMode::WRITE:
				outFile.close();
				break;
			
			case OpenMode::APPEND:
				outFile.close();
				break;
			
			default:
				break;
			}

			delete[] (returnedString->text);
			returnedString->text = nullptr;
			returnedString->len = 0;
			delete[] filePath;
			filePath = nullptr;
			isOpen = false;
		}
	}
	
	File::Str File::read(size_t pos, size_t len) {
		if (isOpen) {
			if (returnedString->text)
				delete[] (returnedString->text);
			if (len) {
				returnedString->len = len + 1;
				returnedString->text = new char[len + 1];
				inFile.seekg(pos);
				inFile.read(returnedString->text, len);
			}
			else {
				inFile.seekg(0, std::ios::end);
				len = inFile.tellg();
				returnedString->len = len + 1;
				returnedString->text = new char[len + 1];
				inFile.seekg(pos);
				inFile.read(returnedString->text, len);
			}
			returnedString->text[len] = '\0';
		}
		return *returnedString;
	}

	void File::write(char* data, size_t len, int64_t pos) {
		if (isOpen and (openMode == OpenMode::WRITE or openMode == OpenMode::APPEND)) {
			if (pos >= 0)
				outFile.seekp(pos);

			outFile.write(data, len);
		}
	}

	File::~File() {
		close();
	}
}
