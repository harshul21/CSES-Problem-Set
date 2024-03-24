#include <iostream>
using namespace std;

typedef long long ll;

ll TwoKnights(int K)
{
    ll total_ways = ((ll)K * K * (K * K - 1)) / 2;
    ll attacking_ways = 4LL * (K - 1) * (K - 2);
    ll ans = total_ways - attacking_ways;

    return ans;
}

int main()
{
    int N;
    cin >> N;
    for (int K = 1; K <= N; K++) {
        cout << TwoKnights(K) << endl;
    }

    return 0;
}
