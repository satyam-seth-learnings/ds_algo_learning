#include<bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(int key) : key(key) {};
};

class DoubleLinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* append(int key) {
        // append to linked list
        Node* n = new Node(key);
        // if tail is null then head should be null so just set both to a new Node
        if(!tail) {
            head = tail = n;
        }
        // else if tail is not null so point tail to new node and set tail to be n
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        return n;
    }
    void moveToEnd(Node* n) {
        assert(head != nullptr && tail != nullptr);
        if(n == tail) return;
        if(n == head) {
            tail->next = n;
            n->prev = tail;
            tail = n;
            head = n->next;
            n->next = nullptr;
        } else { // in between
            n->prev->next = n->next;
            n->next->prev = n->prev;
            tail->next = n;
            n->prev = tail;
            tail = n;
            n->next = nullptr;
        }
    }
    // deletes the head. head is now second element 
    // returns key of head
    int deleteHead() {
        assert(head != nullptr);
        Node* newHead = head->next;
        int delKey = head->key;
        delete head;
        head = newHead;
        return delKey;
    } 
};

class LRUCache {
private:
    DoubleLinkedList dll;
    unordered_map<int,pair<int, Node*>> m;
    int capacity;
public:
    LRUCache(int _capacity) {
        assert(_capacity > 0);
        capacity = _capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()) return -1;
        dll.moveToEnd(it->second.second);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = m.find(key); 
        if(it == m.end()) {
            Node* n = dll.append(key);
            m[key] = {value, n};
            // if size of map exceeds capacity erase lru item from map and dll 
            if(m.size() > capacity) m.erase(dll.deleteHead());
        } else {
            it->second.first = value;
            dll.moveToEnd(it->second.second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    // https://leetcode.com/problems/lru-cache/
    return 0;
}