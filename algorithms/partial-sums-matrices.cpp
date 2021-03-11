#include <iostream>

using namespace std;

static int mat[1001][1001], res[1001][1001];
static int m, n;

struct point {
    int x;
    int y;
};

static bool is_in_mat(point p) {
    return p.x >= 1 && p.x <= n && p.y >= 1 && p.y <= m;
}

static int get_sum_for_point(point p) {
    auto near_1 = point{p.x, p.y - 1};
    auto near_2 = point{p.x - 1, p.y};
    auto diagonal = point{p.x - 1, p.y - 1};
    int sum = 0;
    if (is_in_mat(near_1)) {
        sum += res[near_1.x][near_1.y];
    }
    if (is_in_mat(near_2)) {
        sum += res[near_2.x][near_2.y];
    }
    if (is_in_mat(diagonal)) {
        sum -= res[diagonal.x][diagonal.y];
    }
    return sum;
}

static void compute_partial_sums() {
    res[1][1] = mat[1][1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res[i][j] = mat[i][j] + get_sum_for_point(point{i, j});
}

static int get_sum_between(point p1, point p2) {
    return res[p2.x][p2.y] - res[p1.x - 1][p2.y] - res[p2.x][p1.y - 1] + res[p1.x - 1][p1.y - 1];
}

int main(int argc, char* argv[]) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    compute_partial_sums();
    for (int i = 1; i <= n; i++, cout << endl)
        for (int j = 1; j <= m; j++)
            cout << res[i][j] << " ";
    cout << endl << get_sum_between(point{2, 1}, point{3, 2});
}
