#include <string>
#include <vector>

using namespace std;

bool cmp(int yellow, int i, int brown) {
    return ((((yellow / i) + i) * 2) + 4) == brown;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int width, height;
    
    for (int i = 1; i * i <= yellow; ++i) {
        if (yellow % i == 0) {
            if (yellow / i >= i) {
                if (cmp(yellow, i, brown)) {
                    height = i + 2;
                    width = yellow / i + 2;
                    break;
                }
            }
        }
    }
    
    answer.emplace_back(width);
    answer.emplace_back(height);
    
    return answer;
}