#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    string s;
    cin >> s;
    map<char, ll> mp;
    mp['1'] = 0;
    mp['2'] = 0;
    mp['3'] = 0;
    for (auto it : s)
    {
        if (it != '+')
            mp[it]++;
    }
    string ans = "";
    for (ll i = 0; i < mp['1']; i++)
    {
        ans += "1+";
    }
    for (ll i = 0; i < mp['2']; i++)
    {
        ans += "2+";
    }
    for (ll i = 0; i < mp['3']; i++)
    {
        ans += "3+";
    }
    ans.erase(ans.begin() + ans.length() - 1);
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