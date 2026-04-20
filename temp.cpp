#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int v){
        data=v;
        next=NULL;
    }
};
Node* ReverseinK(Node * head,int k){
    if(head==NULL) return head;
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    int cnt=0;
    while(curr!=NULL && cnt<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }
    if(next!=NULL) head->next=ReverseinK(next,k);
    return prev;
}

Node* reverseinKGroup(Node* head,int k){
    if(head==NULL) return head;
    Node* curr=head;
    Node* prevgroup=NULL;
    Node* nextgroup=NULL;
    int cnt=1;
    while(curr!=NULL && cnt<k)
    {
        curr=curr->next;
        cnt++;
    }
    if(curr==NULL) return head;
    nextgroup=curr->next;
    prevgroup->next=curr;
    
}