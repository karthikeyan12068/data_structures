#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
void push(Node **head_ref,int data)
{
    Node *new_node=new Node();
    new_node->data=data;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
    }
    else
    {
        Node *temp=*head_ref;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void reverse(Node **head_ref,int k)
{
    Node *prev=NULL,*curr=*head_ref,*nxt=NULL;
    while(curr!=NULL && k--)
    {
        nxt=curr->next;
        curr->next = prev;
        prev=curr;
        curr=nxt;
    }
    *head_ref=prev;
    Node *t1=*head_ref;
    while(t1->next!=NULL)
    {
        t1=t1->next;
    }
    t1->next=curr;
}
void print(Node **head_ref)
{
    Node *temp=*head_ref;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    int n;
    cin>>n;
    Node *head=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        push(&head,a);
    }
    int k;
    cin>>k;
    reverse(&head,k);
    print(&head);
    return 0;
}
