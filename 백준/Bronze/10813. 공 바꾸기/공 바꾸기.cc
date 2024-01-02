#include <iostream>
#include <vector>

using namespace std;

void print_ball_number(int N, int M) {
	vector<int> basket(N);

	for (int idx = 0; idx < N; ++idx) {
		basket[idx] = idx;
	}

	for (int idx = 0; idx < M; ++idx) {
		int i, j;
		cin >> i >> j;
		i -= 1;
		j -= 1;

		int ex_basket;
		ex_basket = basket[i];
		basket[i] = basket[j];
		basket[j] = ex_basket; 
	}

	for (int idx = 0; idx < N; ++idx) {
		cout << basket[idx]+1 << " ";
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	print_ball_number(N, M);

	return 0;
}