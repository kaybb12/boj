/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

inline bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second < b.second;
}

void classyfy_class(const int K, unordered_map<string, int> classes) {
    vector<pair<string, int>> student_nums;
    
    for (const auto & c : classes) {
        student_nums.emplace_back(c);
    }
    
    sort(student_nums.begin(), student_nums.end(), cmp);

    int i = 0;

    for (const auto student_num : student_nums) {
        if (i >= K)
            break;
        
        cout << student_num.first << "\n";

        ++i;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int K, L;
    cin >> K >> L;
    unordered_map<string, int> classes;
    
    for (int i = 0; i < L; ++i) {
        string num;
        cin >> num;
        
        classes[num] = i;
    }
    
    classyfy_class(K, classes);

    return 0;
}