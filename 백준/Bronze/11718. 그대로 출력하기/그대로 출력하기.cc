#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string str;
	while(getline(cin, str))
		cout << str << "\n";

	return 0;
}