#include <iostream>
#include <string>

using namespace std;

string reverseString(string s) {
	int inputLength = s.size();
	if (inputLength == 0) {
		string nullString = "";
		return nullString;
	}
	char array[inputLength + 1];
	for (int i = 1; i < inputLength + 1; i++) {
		char c = s.at(inputLength - i);
		array[i - 1] = c;
	}
	array[inputLength] = '\0';
	return array;
}

int main(int argc, char const *argv[]) {
	string original = "This is a string.";
	cout << "The generated string is: " << original << endl;
	string reversed = reverseString(original);
	cout << "The processed string is: " << reversed << endl;
	return 0;
}
