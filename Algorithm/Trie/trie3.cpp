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

//    bool Search(string word) //O(len(word))
//    {
//        Node* node = root;
//        for(int i=0; i<word.size(); i++)
//        {
//            if(!node->ContainsKey(word[i]))
//            {
//                return false;
//            }
//            node = node->get(word[i]);
//        }
//        return node->isEnd();
//    }
//
//    bool StartsWith(string word) //O(len(word))
//    {
//        Node* node = root;
//        for(int i=0; i<word.size(); i++)
//        {
//            if(!node->ContainsKey(word[i]))
//            {
//                return false;
//            }
//            node = node->get(word[i]);
//        }
//        return true;
//    }

    bool checkIfPrefixExist(string word)
    {
        bool fl = true;

        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->ContainsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
            if(node->isEnd() == false) return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> & a)
{
    Trie trie;
    for(auto &it: a)
    {
        trie.Insert(it);
    }
    string longest = "";

    for(auto &it: a)
    {
        if(trie.checkIfPrefixExist(it))
        {
            if(it.size() > longest.size())
            {
                longest = it;
            }
            else if(it.size() == longest.size() && it < longest)
            {
                longest = it;
            }
        }
    }

    if(longest == "") return "None";
    else return longest;
}

int main() {
    int n, i;
    cin >> n;
    vector<string> v(n);
    for(i=0; i<n; i++)
    {
        string str;
        cin >> str;
        v[i] = str;
    }
    string result = completeString(n, v);
    cout << result << nn;

    return 0;
}



