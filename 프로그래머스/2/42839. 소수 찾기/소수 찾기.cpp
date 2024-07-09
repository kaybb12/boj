#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline bool is_prime (const int num) {
    
    if (num < 2)
        return false;
    
    if (num == 2)
        return true;
    
    for (int i = 2; i*i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> nums;
    vector<char> strs;
    
    for (const auto str : numbers) {
        strs.emplace_back(str);
    }
    
    sort(strs.begin(), strs.end());
    
    do {
        string temp = "";
        for (const auto str : strs) {
            temp.push_back(str);
            nums.emplace_back(stoi(temp));
        }
    } while (next_permutation(strs.begin(), strs.end()));
    
    sort (nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    for (const auto &num : nums) {
        if(is_prime(num))
            ++answer;
    }
    
    return answer;
}