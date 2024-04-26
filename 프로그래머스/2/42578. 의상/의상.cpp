#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> map;
    
    for (const auto& clothes_name : clothes) {
            map[clothes_name[1]] += 1;
    }
    
    for (auto cloth : map)
        answer *= cloth.second + 1;
    
    return answer - 1;
}