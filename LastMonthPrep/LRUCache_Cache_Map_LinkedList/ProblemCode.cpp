#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int value;
        node *next;
        node *prev;
        node(int k, int v)
        {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    int cap;
    unordered_map<int, node *> mp;
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);

    LRUCache(int capacity)
    {

        cap = capacity;
        // head = new node(-1, -1);
        // tail = new node(-1, -1);
        head->next = tail;
        tail->next = NULL;
        head->prev = NULL;
        tail->prev = head;
    }
    void addnode(node *temp)
    {
        node *Next = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = Next;
        mp[temp->key] = temp;
    }
    void deletenode(node *temp)
    {
        node *delPrev = temp->prev;
        node *delNext = temp->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        mp.erase(temp->key);
        delete temp;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            node *copy = new node(key, mp[key]->value);
            deletenode(mp[key]);
            addnode(copy);

            return mp[key]->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            deletenode(mp[key]);
            addnode(new node(key, value));
        }
        else
        {
            if (mp.size() != cap)
            {
                node *n = new node(key, value);
                addnode(n);
            }
            else
            {

                deletenode(tail->prev);
                node *n = new node(key, value);
                addnode(n);
            }
        }
    }
};

int main()
{

    return 0;
}
