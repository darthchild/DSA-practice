#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    // constructor
    ListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

ListNode* constructLLfromArray(vector<int>& a) {
    
    int n = a.size();
    ListNode* head = new ListNode(a[0]);
    ListNode* it = head;
    
    for(int i=1; i<n; i++){
        ListNode* curr = new ListNode(a[i]);
        it->next = curr;
        it = curr;
    }
    
    return head;   
}

void printLL(ListNode* head){
    ListNode* it = head;
    while(it != NULL){
        cout << it->data << " ";
        it = it->next;
    }
}


ListNode* reverse(ListNode* head){

    if(!head || !head->next) return head;
    ListNode* it = head, *aft, *prev = NULL;

    while(it){
        aft = it->next;
        it->next = prev;
        prev = it;
        it = aft;
    }
    return prev;
}

ListNode* rotateRight(ListNode* head, int k) {
        
    int cnt = 1, len = 0;
    ListNode* it = head, *rev, *newSec, *sec, *newHead;
    
    while(it) len++, it = it->next;

    k = k % len;
    if(k == 0) return head;
    
    rev = reverse(head);

    it = rev;
    while(it && cnt < k)
        cnt++, it = it->next;

    // sec is the head of remaining E list
    sec = it->next;
    it->next = NULL;

    //reversing 1st k E
    newHead = reverse(rev);

    //reversing remaning E
    newSec = reverse(sec);

    // rev - old head, new tail of 1st k elements LL
    // Now, JOIN the two lists
    rev->next = newSec;
    return newHead;

}

int main(){

    vector<int> arr = {1,2,3,4,5};
    ListNode* head = constructLLfromArray(arr);

    ListNode* x = rotateRight(head,3);
    printLL(x);

}
