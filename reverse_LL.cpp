#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void append(Node **head_ref,int data)
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
        Node *t=*head_ref;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=new_node;
    }
}
void reverse(Node **head_ref)
{
    Node *prev=NULL,*curr = *head_ref,*next=NULL;
    {
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        *head_ref=prev;
    }
}
void print(Node **head_ref)
{
    Node *t=*head_ref;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<"\n";
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Node *head=NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    print(&head);
    reverse(&head);
    print(&head);
    return 0;
}
