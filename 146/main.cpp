#include "algorithm"
#include "iostream"
#include "stack"
#include "unordered_map"
#include "utility"
#include "vector"

using std::cout;
using std::deque;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::sort;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

struct Node
{
    int   val;
    Node *prev;
    Node *next;
    Node() {};
    Node(int x) : val(x) {};
};

class LRUCache
{
    unordered_map<int, Node> map;
    int                      cap;
    Node                     head;

  public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        auto kvp = map.find(key);
        if (kvp == map.end())
        {
            return -1;
        }
        Node temp              = head;
        kvp->second.prev->next = kvp->second.next;
        head                   = kvp->second;
        head.next              = temp.next;
        head.prev              = temp.prev;
        return kvp->second.val;
    }

    void put(int key, int value)
    {
        auto kvp = map.find(key);
        if (kvp == map.end())
        {
            return;
        }
    }
};

int main()
{
    LRUCache *sol = new LRUCache(2);
}
