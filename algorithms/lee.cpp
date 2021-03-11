#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int mat[1001][1001], res[1001][1001];
int m, n;

struct point {
    int x;
    int y;
};

queue<point> q;
vector dir = {point{0, -1}, point{0, 1}, point{-1, 0}, point{1, 0}};

static bool in_mat(point p) {
    return p.x >= 1 && p.y >= 1 && p.x <= n && p.y <= m;
}

void lee(point p) {
    q.push(p);
    res[p.x][p.y] = 1;
    while (!(q.empty())) {
        point front = q.front();
        q.pop();
        for (auto &dir_point : dir) {
            point new_point = point{front.x + dir_point.x, front.y + dir_point.y};
            if (in_mat(new_point) && mat[new_point.x][new_point.y] == 1 && res[new_point.x][new_point.y] == 0) {
                res[new_point.x][new_point.y] = res[front.x][front.y] + 1;
                q.push(new_point);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    cin >> m >> n;
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res[i][j] = 0;
    point plecare = {x, y};
    lee(placeare);
}
