/*
Find length of Loop (GFG)
Easy

Given a linked list of size N. The task is to complete the function
that checks whether a given Linked List contains a loop or not and if the loop is present 
then return the count of nodes in a loop or else return 0
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};


int countNodesinLoop(struct Node *head)
{
    Node* s = head, *f = head;
    
    while(f && f->next){
        s = s ->next;
        f = f->next->next;
        
        if(s == f){          // If True => loop present
            s = s->next;
            int len = 0;
            
            while(s!=f){
                len++;
                s = s->next;
            }
            return len+1;
        }
    }
    
    return 0;
}