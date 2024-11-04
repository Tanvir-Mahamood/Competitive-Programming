//Longest Palindromic Substring
//O(n)

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

struct manacher
{
    vector<int> p;

    void run_manacher(string s)
    {
        cout << s << nn;
        int n = s.length();
        p.assign(n, 1);

        int l = 1, r = 1;

        for(int i=1; i<n; i++)
        {
            p[i] = max(0, min(r-i, p[l+r-i]));
            while(i+p[i] < n && i-p[i] >= 0 && s[i+p[i]] == s[i-p[i]])
            {
                p[i]++;
            }
            if(i+p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }
        for(auto v: p) cout << v << " ";
        cout << nn;
    }

    void build(string s)
    {
        string t;
        for(auto it: s)
        {
            t += string("#") + it;
        }
        run_manacher(t+"#");
    }

    //functions
    int getLongest(int cen, bool odd)
    {
        int pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }

    bool checkPalin(int l, int r)
    {
        if((r-l+1) <= getLongest((l+r)/2, l%2==r%2)) return 1;
        else return 0;
    }

}m;

void solve()
{
    string s; cin >> s;
    m.build(s);
    cout << m.getLongest(1,0) << nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t ; cin>>t; while(t--)
    solve();

    return 0;
}



