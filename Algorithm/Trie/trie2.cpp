//Insert() = to insert a new string
//countWordsEqualTo() = to count the number of "word" present in the trie
//countWordsStartingWith() = to count the number of "prefix" present in the trie

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
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void decreaseEnd()
    {
        cntEndWith--;
    }
    void decreasePrefix()
    {
        cntPrefix--;
    }

    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPrefix;
    }
};
class Trie
{
private:
    Node * root;

public:
    Trie()
    {
        root = new Node();
    }

    void Insert(string word)
    {
        Node *node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }


    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void Erase(string &word)
    {
        Node *node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return;
            }
            node = node->get(word[i]);
            node->decreasePrefix();
        }
        node->decreaseEnd();
    }
};

int main()
{
    Trie T;
    T.Insert("apple");
    T.Insert("apple");
    T.Insert("apps");
    T.Insert("apps");
    string word1 = "apps";
    cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
    string word2 = "abc";
    cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
    string word3 = "ap";
    cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
        <<endl;
    string word4 = "appl";
    cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
        <<endl;
    T.Erase(word1);
    cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
    return 0;
}
