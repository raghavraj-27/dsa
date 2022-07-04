// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node *slow = head, *fast = head;
        while(fast->next != nullptr and fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node *prev = nullptr;
        Node *ptr = slow->next;
        while(ptr != nullptr) {
            Node* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        // ptr->next = slow;
        
        Node *ptr1 = head, *ptr2 = prev;
        while(ptr2 != nullptr) {
            if(ptr1->data != ptr2->data) return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends