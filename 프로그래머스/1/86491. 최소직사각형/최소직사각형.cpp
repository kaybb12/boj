#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int w = 0;
    int h = 0;
    
    for (const auto size : sizes) {
        if (size[0] > size[1]) {
            w = max(w, size[0]);
            h = max(h, size[1]);
        }
        else {
            w = max(w, size[1]);
            h = max(h, size[0]);
        }
        
        //cout << "w: " << w << " h: " << h << "\n";
    }
    
    return w * h;
}