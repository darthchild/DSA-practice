/*
2095. Delete the Middle Node of a Linked List
Medium
You are given the head of a linked list. Delete the middle node, 
and return the head of the modified linked list. In case of even lengthed 
lists, delete the 2nd middle element
*/

#include <bits/stdc++.h>
using namespace std;    

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// NAIVE SOLUTION, O(N)
ListNode* deleteMiddle(ListNode* head) {
    
    if(head->next == NULL) return NULL;
    ListNode *s = head, *f = head, *prev;

    while(f && f->next){
        if(f->next->next == NULL || f->next->next->next == NULL)
            prev = s;
        s = s->next;
        f = f->next->next;
    }

    // now S is the middle node
    prev->next = s->next;
    return head;
}


// SAME TC, BETTER LOGIC
ListNode* deleteMiddle(ListNode* head) {
    
    if(head->next == NULL) return NULL;

    ListNode *s = head, *f = head->next->next;

    while(f && f->next){
        s = s->next;
        f = f->next->next;
    }

    // now S is the mid-1 node (odd case)
    // or 1st mid (even case) -> basically previous to middle node (the one to be deleted)
    s->next = s->next->next;

    return head;

}