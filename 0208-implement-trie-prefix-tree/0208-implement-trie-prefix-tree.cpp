struct Node {
    Node *link[26]; 
    bool flag; 
    
    Node() {
        for(int i=0; i<26; i++) {
            link[i] = NULL;
        }
        flag = false; 
    }
    
    bool isContainKey(int c)
    {
        return link[c] != NULL; 
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node(); 
    }
    
    void insert(string word) {
        Node* node = root; 
        for(int i=0; i<word.size(); i++) {
            if(!node->isContainKey(word[i] - 'a')) {
                // node->createKey(word[i]-'a', new Node()); 
                node->link[word[i]-'a'] = new Node(); 
            }
            node = node->link[word[i] - 'a']; 
        }
        
        node->flag = true; 
    }
    
    bool search(string word) {
        Node* node = root; 
        for(int i=0; i<word.size(); i++) {
            if(! node->isContainKey(word[i] - 'a'))
                return false; 
            node = node->link[word[i] - 'a']; 
        }
        
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        
        for(int i=0; i<prefix.size(); i++) {
            if(!node->isContainKey(prefix[i] - 'a'))
                return false;
            node = node->link[prefix[i] - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */