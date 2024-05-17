#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <string> 

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> pq_dec;
    priority_queue<int, vector<int>, greater<int>> pq_inc;
    
    int cnt = 0;
    
    for (const auto op : operations) {
        char order;
        int num;
        stringstream str(op);
        str >> order;
        str >> num;
        
        if (order == 'I') {
            pq_inc.emplace(num);
            pq_dec.emplace(num);
            ++cnt;
        }
        
        else if (order == 'D') {
            if (num == 1) {
                if (!pq_dec.empty()) {
                    pq_dec.pop();
                    --cnt;
                }
            }
            
            else if (num == -1) {
                if (!pq_inc.empty()) {
                    pq_inc.pop();
                    --cnt;
                }
            }
        }
        
        if (cnt == 0) {
            while (!pq_inc.empty()) {
                pq_inc.pop();
            }
            while (!pq_dec.empty()) {
                pq_dec.pop();
            }
        }
    }
    
    if (!pq_inc.empty() && !pq_dec.empty()) {
        answer.emplace_back(pq_dec.top());
        answer.emplace_back(pq_inc.top());
    }
    
    else {
        answer.emplace_back(0);
        answer.emplace_back(0);
    }
    
    
    return answer;
}