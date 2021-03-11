#include <iostream>
#include <unordered_map>

using namespace std;

struct point {
  int x;
  int y;
}

int mat[1001][1001];
unordered_map<point, bool> map = {};

vector<point> dir = {point{-1 ,0}, point{0, 1}, point{1, 0}, point{-1, 0}};

static void dfs(point p) {
  if (map[point]) return;
  map[point] = true;
  // PROCESS NODE HERE DEPENDING ON GIVEN PROBLEM
  for (auto &d : dir) {
    point new_point = point{p.x + d.x, p.y + d.y};
    dfs(new_point);
  }
}
