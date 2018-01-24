#include <iostream>
#include <string>

using namespace std;

string reverseVowels(string s) {
	int inputLength = s.size();
	char array[inputLength + 1];
	for (size_t i = 0; i < inputLength; i++) {
		array[i] = s.at(i);
	}
	array[inputLength] = '\0';
	int k = inputLength - 1;
	for (size_t j = 0; j < k && j < inputLength; j++) {
		if (array[j] == 'a' || array[j] == 'e' || array[j] == 'i' ||
		 array[j] == 'o' || array[j] == 'u' || array[j] == 'A' ||
		  array[j] == 'E' || array[j] == 'I' || array[j] == 'O' || array[j] == 'U') {
			for (; k > j; k--) {
				if (array[k] == 'a' || array[k] == 'e' || array[k] == 'i' ||
				 array[k] == 'o' || array[k] == 'u' || array[k] == 'A' ||
				 array[k] == 'E' || array[k] == 'I' || array[k] == 'O' || array[k] == 'U') {
					char temp = array[j];
					array[j] = array[k];
					array[k] = temp;
					k--;
					break;
				}
			}
		}
	}
	return array;
}


int main(int argc, char const *argv[]) {
	string original = "leetcode";
	cout << "The generated string is: " << original << endl;
	string reversed = reverseVowels(original);
	cout << "The processed string is: " << reversed << endl;
	return 0;
}
