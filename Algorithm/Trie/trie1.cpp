//Insert() = to insert a new string
//Search() = to check if "word" is present in the trie or not
//StartsWith() = to check if there is any string in trie that starts with the given prefix

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

struct Node
{
    Node *links[26];
    bool flag = false;

    bool ContainsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{

private:
    Node* root;

public:
    Trie()
    {
        root = new Node(); //creating new object
    }

    void Insert(string word) //O(len(word))
    {
        Node* node = root; //initializing empty node pointing to root initially
        for(int i=0; i<word.size(); i++)
        {
            if(!node->ContainsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]); //Moves to the reference trie
        }
        node->setEnd();
    }

    bool Search(string word) //O(len(word))
    {
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->ContainsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool StartsWith(string word) //O(len(word))
    {
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->ContainsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};

void solve()
{
    int n, i, val;
    cin >> n;
    Trie trie;
    while(n--)
    {
        string str;
        cin >> val >> str;

        if(val == 1) trie.Insert(str);
        else if(val == 2) (trie.Search(str)) ?     cout << "true\n" : cout << "false\n";
        else if(val == 3) (trie.StartsWith(str)) ? cout << "true\n" : cout << "false\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}



