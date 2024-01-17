#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count_croatia_alphabet(const string word) {

	int count = word.size();

	for (int i = 0; i < word.size(); ++i) {

		if (i < word.size() - 2) {
			if (word[i] == 'd' && word[i+1] == 'z' && word[i+2] == '=')
				count -= 1;
		}

		if (i < word.size() - 1) {
			if (word[i] == 'c' && word[i+1] == '=') {
				--count;
			}
			else if (word[i] == 'c' && word[i+1] == '-') {
				--count;
			}
			else if (word[i] == 'd' && word[i+1] == '-') {
				--count;
			}
			else if (word[i] == 'l' && word[i+1] == 'j') {
				--count;
			}
			else if (word[i] == 'n' && word[i+1] == 'j') {
				--count;
			}
			else if (word[i] == 's' && word[i+1] == '=') {
				--count;
			}
			else if (word[i] == 'z' && word[i+1] == '=') {
				--count;
			}
		}	
	}

	return count;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;
	cout << count_croatia_alphabet(str) << "\n";

	return 0;
}