#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    ll ans = 0;
    for (ll a = 1; a <= d; a++)
    {
        if (a % k == 0 || a % l == 0 || a % m == 0 || a % n == 0)
            ans++;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    solve();

    // ll t;
    // cin >> t;
    // while(t--)
    // {
    //     solve();
    // }
    return 0;
}

/*
ulimit -s unlimited
g++ solution.cpp -o solution
./solution
*/

/*
g++ -Wl,--stack,1073741824 solution.cpp -o solution
./solution < input.txt > output.txt
*/