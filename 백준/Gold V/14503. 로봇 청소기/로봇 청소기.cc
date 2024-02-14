#include <array>
#include <iostream>
#include <vector>


using namespace std;
using Matrix = vector<vector<int>>;
using Point = pair<int, int>;

class GC {
    static constexpr int EMPTY = 0;
    static constexpr int WALL = 1;
    static constexpr int CLEANED = 2;

    Matrix room;
    static constexpr array<pair<int, int>, 4> delta = { { 
      { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } 
    } };
                      
    
    int r = 1;
    int c = 1;
    int dir = 0;
    
    void getInput(int n, int m) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> room[i][j];
    }
    
    public :
    GC(const int n, const int m) {
        room = Matrix(n + 2, vector<int>(m + 2, WALL));
        
        getInput(n, m);
    }
    
    inline void init(const int r, const int c, const int dir) {
        this->r = r + 1;
        this->c = c + 1;
        this->dir = dir;
    }
    
    inline void clean() {
        if (room[r][c] == EMPTY)
            room[r][c] = CLEANED;
        
        search_next();
    }
    
    inline bool is_front_empty() {
        const auto& [ dr, dc ] = delta[dir]; 
        int nr = r + dr;
        int nc = c + dc;

        return (room[nr][nc] == EMPTY);
    }
    
    inline bool is_back_wall() {
        const auto& [ dr, dc ] = delta[dir]; 
        int nr = r - dr;
        int nc = c - dc;

        return (room[nr][nc] == WALL);
    }
    
    inline void rotate() {
        dir = (dir + 3) % 4;
    }
    
    inline void forward() {
        const auto& [ dr, dc ] = delta[dir]; 
        r += dr;
        c += dc;
    }
    
    inline void backward() {
        const auto& [ dr, dc ] = delta[dir]; 
        r -= dr;
        c -= dc;
    }
    
    inline void search_next() {
        for (int i = 0; i < 4; ++i) {
            rotate();
            
            if (is_front_empty()) {
                forward();
                clean();
                return;
            }
        }
        
        if (!is_back_wall()) {
            backward();
            search_next();
        }
    }
    
    inline int get_cleaned_area() {
        int count = 0;
        
        for (const auto& line : room) {
            for (const auto& cell : line)
                if (cell == CLEANED)
                    ++count;
        }
        
        return count;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    int r, c, dir;
    cin >> r >> c >> dir;
    
    GC gc(n, m);
    gc.init(r, c, dir);
    gc.clean();
    
    cout << gc.get_cleaned_area() << "\n";
    
    return 0;
}
