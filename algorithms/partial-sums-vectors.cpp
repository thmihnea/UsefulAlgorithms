#include <iostream>

using namespace std;
static int n, v[1001], s[1001];

static void compute_partial_sums() {
    s[1] = v[1];
    for (int i = 2; i <= n; i++) {
        s[i] = s[i-1] + v[i];
    }
}

static int get_sum_between(int start, int end) {
    return s[end] - s[start - 1];
}

int main(int argc, char* argv[]) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    compute_partial_sums();
    for (int i = 1; i <= n; i++)
        cout << s[i] << " ";
    cout << endl << get_sum_between(2, 6);
}
