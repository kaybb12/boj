#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int is_max_score(vector<double> score) {
	double max_score = 0;
	for (int i = 0; i < score.size(); ++i) {
		max_score = max(max_score, score[i]);
	}

	return max_score;
}

double change_score(vector<double> score, const double max_score, const int num_sub) {

	double average = 0;
	for (int i = 0; i < score.size(); ++i) {
		score[i] = (score[i] / max_score) * 100;
		average += score[i];
	}
	average = average/num_sub;

	return average;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int num_sub;
	cin >> num_sub;

	vector<double> score(num_sub);
	for (int i = 0; i < score.size(); ++i) {
		cin >> score[i];
	}

	double max_score = is_max_score(score);
	cout.precision(15);
	cout << change_score(score, max_score, num_sub) << "\n";

	return 0;
}