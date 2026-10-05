class Node {
public:
int key;
int val;
Node* prev;
Node* next;

Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {};

};




class LRUCache {

private:

int capacity;
unordered_map<int, Node*> cache;
Node* lru;
Node* mru;

void remove(Node* node) {

    Node* next = node->next;
    Node* prev = node->prev;
    prev->next = next;
    next->prev = prev;

}
void insert(Node* node) {

    Node* prev = mru->prev;

    prev->next = node;
    node->prev = prev;
    node->next = mru;

    mru->prev = node;

}

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
        lru = new Node(0,0);
        mru = new Node(0,0);
        lru->next = mru;
        mru->prev = lru;
    }
    
    int get(int key) {

        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];

            remove(node);
            insert(node);

            return node->val;
        }

        return -1;

    }
    
    void put(int key, int value) {

        if(cache.find(key) != cache.end()) {
            remove(cache[key]);

        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if(cache.size() > this->capacity) {

            Node* lnode = lru->next;
            remove(lnode);

            cache.erase(lnode->key);

            delete lnode;

        }

        
    }
};
