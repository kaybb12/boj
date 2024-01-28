#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
static vector<string> pokemon;
static map<string, int> pokedex;
static vector<string> answer;

void make_correct_answer(const string quiz) {
	if (quiz[0] >= 'A' && quiz[0] <= 'Z') {
		answer.push_back(to_string(pokedex[quiz]));
	}
	else {
		answer.push_back(pokemon[stoi(quiz) - 1]);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	string index;

	for (int i = 1; i <= N; ++i) {
		cin >> index;
		pokemon.push_back(index);
		pokedex.insert(make_pair(index, i));
	}

	for (int i = 0; i < M; ++i) {
		cin >> index;
		make_correct_answer(index);
	}

	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << "\n";
	}

	return 0;
}