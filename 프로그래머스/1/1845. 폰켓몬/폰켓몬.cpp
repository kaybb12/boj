#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int get_num = nums.size() / 2;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int res_num = nums.size();
    if (get_num < res_num)
        answer = get_num;
    else
        answer = res_num;
    
    return answer;
}