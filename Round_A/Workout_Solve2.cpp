#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N, K;

// 최적화 문제로 푼다.
// 알아내고자 하는 답(difficulty)를 대입해보며, 최적의 답에 접근
// f(d): difficulty를 d로 정했을 때, 필요한 최소 세션수(<= K)
// difficulty란 각 diff들 사이에 세션 추가시 발생하는 가장 큰 수
// 목표로 하는 d가 낮을수록 --> f(d)는 커진다
// 목표로 하는 d가 높을수록 --> f(d)는 작아진다.
// 최적의 d를 찾기 위해서, 어떤 d를 정하여 f(d)의 값을 얻었을 때, 두가지 경우를 고려해볼 수 있다.
// 1. f(d)가 해의 영역일 때 (f(d) <= K):    더 좋은 답을 찾아본다. 즉, d를 낮춰도 좋을지 본다. (f(d)를 조금 키워도 괜찮을지 살핀다.)
// 2. f(d)가 해의 영역일 밖일 때 (f(d) > K): 해의 영역안에 들어갈 수 있도록 d를 높힌다. (f(d)를 작게 한다.)
// 최적의 답이 나올 때까지 d를 내릴 것이냐 올릴 것이냐 선택. --> 이분탐색. 시간복잡도는 O(log(1e9) * N) => O(N)
bool ok(vector<int>& diffs, int d) { //f(d)가 해의 영역인지?
    int fd = 0;
    for (int dd : diffs) {
        if (dd > d) {
            fd += dd / d - 1;
            if (dd % d != 0)
                fd += 1;
        }
    }
    return fd <= K;
}

int solve(vector<int>& mini) {
    vector<int> diffs;
    diffs.reserve(mini.size() - 1);
    for (int i = 0; i < mini.size() - 1; ++i) {
        diffs.push_back(mini[i+1] - mini[i]);
    }

    int R = 1e9;
    int L = 1;
    int ans = 1e9;

    while (L < R) {
        int M = (R + L) / 2;
        if (ok(diffs, M)) {
            ans = min(ans, M);
            R = M;
        } else {
            L = M + 1;
        }
    }

    return ans;
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
