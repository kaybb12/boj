#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for (int i = 0; i < citations.size(); ++i) {
        int h = citations.size() - i;
        
        if(citations[i] >= h) {
            answer = h;
            break;
        }
    }
    
    return answer;
}