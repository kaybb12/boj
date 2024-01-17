#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<double, double> change_score_double(const vector<string>& sub) {

	double credit = 0;
	double score = 0;

	if (sub[2] != "P") {
		credit = stod(sub[1]);
	}

	if (sub[2] == "A+")
		score = 4.5;
	else if (sub[2] == "A0")
		score = 4.0;
	else if (sub[2] == "B+")
		score = 3.5;
	else if (sub[2] == "B0")
		score = 3.0;
	else if (sub[2] == "C+")
		score = 2.5;
	else if (sub[2] == "C0")
		score = 2.0;
	else if (sub[2] == "D+")
		score = 1.5;
	else if (sub[2] == "D0")
		score = 1.0;
	else if (sub[2] == "F")
		score = 0;

	return { credit, score };
}

inline double calculate_score(const double credit, const double score) {
	return score / credit;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	double total_credit = 0;
	double total_score = 0;

	for (int test_case = 0; test_case < 20; ++test_case) {
		vector<string> subject(3);

		for (int i = 0; i < 3; ++i) {
			cin >> subject[i];		
		}

		auto [credit, score] = change_score_double(subject);
		
		total_credit += credit;
		total_score += score * credit;
	}

	cout << fixed;
	cout.precision(6);
	cout << calculate_score(total_credit, total_score) << "\n";

	return 0;
}