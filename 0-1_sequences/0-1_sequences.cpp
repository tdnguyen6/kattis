#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int count_inversion(string s)
{
    int cur_non_0 = 0, n_inversion = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            n_inversion += i - cur_non_0;
            cur_non_0++;
        }
    }
    return n_inversion;
}

void solve()
{
    using std::map;
    string s;
    cin >> s;
    ll sum = 0;

    map<int, char> unknown_pos;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '?')
        {
            unknown_pos[i] = '0';
        }
    }

    int n_s = pow(2, unknown_pos.size());
    auto it = unknown_pos.begin();

    for (int i = 0; i < n_s; i++)
    {
        string permutation = s;

        for (auto p : unknown_pos)
            permutation[p.first] = p.second;

        sum += count_inversion(permutation);

        if (i < n_s - 1)
        {
            if (it->second == '0')
            {
                it->second = '1';
            }
            else
            {
                while (it->second == '1' && it != unknown_pos.end())
                {
                    it++;
                }
                it->second = '1';
                while (it != unknown_pos.begin())
                {
                    --it;
                    it->second = '0';
                }
            }
        }
    }

    cout << sum % MOD << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        solve();
    }
}
