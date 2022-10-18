#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    string s1, s2;
    // unordered_set<char> set1;
    // unordered_set<char> set2;
    cin >> s1 >> s2;
    s1 = s1 + s2;
    cin >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 == s2)
        cout << "YES";
    else
        cout << "NO";
}
int main()
{
    float we;
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
