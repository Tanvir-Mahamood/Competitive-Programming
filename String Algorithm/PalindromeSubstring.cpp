//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

string solve(string str)
{
    int n=str.length();
    int center,high,low,start=0,maxLength=1;
    for(center=1;center<n;center++)
    {
        low=center-1;
        high=center+1;
        while(low>=0 && high<n && str[low]==str[high])
        {
            if((high-low+1)>maxLength)
            {
                maxLength=high-low+1;
                start=low;
            }
            low--;
            high++;
        }

        low=center-1;
        high=center;
        while(low>=0 && high<n && str[low]==str[high])
        {
            if((high-low+1)>maxLength)
            {
                maxLength=high-low+1;
                start=low;
            }
            low--;
            high++;
        }
    }
    string res=str.substr(start,maxLength);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin>>str;
    string res=solve(str);
    cout<<res<<nn;

    return 0;
}


