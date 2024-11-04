#include <bits/stdc++.h>
using namespace std;

vector<int> lps_creator(string pattern)
{
    vector<int> lps(pattern.size());
    int index=0,j;
    for(j=1; j<pattern.size(); ) //never j++
    {
        if(pattern[index]==pattern[j])
        {
            lps[j]=index+1;
            index++;
            j++;
        }
        else
        {
            if(index != 0) index=lps[index-1];
            else lps[j]=index;
            j++;
        }
    }
    return lps;
}


void kmp(string text,string pattern)
{
    int flag=0;
    vector<int> lps=lps_creator(pattern);
    int i=0,j=0; // i for text and j for pattern
    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0) j=lps[j-1];
            else i++;
        }

        if(j==pattern.size())
        {
            cout<<"Found\n";
            flag=1;
            //break;
            cout<<"Index: "<<(i-pattern.size())<<"\n";
            j=lps[j-1];
        }
    }
    if(!flag) cout<<"Not found\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string pattern,text;
    getline(cin,text);
    getline(cin,pattern);

    kmp(text,pattern);

    return 0;
}


