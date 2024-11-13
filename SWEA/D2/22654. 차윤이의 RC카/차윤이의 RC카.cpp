#include <iostream>

using namespace std;

int T;
int N;
int starty, startx, endy, endx;
char boards[6][6];
int nowy, nowx, dir;

// 방향배열: 상우하좌
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

// cmd 가 A 일 때는 전진
// L 일 때는 왼쪽으로 회전
// R 일 때는 오른쪽으로 회전
void run(char cmd) {
    if (cmd == 'A') {
        int ny = nowy + dy[dir];
        int nx = nowx + dx[dir];

        // 이동 불가능하다면 pass
        if (boards[ny][nx] == 'T') return;
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) return;

        nowy = ny, nowx = nx;
    }
    else if (cmd == 'L') {
        dir = dir - 1;
        if (dir < 0) dir = 3;
    }
    else if (cmd == 'R') {
        dir = (dir + 1) % 4;
    }
}

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < N; j++) {
                boards[i][j] = row[j];
                // 출발점과 도착점 저장하기
                if (row[j] == 'X') {
                    starty = i, startx = j;
                }
                else if (row[j] == 'Y') {
                    endy = i, endx = j;
                }
            }
        }

        cout << "#" << tc << " ";

        int Q;
        cin >> Q;

        for (int i = 0; i < Q; i++) {
            // 초기화
            nowy = starty, nowx = startx;
            dir = 0;

            int cmd_cnt;
            string cmd;
            cin >> cmd_cnt >> cmd;

            for (int j = 0; j < cmd_cnt; j++) {
                run(cmd[j]);
            }

            if (nowy == endy && nowx == endx) {
                cout << "1 ";
            }
            else {
                cout << "0 ";
            }
        }

        cout << "\n";
    }

    return 0;
}