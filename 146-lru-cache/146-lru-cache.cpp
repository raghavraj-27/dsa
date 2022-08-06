class Node {
public: 
    int value, key;
    Node* next, *prev;
    Node(int _key, int _val) {
        key = _key;
        value = _val;
        next = nullptr;
        prev = nullptr;
    }
    
    
};

class LRUCache {
public:
    Node* head, *tail;
    int maxSize;
    // key->node
    unordered_map<int, Node*> keyToNode;
    // key->value
    // map<int, int> keyToVal;
    void addnode(Node* node) {
        Node* nextptr = head->next;
        
        node->next = nextptr;
        node->prev = head;
        head->next = node;
        nextptr->prev = node;
    }
    
    void deletenode(Node* node) {
        Node* prevnode = node->prev;
        Node* nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        
        // delete(node);
    }
    
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        maxSize = capacity;
    }
    
    int get(int key) {
        if(keyToNode.find(key) != keyToNode.end()) {
            Node* node = keyToNode[key];
            int val = node->value;
            deletenode(node);
            // keyToNode.erase(key);
            Node* new_node = new Node(key, val);
            addnode(new_node);
            keyToNode[key] = new_node;
            
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyToNode.find(key) != keyToNode.end()) {
            deletenode(keyToNode[key]);
            keyToNode.erase(key);
        }
        
        if(keyToNode.size() == maxSize) {
            keyToNode.erase(tail->prev->key);
            deletenode(tail->prev);
            
        }
        Node* new_node = new Node(key, value);
        keyToNode[key] = new_node;
        addnode(new_node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */