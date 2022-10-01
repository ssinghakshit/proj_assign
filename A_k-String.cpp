#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    unordered_map<char, int> um;
    string s;
    cin >> s;
    if (n == 1)
    {
        cout << s << endl;
        return;
    }
    for (auto it : s)
        um[it]++;
    for (auto it : um)
    {
        if (it.second % n != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    string ans = "";
    int t = n;
    while (n--)
    {
        for (auto &it : um)
        {
            int k = it.second;
            k = k / t;
            it.second -= k;
            while (k--)
            {
                ans += it.first;
            }
        }
        t--;
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