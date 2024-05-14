#include <string>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

inline int target_scoville (priority_queue<int, vector<int>, greater<int>>& pq) {
    int sco_1 = pq.top();
    pq.pop();
    int sco_2 = pq.top();
    pq.pop();
    
    return sco_1 + (sco_2 * 2);
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (const auto& sco : scoville)
        pq.emplace(sco);
    
    while(!pq.empty()) {
        if (pq.size() > 1) {
            if (pq.top() < K) {
                int sco = target_scoville(pq);
                pq.emplace(sco);
                ++answer;
            }            
            else
                return answer;
        }
        
        else if (pq.size() == 1){
            if (pq.top() >= K)
                return answer;
            else
                break;
        }
    }
    
    return -1;
}