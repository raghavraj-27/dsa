struct Node {
    Node* links[26];
    bool flag;
    Node() { 
        for(int i=0; i<26; i++)
            links[i] = NULL;
        flag = false; 
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            int ch = word[i] - 'a';
            if(node->links[ch] == NULL)
                node->links[ch] = new Node();
            node = node->links[ch];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        return mysearch(word, root);
    }
    
    bool mysearch(string word, Node* node) {
        for(int i=0; i<word.size(); i++) {
            if(word[i] != '.') {
                int ch = word[i] - 'a';
                if(node->links[ch] != NULL)
                    node = node->links[ch];
                else
                    return false;
            } else {
                for(int j=0; j<26; j++) {
                    if(node->links[j] != NULL) {
                        if(mysearch(word.substr(i+1), node->links[j]))
                            return true;
                    }
                }
                return false;
            }
        }
        return node->flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */