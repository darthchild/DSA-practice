/*
142. Linked List Cycle II
Medium
Given the head of a linked list, return the node where the cycle begins.
If there is no cycle, return null.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *detectCycle(ListNode *head) {

    ListNode *s = head, *f = head;

    while(f && f->next){
        s = s->next;
        f = f->next->next;
        if(f == s)
            break;
    }

    s = head;

    while(f && f->next){
        if(f == s)
            return f;
        s = s->next;
        f = f->next;   
    }
    return NULL;
}


// ALT WAY TO WRITE, STILL O(N)
ListNode *detectCycle(ListNode *head) {

    ListNode *s = head, *f = head;

    while(f && f->next){
        s = s->next;
        f = f->next->next;
        if(f == s){
            s = head;
            while(f && f->next){
                if(f == s)
                    return f;
                s = s->next;
                f = f->next;   
            }
        }          
    }
    return NULL;
}

/*
Even though it seems like there is a loop inside a loop, they are not nested in the traditional 
sense where the inner loop runs to completion for each iteration of the outer loop. Instead, 
<<< the loops are sequential >>>>

The first loop runs up to 
O(n) iterations to detect the cycle.
The second loop, after resetting the slow pointer, runs up to 

O(n) iterations to find the start of the cycle.
Each phase is linear, and the phases are consecutive, not nested. Therefore, the overall time complexity is 

O(n) + O(n) = O(n).
*/