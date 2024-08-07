#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* random;
    
    Node(int val){
        this->val = val;
        this->next = nullptr;
        this->random = NULL;
    }
};


// O(n) Space
Node* copyRandomList(Node* head) {

    Node* dummy = new Node(0), *it = head, *prev = dummy;
    
    // creating copy list (w/o random ptrs)
    while(it){

        Node* curr = new Node(it->val);
        if(it->next) Node* nxt = new Node(it->next->val);
        curr->next = nxt;
        
        prev->next = curr;
        prev = curr;
        it = it->next;
    }

    // mapping old nodes to new nodes
    unordered_map<Node*,Node*> map;
    Node* a = head, *b = dummy->next;
    
    while(a){
        map[a] = b;
        a = a->next, b = b->next;
    }

    // making "random" connections
    a = head, b = dummy->next;
    while(a){
        b->random = map[a->random];
        a = a->next, b = b->next;
    }
    
    return dummy->next;
}