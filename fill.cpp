// Flood fill algorithm.
#include <iostream>

using namespace std;

struct point {
    int x;
    int y;
};

static int n, m, d[101]; // n si m sunt limitele matricei, d reprezinta vectorul care retine cate elemente face parte dintr o zona
static int mat[1001][1001]; // matrice originala
static int res[1001][1001]; // matricea de rezolvari
static int zone_number = 0; // numarul care se pune pe zona

point dir[] = {point{-1, 0}, point{0, 1}, point{1, 0}, point{0, -1}}; // vectorul de directie

static bool is_in_mat(point p) { // verificarea daca un punct se afla in matrice
    return p.x >= 1 && p.x <= n && p.y >= 1 && p.y <= m;
}

void fill(point start) { // functia de fill
    res[start.x][start.y] = zone_number;
    d[zone_number]++;
    for (auto & i : dir) {
        auto new_point = point{start.x + i.x, start.y + i.y};
        if (is_in_mat(new_point) && res[new_point.x][new_point.y] == 0 && mat[start.x][start.y] == mat[new_point.x][new_point.y])
            fill(new_point);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j]; // citire matrice
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (!res[i][j]) {
                zone_number++;
                fill(point{i, j}); // aplicam fill daca pe res[i][j] nu se afla nimic
            }
        }
    for (int i = 1; i <= n; i++, cout << endl)
        for (int j = 1; j <= m; j++)
            cout << res[i][j] << " ";
}
