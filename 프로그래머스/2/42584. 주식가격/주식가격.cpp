#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<pair<int,int>> q;
    
    for (int i = 0; i < prices.size(); ++i) {
        q.emplace(prices[i], i);
    }
    
    while(!q.empty()) {
        int temp = q.front().first;
        int idx = q.front().second;
        int cnt = 0;
        
        for (int i = idx; i < prices.size(); ++i) {
            if (i == prices.size() - 1)
                break;
            
            if (temp <= prices[i])
                cnt++;
            else 
                break;
        }
        
        q.pop();
        answer.emplace_back(cnt);
    }
    
    return answer;
}