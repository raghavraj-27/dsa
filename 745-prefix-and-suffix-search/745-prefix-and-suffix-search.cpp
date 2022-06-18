struct Node {
    Node* links[27];
    int index;
    bool endOfWord;
    
    Node() {
        for(int i=0; i<27; i++) links[i] = NULL;
        index = -1;
    }
};

class Trie {
public:
    Node* root; 
    Trie() {
        root = new Node();
    }
    
    void insert(string word, int i) {
        Node* node = root;
        for(char ch : word) {
            if(node->links[ch-'a'] == nullptr) {
                node->links[ch-'a'] = new Node();
            }
            node = node->links[ch-'a'];
            node->index = i;
        }
    }
    
    int search(string word) {
        Node* node = root;
        for(char ch : word) {
            if(node->links[ch-'a'] == nullptr) {
                node->links[ch-'a'] = new Node();
            }
            node = node->links[ch-'a'];
        }
        return node->index;
    }
};

class WordFilter {
public:
    Trie trie;
    WordFilter(vector<string>& words) {
        int idx = 0;
        string s = "";
        
        for(auto &word : words) {
            s = "{" + word;
            trie.insert(s, idx);
            
            for(int i=word.size()-1; i>=0; i--) {
                s = word[i] + s;
                trie.insert(s, idx);
            }
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        string str = suffix + "{" + prefix;
        return trie.search(str);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */