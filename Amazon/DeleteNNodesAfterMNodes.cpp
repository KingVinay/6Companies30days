#include<bits/stdc++.h>
using namespace std;

Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node *first = head, *second; 
        
        while(first != NULL){
            for (int i = 1; i < m && first!= NULL; i++) 
                first = first->next; 
    
            
            if (first == NULL) 
                return head; 
    
            
            second = first->next; 
            for (int i = 1; i <= n && second!= NULL; i++) { 
                Node *temp = second; 
                second = second->next; 
                delete(temp); 
            } 
            
            first->next = second;
            first = second;
        }
        return head;
    }

int main()
{
   Node* head = new Node(1);
   head->next = new Node(2);
   head->next->next = new Node(3);
   head->next->next->next = new Node(4);
   head->next->next->next->next = new Node(5);
   head->next->next->next->next->next = new Node(6);

   int n = 2, m = 3;
   head = linkdelete(head, n, m);
   printList(head);
   return 0;
}