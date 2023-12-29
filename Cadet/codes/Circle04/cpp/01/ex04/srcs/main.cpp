#include <iostream>
#include <fstream>

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Arguments Error." << std::endl;
		return 1;
	}

	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::string	line;

	std::ifstream	inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Open Error.";
		return 1;
	}
	std::ofstream	outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Cannot Create File.";
		return 1;
	}

	while (getline(inputFile, line)) {
		size_t	pos = 0;	// position

		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());	// s1을 삭제
			line.insert(pos, s2);			// s2를 삽입
			pos += s2.length();
		}
		outputFile << line;
		if (inputFile.peek() != EOF)
			outputFile << '\n';
	}

	std::cout << "Success!!" << std::endl;

	return 0;
}
