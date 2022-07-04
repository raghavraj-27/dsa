// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    // 5 4
    // 5 4 3
    // 0 9 3
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head) {
        Node* ptr = head;
        Node* prev = nullptr;
        while(ptr != nullptr) {
            Node* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        
        return prev;
    }
    Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        Node *dummy = new Node(0);
        Node *temp = dummy;
    
        int carry = 0;
        while(l1 != nullptr or l2 != nullptr or carry) {
            int sum = 0;
            if(l1 != nullptr) {
                sum += l1->data;
                l1 = l1->next;
            }
    
            if(l2 != nullptr) {
                sum += l2->data;
                l2 = l2->next;
            }
    
            sum += carry;
            carry = sum / 10;
            Node *node = new Node(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return reverse(dummy->next);
        // return dummy->next;
        // int carry = 0;
        // Node* prev = new Node(-1);
        // Node* dummy = prev;
        
        // while(first != nullptr or second != nullptr or carry) {
        //     int sum = 0;
            
        //     if(first != nullptr) {
        //         sum += first->data;
        //         first = first->next;
        //     }
            
        //     if(second != nullptr) {
        //         sum += second->data;
        //         second = second->next;
        //     }
            
        //     sum += carry;
        //     carry = sum / 10;
        //     Node* new_node = new Node(sum%10);
        //     prev->next = new_node;
        //     prev = prev->next;
        // }
        
        // return dummy->next;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends