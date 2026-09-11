#include "algorithm"
#include "climits"
#include "iostream"
#include "stack"
#include "unordered_map"
#include "unordered_set"
#include "utility"
#include "vector"

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::sort;
using std::stack;
using std::string;
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Trie
{
    Trie *children[26];
    bool  is_leaf;

  public:
    Trie()
    {
        is_leaf = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }

    void insert(string word)
    {
        Trie *curr = this;
        for (char c : word)
        {
            if (curr->children[c - 'a'] == nullptr)
            {
                Trie *node              = new Trie();
                curr->children[c - 'a'] = node;
            }
            curr = curr->children[c - 'a'];
        }
        curr->is_leaf = true;
    }

    bool search(string word)
    {
        Trie *curr = this;
        for (char c : word)
        {
            if (curr->children[c - 'a'] == nullptr)
                return false;
            curr = curr->children[c - 'a'];
        }
        return curr->is_leaf;
    }

    bool startsWith(string prefix)
    {
        Trie *curr = this;
        for (char c : prefix)
        {
            if (curr->children[c - 'a'] == nullptr)
                return false;
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

int main()
{
    Trie *trie = new Trie();

    trie->insert("apple");
    bool ans = trie->search("apple"); // return True
    cout << ans << endl;
    ans = trie->search("app"); // return False
    cout << ans << endl;
    ans = trie->startsWith("app"); // return True
    cout << ans << endl;
    trie->insert("app");
    ans = trie->search("app"); // return True
    cout << ans << endl;
}

/**
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
