#include <iostream>
#include <string>

using namespace std;

string get_stone_game_result(int stone) {

	if (stone % 2 == 0)
		return "CY";
	else
		return "SK";
}

int main() {
	int N;
	cin >> N;

	cout << get_stone_game_result(N) << "\n";

	return 0;
}