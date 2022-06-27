class LRUCache {
public:
    class Node {
        public:
        int key, value;
        Node *next, *prev;
        
        Node(int _key, int _value) {
            key = _key;
            value = _value;
        }
    };
    
    int cap;
    Node *head, *tail;
    map<int, Node*> mp;
    int size;
    
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1); 
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(Node* new_node) {
        Node *temp = head->next;
        head->next = new_node;
        new_node->prev = head;
        temp->prev = new_node;
        new_node->next = temp;
    }
    
    void deletenode(Node* del_node) {
        Node* left = del_node->prev;
        Node* right = del_node->next;
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* resnode = mp[key];
            int res = resnode->value;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            deletenode(mp[key]);
            mp.erase(key);
        }
        
        if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        Node* new_node = new Node(key, value);
        addnode(new_node);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */