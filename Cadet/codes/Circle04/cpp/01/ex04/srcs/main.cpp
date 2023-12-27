#include <iostream>
#include <fstream>

static void	replaceFile(std::ifstream& inputFile, std::ofstream& outputFile, std::string& s1, std::string& s2) {
	std::string	line;

	while (getline(inputFile, line)) {
		size_t	pos = 0;	// position

		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());	// s1을 삭제
			line.insert(pos, s2);	// s2를 삽입
			pos += s2.length();
		}
		outputFile << line;
		if (inputFile.peek() != EOF)
			outputFile << '\n';
	}

	std::cout << "Success!!" << std::endl;
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Arguments Error.";
		return 1;
	}

	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	std::ifstream	inputFile(filename);
	if (!inputFile.is_open()) {
		std::cerr << "Open Error.";
		return 1;
	}

	std::ofstream	outputFile(filename + ".replace");
	if (outputFile.is_open())
		replaceFile(inputFile, outputFile, s1, s2);
	else {
		std::cerr << "Cannot Create File.";
		return 1;
	}
	
	return 0;
}
