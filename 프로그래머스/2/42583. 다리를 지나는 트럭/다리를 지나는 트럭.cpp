#include <string>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> q;
    
    int weight_sum = 0; // 다리 무게 합
    int i = 0; // 트럭 번호
    
    while(1) {
        int now_w = truck_weights[i];
        if (i == truck_weights.size()) {
            answer += bridge_length;
            break;
        }
        
        if (q.size() == bridge_length) {
            weight_sum -= q.front();
            q.pop();
        }
        
        if (weight_sum + now_w <= weight) {
            weight_sum += now_w;
            q.emplace(now_w);
            ++i;
        }
        else
            q.emplace(0);
        
        ++answer;
    }
    
    return answer;
}