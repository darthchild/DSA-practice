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


Node* insertBefHead(Node* head, int data){
    Node* x = new Node(data);

    head->back = x;
    x->next = head;
    head = x;
    return head;
}

Node* insertBefTail(Node* head, int data){
    Node* x = new Node(data);
    Node* it = head;

    while(it->next != NULL){
        it = it->next;
    }

    // now it = tail
    Node* prev = it->back;
    prev->next = x;
    x->back = prev;
    x->next = it;
    it->back = x;
    return head;
}



Node* insertBefKth(Node* head, int k, int data){
    Node* x = new Node(data);
    Node* it = head;
    int cnt = 0;

    while(it != NULL){
        cnt++;
        if(cnt == k) break;
        it = it->next;
    }
    Node* prev = it->back;
    prev->next = x;
    x->back = prev;
    x->next = it;
    it->back = x;
    return head;
}

/*

X <- 3 <-> 2 <-> 1 <-> 5 -> X

*/

void insertBefGivenNode(Node* node, int data){
    // assured: given node != head
    
    Node* x = new Node(data);
    Node * prev = node->back;

    prev->next = x;
    x->back = prev;

    node->back = x;
    x->next = node;
}

void insertAfterKth(Node *head, int k, int data){
   
    Node* x = new Node(data);
    Node* it = head;
    int cnt = 0;

    while(it != NULL){
        cnt++;
        if(cnt == k) break;
        it = it->next;
    }
    
    Node* nextNode = it->next;
    
    if(nextNode != NULL){
        x->back = it;
        it->next = x;
        x->next = nextNode;
        nextNode->back = x;
    } else {
        x->back = it;
        it->next = x;
    }
}


Node* deleteKthNode(Node* head, int k) {
    
    int cnt = 0;
    Node* it = head;
    
    while(it != NULL){
        cnt++;
        if(cnt == k) break;
        it = it->next;
    }
    
    Node* bef = it->back;
    Node* aft = it->next;
    
    
    if(aft == NULL && bef == NULL){
        delete it;
        return NULL;
        
    } else if(bef == NULL){
        it->next = NULL;
        it->back = NULL;
        aft->back = NULL;
        head = aft;
        delete it;
        return head;
        
    } else if(aft == NULL){
        it->back = NULL;
        bef->next = NULL;
        delete it;
        return head;
    }
    
    // normal case
    it->next = it->back = NULL;
    bef->next = aft;
    aft->back = bef;
    delete it;

    return head;
}

int main(){

    vector<int> arr = {3,2,1,5};
    Node* head = convertToDLL(arr);

    Node* node = head->next->next;

    insertBefGivenNode(node,4);
    printDLL(head);

    return 0;
}