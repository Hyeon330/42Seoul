#include <iostream>
#include <fstream>

using namespace	std;

static void	replaceFile(ifstream& inputFile, ofstream& outputFile, string& s1, string& s2) {
	string	line;

	while (getline(inputFile, line)) {
		size_t	pos = 0;	// position

		while ((pos = line.find(s1, pos)) != string::npos) {
			line.erase(pos, s1.length());	// s1을 삭제
			line.insert(pos, s2);	// s2를 삽입
			pos += s2.length();
		}
		outputFile << line;
		if (inputFile.peek() != EOF)
			outputFile << '\n';
	}

	cout << "Success!!" << endl;
}

int main(int ac, char **av) {
	if (ac != 4) {
		cerr << "Arguments Error.";
		return 1;
	}

	string	filename = av[1];
	string	s1 = av[2];
	string	s2 = av[3];

	ifstream	inputFile(filename);
	if (!inputFile.is_open()) {
		cerr << "Open Error.";
		return 1;
	}

	ofstream	outputFile(filename + ".replace");
	if (outputFile.is_open())
		replaceFile(inputFile, outputFile, s1, s2);
	else {
		cerr << "Cannot Create File.";
		return 1;
	}
	
	return 0;
}
