#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
	int target;
	int cost;
};

struct Node {
	int num;
	int cost;

	bool operator < (const Node& r) const {
		return cost > r.cost;
	}
};

int get_min_cost(const int st, const int en, const vector<vector<Edge>>& buses) {
	priority_queue<Node> pq;
	pq.push({ st, 0 });
	vector<int> dist(buses.size(), INT_MAX);
	dist[st] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		
		if (dist[now.num] < now.cost)
			continue;

		if (now.num == en) {
			return dist[now.num];
		}

		for (int i = 0; i < buses[now.num].size(); ++i) {
			int next = buses[now.num][i].target;
			int ncost = dist[now.num] + buses[now.num][i].cost;
			
			if (dist[next] <= ncost)
				continue;

			pq.push({ next, ncost });
			dist[next] = ncost;
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N;
	vector<vector<Edge>> buses(N + 1);
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int st, target, cost;
		cin >> st >> target >> cost;
		buses[st].push_back({target, cost});
	}

	int st, en;
	cin >> st >> en;

	int res = get_min_cost(st, en, buses);

	cout << res << "\n";

	return 0;
}