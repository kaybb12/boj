#include <string>
#include <vector>
#include <queue>
#include <array>
#include <climits>

using namespace std;
using Point = pair<int, int>;

static constexpr int WALL = 1;

struct Node{
    Point id;
    int direction;
    int cost;
    
    bool operator<(const Node &right) const {
        return cost > right.cost;
    }
};

static const array<Point, 4> dir = {{
    { 1, 0 }, { -1, 0 }, { 0, 1}, { 0, -1 }
}};

int solution(vector<vector<int>> board) {
    int N = board.size();
    Point fin = { N - 1, N - 1 };
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(4, INT_MAX)));
    priority_queue<Node> pq; 
    
    for (int d = 0; d < 4; ++d) {
        dist[0][0][d] = 0;
        pq.push({{0, 0}, d, 0});
    }
    
    while(!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        int r = now.id.first;
        int c = now.id.second;
        
        if (r == fin.first && c == fin.second) {
            continue;
        }
        
        if (dist[r][c][now.direction] < now.cost)
            continue;
        
        for (int i = 0; i < dir.size(); ++i) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            
            if (nr < 0 || nc < 0 || nr >= N || nc >= N)
                continue;
            
            if (board[nr][nc] == WALL)
                continue;
            
            int ncost = now.cost + 100;
            
            if (now.direction != i) {
                ncost += 500;
            }
            
            if (dist[nr][nc][i] > ncost) {
                dist[nr][nc][i] = ncost;
                pq.push({ { nr, nc }, i, ncost });
            }
        } 
    }
    
    int min_cost = INT_MAX;
    for (int d = 0; d < 4; ++d) {
        if (dist[N - 1][N - 1][d] < min_cost) {
            min_cost = dist[N - 1][N - 1][d];
        }
    }
    return min_cost;
}
