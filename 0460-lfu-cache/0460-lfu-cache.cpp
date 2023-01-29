struct Node {
    int key, value, cnt; 
    Node* next; 
    Node* prev; 
    
    Node(int k, int v) {
        key = k; 
        value = v; 
        cnt = 1;
    }
};

class List {
    public:
    Node* head; 
    Node* tail; 
    int size;
    
    List() {
        head = new Node(-1, -1); 
        tail = new Node(-1, -1);
        head->next = tail; 
        tail->prev = head;
        size = 0; 
    }
    
    void addnode(Node* new_node) {
        Node* temp = head->next;
        new_node->next = temp; 
        new_node->prev = head; 
        temp->prev = new_node; 
        head->next = new_node;
        size++; 
    }
    
    void deletenode(Node* old_node) {
        Node* left = old_node->prev; 
        Node* right = old_node->next; 
        left->next = right; 
        right->prev = left; 
        size--;
    }
};

class LFUCache {
public:
    unordered_map<int, List*> freq_list; 
    unordered_map<int, Node*> key_node; 
    int maxsize, currsize, minfreq;
    
    LFUCache(int capacity) {
        maxsize = capacity; 
        currsize = 0; 
        minfreq = 0;
    }
    
    void updateFreqList(Node* node) 
    {
        int currnodefreq = node->cnt; 
        key_node.erase(node->key);
        List* currnodelist = freq_list[currnodefreq]; 
        currnodelist->deletenode(node); 
        
        if(currnodefreq == minfreq and freq_list[minfreq]->size == 0) {
            minfreq++;
        }
        
        List* nextHigherFreqList = new List(); 
        
        if(freq_list.find(currnodefreq + 1) != freq_list.end()) {
            nextHigherFreqList = freq_list[currnodefreq + 1];
        }
        
        // Node* new_node = new Node(key, value); 
        node->cnt++; 
        nextHigherFreqList->addnode(node); 
        freq_list[node->cnt] = nextHigherFreqList; 
        key_node[node->key] = node;
    }
    
    int get(int key) {
        if(key_node.find(key) != key_node.end()) {
            Node* node = key_node[key]; 
            int val = node->value; 
            updateFreqList(node); 
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsize == 0) {
            return; 
        }
        
        if(key_node.find(key) != key_node.end()) {
            Node* node = key_node[key]; 
            node->value = value; 
            updateFreqList(node); 
            return;
        }
        else {
            if(currsize == maxsize) {
                List *list = freq_list[minfreq]; 
                key_node.erase(list->tail->prev->key); 
                list->deletenode(list->tail->prev);
                currsize--;
            }
            currsize++; 
            minfreq = 1; 
            List* new_list = new List(); 
            
            if(freq_list.find(minfreq) != freq_list.end()) {
                new_list = freq_list[minfreq]; 
            }
            
            Node* new_node = new Node(key, value); 
            
            new_list->addnode(new_node); 
            key_node[key] = new_node;
            freq_list[minfreq] = new_list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */