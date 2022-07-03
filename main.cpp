#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <fstream>

#define log(text, ...) printf(text, __VA_ARGS__);

int main(int argc, char* argv[]) {

	if (argc < 3) {
		log("Usage: xor_file [file_name] [output_name] [key]");
		return -1;
	}

	const auto key = std::stoi(argv[3]);
	log("Xoring file %s with key: %d\n", argv[1], key);

	std::ifstream input_file(argv[1], std::ios::binary);
	std::ofstream output_file(argv[2], std::ios::binary);

	std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input_file), {}); // read the file

	for (auto i = 0; i < buffer.size(); i++) { 
		buffer[i] ^= key;  // xor each byte with key
		output_file.write((const char*)&buffer[i], sizeof(buffer[i])); // write file with encrypted bytes
	}

	log("Written to output file: %s\n", argv[2]);

	output_file.close();
	input_file.close();
	return 0;
}
