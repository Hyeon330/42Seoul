#include <iostream>
using namespace std;

int main() {
	string	str = "HI This Is Brain";
	string*	stringPTR = &str;
	string&	stringREF = str;

	cout << "================ memory =================" << endl;
	cout << "str memory: " << &str << endl;
	cout << "PTR memory: " << stringPTR << endl;
	cout << "REF memory: " << &stringREF << endl;

	cout << "================ value ==================" << endl;

	cout << "str value: " << str << endl;
	cout << "PTR value: " << *stringPTR << endl;
	cout << "REF value: " << stringREF << endl;
}