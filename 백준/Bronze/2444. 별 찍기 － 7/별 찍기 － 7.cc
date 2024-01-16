#include <iostream>
#include <vector>

using namespace std;

void print_line(const int star_cnt, const int empty_cnt1) {
	for (int i = 0; i < empty_cnt1; ++i) {
		cout << ' ';
	}

	for (int i = 0; i < star_cnt; ++i) {
		cout << '*';
	}

	cout << "\n";
}

void print_star(const int cnt) {

	for (int i = 1; i <= cnt; ++i) {
		int count = 2 * i - 1;
		print_line(count, cnt - i);
	}

	for (int i = cnt - 1; i > 0; --i) {
		int count = 2 * i - 1;
		print_line(count, cnt - i);
	}
}


int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	print_star(cnt);

	return 0;
}