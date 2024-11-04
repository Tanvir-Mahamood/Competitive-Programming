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

//    void setEnd()
//    {
//        flag = true;
//    }
//    bool isEnd()
//    {
//        return flag;
//    }
};

//class Trie
//{
//
//private:
//    Node* root;
//
//public:
//    Trie()
//    {
//        root = new Node(); //creating new object
//    }
//
//    void Insert(string word) //O(len(word))
//    {
//        Node* node = root; //initializing empty node pointing to root initially
//        for(int i=0; i<word.size(); i++)
//        {
//            if(!node->ContainsKey(word[i]))
//            {
//                node->put(word[i], new Node());
//            }
//            node = node->get(word[i]); //Moves to the reference trie
//        }
//        node->setEnd();
//    }
//
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
//};

int countDistinctSubstrings(string &s)
{
    int cnt = 0;
    Node *root = new Node();

    for(int i=0; i<s.size(); i++) //starting character
    {
        Node *node = root;
        for(int j=i; j<s.size(); j++)
        {
            if(!node->ContainsKey(s[j]))
            {
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]); //Moves to the reference trie
        }
    }
    return (cnt + 1);
}

int main()
{
    string str;
    cin >> str;
    int result = countDistinctSubstrings(str);
    cout << result << nn;

    return 0;
}




