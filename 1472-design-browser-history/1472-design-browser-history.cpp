class Node {
    public:
    Node* prev, *next;
    string val;
    Node(string _val) {
        this->val = _val;
        this->prev = nullptr;
        this->next = nullptr;
    }
    Node(string _val, Node* _prev, Node* _next) {
        this->prev = _prev;
        this->next = _next;
        this->val = _val;
    }
};
class BrowserHistory {
public:
    int i;
    Node* head = new Node("");
    Node* ptr;
    BrowserHistory(string homepage) {
        head->val = homepage;
        ptr = head;
    }
    
    void visit(string url) {
        ptr->next = new Node(url, ptr, nullptr);
        ptr = ptr->next;
    }
    
    string back(int steps) {
        while(steps-- and ptr->prev != nullptr) {
            ptr = ptr->prev;
        }
        return ptr->val;
    }
    
    string forward(int steps) {
        while(steps-- and ptr->next != nullptr) {
            ptr = ptr->next;
        }
        return ptr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */