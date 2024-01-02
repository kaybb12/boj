#include <iostream>
#include <vector>

using namespace std;

void print_ball_num(int N, int M) {
	vector<int> basket(N);

	for (int idx = 0; idx < M; ++idx) {
		int i, j, k;
		cin >> i >> j >> k;

		for (int bas_idx = i-1; bas_idx < j; ++bas_idx) {
			basket[bas_idx] = k;
		}
	}

	for (int cnt = 0; cnt < N; ++cnt)
		cout << basket[cnt] << " ";
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	print_ball_num(N, M);

	return 0;
}