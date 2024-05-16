#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int cnt = 0;
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    while(cnt < jobs.size() || !pq.empty()) {
        
        if (cnt < jobs.size() && jobs[cnt][0] <= time) {
            pq.emplace(jobs[cnt++]);
            continue;
        }
        
        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];            
            pq.pop();
        }
        else
            time = jobs[cnt][0];
    }
        
    return answer / jobs.size();
}