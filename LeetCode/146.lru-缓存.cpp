
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */


#include <unordered_map>
using namespace std;
// @lc code=start
struct DLinkedNode
{
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
class LRUCache
{
private:
    int size ;
    int capacity;
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;

public:
    LRUCache(int capacity) : size(0), capacity(capacity)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
            return -1;
        moveToHead(cache[key]);
        return cache[key]->value;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            DLinkedNode *newNode = new DLinkedNode(key, value);
            cache[key]=newNode;
            addToHead(newNode);
            size++;
            if (size > capacity)
            {
                DLinkedNode* removed=removeTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        }
        else{
            cache[key]->value=value;
            moveToHead(cache[key]);
        }
    }
    void addToHead(DLinkedNode *node)
    {   
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev=node;
    }
    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node = nullptr;
    }
    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode* removeTail()
    {
        DLinkedNode* removed=tail->prev;
        removeNode(removed);
        return removed;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
