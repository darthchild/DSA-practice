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


// MY SOLUTION
ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {

    ListNode* it = h1, *x, *y, *head;
    int len1 = 0, len2 = 0, carry = 0;

    while(it)
        len1++, it = it->next;
    it = h2;
    while(it)
        len2++, it = it->next;

    // y - larger num, x - smaller num
    if(len1 >= len2)
        y = h1, x = h2, head = h1;
    else 
        y = h2, x = h1, head = h2;

    while(x){
        
        int sum = x->val + y->val + carry;

        if(sum > 9){ 
            y->val = sum - 10, carry = 1;
            if( !x->next && !y->next){
                y->next = new ListNode(1);
                return head;
            } 
        } else 
            y->val = sum, carry = 0;

        y = y->next;
        x = x->next;
    }


    while(y){
        int sum = y->val + carry;

        if(sum > 9){
            y->val = 0, carry = 1;
            if(!y->next){
                y->next = new ListNode(1);
                return head;
            }
        } else {
            y->val = sum, carry = 0;
        }
        y = y->next;
    }
    return head;
}
