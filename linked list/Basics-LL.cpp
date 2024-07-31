#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


Node* insertAtEnd(Node* head, int x) {
    
    Node* last = new Node(x);
    
    if(head == nullptr)
        return last;
    
    // S1: Find last node
    
    Node* it = head;
    while(it->next != nullptr){
        it = it->next; 
    }
    
    // Now "it" is last Node
    
    
    it->next = last;
    
    return head;
}

Node* constructLLfromArray(vector<int>& a) {
    
    int n = a.size();
    Node* head = new Node(a[0]);
    Node* it = head;
    
    for(int i=1; i<n; i++){
        Node* curr = new Node(a[i]);
        it->next = curr;
        it = curr;
    }
    
    return head;   
}


bool searchInLL(int n, struct Node* head, int key) {
    
    Node* it = head;
    
    while(it){
        if(it->data == key)
            return 1;
        it = it->next;
    }
    
    return 0; 
}

// Function to count nodes of a linked list.
int getCount(struct Node* head) {

    Node* it = head;
    int cnt = 0;
    
    while(it->next != NULL){
        cnt++;
        it = it->next;
    }
    
    return cnt+1; 
}
int main(){

    Node* x = new Node(4);
    Node* y = new Node(5);
    x->next = y;
    
    
    //priting LL

    Node* head = x;
    Node* it = head;

    while(it){
        cout<< it->data << " ";
        it = it->next;
    }
    if(it == NULL)
        cout << "NULL";

}