/*
Sort a linked list of 0s, 1s and 2
GFG Easy 
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to 
head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

// APPROACH - 1
Node* segregate(struct Node *head) {
        
    if (!head || !head->next) return head;
    
    //creating three dummy nodes to point to beginning of three linked lists. 
    Node* dum0 = new Node(0), *dum1 = new Node(0), *dum2 = new Node(0); 
    //initializing iterators for three lists.
    Node* zero = dum0, *one = dum1, *two = dum2; 
    
    Node* it = head; 
    
    while (it) { 
        if (it->data == 0) { 
            zero->next = it, zero = it;
        }
        else if (it->data == 1) { 
            one->next = it; 
            one = it; 
        } 
        else { 
            two->next = it; 
            two = it; 
        }
        it = it->next; 
    } 
    
    //attaching the three lists containing 0s,1s and 2s respectively.
    zero->next = dum1->next ? dum1->next : dum2->next; 
    one->next = dum2->next; 
    two->next = NULL; 
    //updating the head of the list.
    head = dum0->next; 
    return head;
}

// APPROACH - 2
Node* segregate(Node *head) {
    
    int count[3] = {0, 0, 0}; // To count 0s, 1s, and 2s
    Node* it = head;

    // Count the occurrences of 0s, 1s, and 2s
    while (it != NULL) {
        count[it->data]++;
        it = it->next;
    }

    int i = 0;
    it = head;

    // Update the list with sorted data
    while (it != NULL) {
        if (count[i] == 0)
            i++;
        else {
            it->data = i;
            count[i]--;
            it = it->next;
        }
    }
    
    return head;
}







// APPROACH - 3
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size()-1;
    while(mid <= high){

        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++, mid++;
        } else if(nums[mid] == 1){
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
Node* arrayToLL(vector<int>& a) {
    
    int n = a.size();
    Node* head = new Node(a[0]);
    Node* it = head;
    
    for(int i=1; i<n; i++){
        Node* curr = new Node(a[i]);
        it->next = curr;
        it = curr;
    }
    
    return head;   
}
vector<int> LLtoArray(Node* head){
    vector<int> arr;
    
    Node* it = head;
    while(it){
        arr.push_back(it->data);
        it = it->next;
    }
    return arr;
}

//Function to sort a linked list of 0s, 1s and 2s.
Node* segregate(Node *head) {
    
    vector<int> arr = LLtoArray(head);
    sortColors(arr);
    head = arrayToLL(arr);
    return head;
}