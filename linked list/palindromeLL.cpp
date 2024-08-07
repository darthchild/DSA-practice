#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
};


ListNode* reverse(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode* prev = NULL;
    ListNode* it = head;

    while (it != NULL) {
        ListNode* aft = it->next;
        it->next = prev;
        prev = it;
        it = aft;
    }
    return prev;
}


// OPTIMAL - O(1) Space
bool isPalindrome(ListNode* head) {
    if (!head == NULL || !head->next) return true;

    // Find the midpoint using s and f pointers
    ListNode* s = head, *f = head;

    while (f && f->next) {
        s = s->next;
        f = f->next->next;
    }

    // Reverse the second half of the list
    ListNode* p2 = reverse(s), *p1 = head;

    // Compare the first and second halves
    // (p1 - iterator for List's 1st half, p2 - iterator for 2nd half)
    while (p2 != NULL) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}


// Using Stack - O(n) space
bool isPalindrome(ListNode* head){
    stack<int> st;
    ListNode* it  = head;

    while(it){
        st.push(it->val);
        it = it->next;
    }

    it = head;
    while(it && it->val == st.top()){
        st.pop();
        it = it->next;
    }
    return st.empty();
}


// MY SOLUTION
bool isPalindrome(ListNode* head) {

    if(!head->next) return true;

    ListNode* newHead = reverse(head);
    ListNode* a = head, *b = newHead;
    int len = 0, cnt = 0;

    while(a){
        len++;
        a = a->next;
    }
    a = head;

    while(a && b){
        cout << a->val << " " << b->val;
        if(a->val == b->val)
            cnt++;
        a = a->next;
        b = b->next;
    }

    if(len == cnt)
        return true;
    return false;
}