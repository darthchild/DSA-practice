#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
};

// Single Pass Soln (reversing the links)
Node* reverseDLL1(Node* head){

    Node* prev = NULL;
    Node* it = head;

    while(it != NULL){
        prev = it->back;
        it->back = it->next;
        it->next = prev;
        it = it->back;
    }

    head = prev->back;
    return head;
}

Node* reverseDLL2(Node* head){
    
    Node* prev,*aft, *it = head;
    
    while(it != NULL){
        prev = it->back;
        aft = it->next;
        
        it->next = prev;
        it->back = aft;

        it = it->next;
    }
    head = prev->back;
    return head;
}


Node* convertToDLL(vector<int> a){
    
    int n = a.size();
    Node* head = new Node(a[0]);
    Node* prev = head;

    for(int i=1; i<n; i++){
        Node* it = new Node(a[i]);
        prev->next = it;
        it->back = prev;
        prev = it;
    }
    return head;
}
void printDLL(Node* head){
    Node* it = head;
    while(it != NULL){
        cout << it->data << " ";
        it = it->next;
    }
}


int main(){
    vector<int> arr = {3,2,1,5};
    Node* head = convertToDLL(arr);

    Node* newHead = reverseDLL1(head);
    printDLL(newHead);
}