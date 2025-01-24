#include<bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  int value;
  shared_ptr<Node> prev;
  shared_ptr<Node> next;
};

class LRUCache {
 public:
  LRUCache(int capacity) : capacity(capacity) {
    join(head, tail);
  }

  int get(int key) {
    const auto it = keyToNode.find(key);
    if (it == keyToNode.cend())
      return -1;

    shared_ptr<Node> node = it->second;
    remove(node);
    moveToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    if (const auto it = keyToNode.find(key); it != keyToNode.cend()) {
      shared_ptr<Node> node = it->second;
      node->value = value;
      remove(node);
      moveToHead(node);
      return;
    }

    if (keyToNode.size() == capacity) {
      shared_ptr<Node> lastNode = tail->prev;
      keyToNode.erase(lastNode->key);
      remove(lastNode);
    }

    moveToHead(make_shared<Node>(key, value));
    keyToNode[key] = head->next;
  }

 private:
  const int capacity;
  unordered_map<int, shared_ptr<Node>> keyToNode;
  shared_ptr<Node> head = make_shared<Node>(-1, -1);
  shared_ptr<Node> tail = make_shared<Node>(-1, -1);

  void join(shared_ptr<Node> node1, shared_ptr<Node> node2) {
    node1->next = node2;
    node2->prev = node1;
  }

  void moveToHead(shared_ptr<Node> node) {
    join(node, head->next);
    join(head, node);
  }

  void remove(shared_ptr<Node> node) {
    join(node->prev, node->next);
  }
};

int main()
{
  LRUCache cache(2);

  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl; // returns 1
  cache.put(3, 3);                  // evicts key 2
  cout << cache.get(2) << endl; // returns -1 (not found)
  cache.put(4, 4);                  // evicts key 1
  cout << cache.get(1) << endl; // returns -1 (not found)
  cout << cache.get(3) << endl; // returns 3
  cout << cache.get(4) << endl; // returns 4
  return 0;
}