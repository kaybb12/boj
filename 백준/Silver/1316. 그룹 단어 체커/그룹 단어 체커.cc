#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_group_word(const string str) {
	for (int i = 0; i < str.length(); ++i) {
		if (i > 0) {
			for(int j = 0; j < i; ++j) {
				if (str[i] != str[i-1] && str[i] == str[j]) {
					//cout << "0" << "\n";
					return false;
				}
			}
		}
	}

	//cout << "1" << "\n";
	return true;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int count = 0;

	for (int test_case = 0; test_case < T; ++test_case) {
		string str;
		cin >> str;

		if(is_group_word(str))
			++count;
	}

	cout << count << "\n";

	return 0;
}