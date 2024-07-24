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

Node* reverse(Node* head){

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    
    Node* prev = NULL, *it = head;

    while(it != NULL){
        Node* aft = it->next;
        it->next = prev;
        prev = it;
        it = aft;
    }
    head = prev;
    return head;
}

Node* convertToLL(vector<int> a){
    
    int n = a.size();
    Node* head = new Node(a[0]);
    Node* prev = head;

    for(int i=1; i<n; i++){
        Node* it = new Node(a[i]);
        prev->next = it;
        prev = it;
    }
    prev->next = NULL;
    return head;
}
void printLL(Node* head){
    Node* it = head;
    while(it != NULL){
        cout << it->data << " ";
        it = it->next;
    }
}


int main(){
    vector<int> arr = {3,2,1,5};
    Node* head = convertToLL(arr);

    Node* n = reverse(head);
    printLL(n);

}

