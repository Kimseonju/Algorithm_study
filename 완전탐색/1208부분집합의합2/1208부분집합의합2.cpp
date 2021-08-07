#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, S;
int main()
{
    cin >> N >> S;

    vector<int>v(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

	int M = N / 2; 
	N = N - M;
	vector<int> first(1 << N);

    for (int i = 0; i < (1 <<N); i++) {
        for (int k = 0; k < N; k++) {
            if (i & (1 << k)) {
                first[i] += v[k];
            }
        }
    }
    vector<int> second(1 << M);

    for (int i = 0; i < (1 << M); i++) {
        for (int k = 0; k < M; k++) {
            if (i & (1 << k)) {
                second[i] += v[k + N];
            }
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    reverse(second.begin(), second.end());


    int ifirst=0;
    int isecond=0;

    long long ans = 0;
    while (ifirst < first.size() && isecond <second.size())
    {
        if (first[ifirst] + second[isecond] == S) {
            long long numfirst = 1;
            long long numsecond = 1;
            ifirst += 1;
            isecond += 1;
            while (ifirst < first.size() && first[ifirst] == first[ifirst - 1]) {
                numfirst += 1;
                ifirst += 1;
            }
            while (isecond < second.size() && second[isecond] == second[isecond - 1]) {
                numsecond += 1;
                isecond += 1;
            }
            ans += numfirst * numsecond;
        }
        else if (first[isecond] + second[isecond] < S) {
            ifirst += 1;
        }
        else {
            isecond += 1;
        }
    }
    if (S == 0)
        ans -= 1;

    cout << ans << '\n';
    return 0;


}
