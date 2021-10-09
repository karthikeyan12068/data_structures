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
        Node *temp=*head_ref;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void swap(Node **headref,int v1,int v2)
{
    Node *t1=*headref,*t2=*headref,*t3=*headref,*t4=*headref;
    int id1=0,id2=0;
    while(t1->data!=v1)
    {
        t3=t1;
        t1=t1->next;
        id1++;
    }
    t3->next=t1->next;
    delete t1;
    while(t2->data!=v2)
    {
        t4=t2;
        t2=t2->next;
        id2++;
    }
    id2++;
    t4->next=t2->next;
    delete t2;
    Node *t5=*headref,*t6=*headref,*t7=*headref,*t8=*headref;
    Node *new_node1=new Node();
    Node *new_node2=new Node();
    while(id1--)
    {
        t6=t5;
        t5=t5->next;
    }
    new_node1->data=v2;
    new_node1->next=t6->next;
    t6->next=new_node1;
    while(id2--)
    {
        t8=t7;
        t7=t7->next;
    }
    new_node2->data=v1;
    new_node2->next=t8->next;
    t8->next=new_node2;
}
void print(Node** head_ref)
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
    Node *head=NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    append(&head,6);
    print(&head);
    swap(&head,3,6);
    print(&head);
    return 0;
}
