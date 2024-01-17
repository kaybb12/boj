#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int check_paelindrom(string str) {

	string temp = str;

	reverse(str.begin(), str.end());
	
	if (temp == str)
		return 1;
	else
		return 0;

	return 0;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	cout << check_paelindrom(str) << "\n";

	return 0;
}