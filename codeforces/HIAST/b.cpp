#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    ll n, m, a; cin >> n >> m >> a;
    ll ans = 0;
    while (true) {
        ans++;
        n-=a;
        a*=2;
        if (a > m) break;
    }
    ans += n/a;
    cout << ans << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 0; t > tt; t++)
        solve(t);

    return 0;
}
