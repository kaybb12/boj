#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); ++i) {
        q.emplace(priorities[i], i);
        pq.emplace(priorities[i]);
    }
    
    while (!q.empty()) {
        auto[prior_temp, loca_temp] = q.front();
        
        if (prior_temp == pq.top()) {
            if (loca_temp == location)
                break;
            q.pop();
            pq.pop();
            ++answer;
        }
        
        else {
            q.pop();
            q.emplace(prior_temp, loca_temp);
        }
    }
    
    
    return answer;
}