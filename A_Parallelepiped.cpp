#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 4 * (sqrt((a * b) / float(c)) + sqrt((a * c) / float(b)) + sqrt((c * b) / float(a)));
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