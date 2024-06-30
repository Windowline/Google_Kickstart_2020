#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, K, P; //stack, paltes in each stack, plates to get

int dp(int st, int p, vector<vector<int>>& plates, vector<vector<int>>& d) {
    if (p == P)
        return 0;

    if (st == N)
        return -1e9;

    if (d[st][p] != -1)
        return d[st][p];

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < K && (p + i + 1) <= P; ++i) {
        sum += plates[st][i];
        int sub = dp(st + 1, p + i + 1, plates, d);
        if (sub > -1e9)
            ans = max(ans, sub + sum);
    }

    int sub = dp(st + 1, p, plates, d);
    if (sub > -1e9)
        ans = max(ans, sub);

    return d[st][p] = ans;
}

int solve(vector<vector<int>>& p) {
    int ans = 0;
    vector<vector<int>> d = vector<vector<int>>(N, vector<int>(N * K, -1));
    ans = dp(0, 0, p, d);
    return ans;
}


int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 0; tc < TC; ++tc) {
        scanf("%d %d %d", &N, &K, &P);
        vector<vector<int>> plates = vector<vector<int>>(N, vector<int>());
        for (int n = 0; n < N; ++n) {
            for (int k = 0; k < K; ++k) {
                int bv;
                scanf("%d", &bv);
                plates[n].push_back(bv);
            }
        }
        int ans = solve(plates);
        printf("Case #%d: %d\n", tc + 1, ans);
    }
}
