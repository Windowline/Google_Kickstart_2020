#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct Info {
    int d;
    int org;
    int divCnt;
    bool operator<(const Info& other) const {
        return this->d < other.d;
    }
};

int N, K;
int solve(vector<int>& mini) {
    priority_queue<Info, vector<Info>> pq;

    for (int i = 0; i < mini.size() - 1; ++i) {
        auto d = mini[i+1] - mini[i];
        pq.push({d, d, 1});
    }

    for (int k = 0; k < K; ++k) {
        auto top = pq.top();
        pq.pop();

        int divCnt = top.divCnt + 1;
        int m = top.org % divCnt ? 1 : 0;
        pq.push({top.org / divCnt + m, top.org, divCnt});
    }

    return pq.top().d;
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 0; tc < TC; ++tc) {
        scanf("%d %d", &N, &K);
        vector<int> mini = vector<int>(N);
        for (int n = 0; n < N; ++n)
            scanf("%d", &mini[n]);
        printf("Case #%d: %d\n", tc + 1, solve(mini));
    }
}