
/*
160. Intersection of Two Linked Lists
Easy
Given the heads of two singly linked-lists headA and headB, return the node at 
which the two lists intersect. If the two linked lists have no intersection at
all, return null.
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


// APPROACH-1
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    ListNode *a = headA, *b = headB;
    if(!a || !b) return NULL;

    while(a && b && a != b){
        a = a->next;
        b = b->next;

        if(a == b) return a;

        if(!a) a = headB;
        if(!b) b = headA;
    }

    return a;
} 

// APPROACH-2
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    ListNode* it = headA, *head = headA;

    while(it->next)
        it = it->next;

    // now it = tail, make the loop!
    it->next = headB;

    // Now just find the starting point of the loop 
    ListNode* s = head, *f = head;
    while(f && f->next){
        s = s->next;
        f = f->next->next;
        if(s == f){
            s = head;
            // s & f are now equidistant from Loop starting pt
            // next time they meet it'll be at that pt
            while(s != f){
                s = s->next;
                f = f->next;
            }
            // undo the link & return the meeting pt of s & f
            it->next = NULL;
            return s;
        }
    }

    it->next = NULL;
    return NULL;
} 


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    ListNode* it = headA, *head = headA;

    while(it->next)
        it = it->next;

    // now it = tail, make the loop!
    it->next = headB;

    // Now just find the starting point of the loop 
    ListNode* s = head, *f = head;
    while(f && f->next){
        s = s->next;
        f = f->next->next;
        if(s == f){
            s = head;
            // s & f are now equidistant from Loop starting pt
            // next time they meet it'll be at that pt
            while(s != f){
                s = s->next;
                f = f->next;
            }
            // undo the link & return the meeting pt of s & f
            it->next = NULL;
            return s;
        }
    }

    it->next = NULL;
    return NULL;
}   