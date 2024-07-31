
/*
19. Remove Nth Node From End of List
Medium
Given the head of a linked list, remove the nth node from the end 
of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]]

Input: head = [1,2], n = 1
Output: [1]
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    
    ListNode(int data){
        this->data = data;
        this->next = nullptr;
    }
};


// Optimal - using Slow & Fast pointers
ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode *f = head, *s = head;

    // give 'f' a headstart of 'n' nodes, such that when f
    // reaches the End, s will be at Nth node from end
    for (int i = 0; i < n; i++) {
        f = f->next;
    }

    if (!f) return head->next;

    // Here, when f reached the last node, s will reach
    // prev of Nth node (didn't take f till end, since we need
    // prev node in order to delete the Nth node)
    while (f->next){
        f = f->next;
        s = s->next;
    }
    s->next = s->next->next;

    return head;
}

// My Solution 
ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    if(!head || !head->next) return NULL;
    ListNode* it = head;
    int len = 0;
    while(it){
        len++;
        it = it->next;
    }

    if(len == n){
        head = head->next;
        return head;
    }

    int target = len-n, cnt = 0;
    it = head;
    
    while(it){
        cnt++;
        if(cnt == target){
            it->next = !it->next->next ? NULL : it->next->next; 
            break;
        }
        it = it->next;
    }
    return head;
}