#include <iostream>
using namespace std;
class Node{
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
void dummy1(Node **head_ref1,Node **head_ref2,Node **head_ref3,int n1,int n2)
{
    Node *temp1=*head_ref1;
    Node *temp2=*head_ref2;
    Node *temp3=*head_ref3;
    while(temp1!=NULL && temp2!=NULL)
    {
        Node *new_node=new Node();
        if(temp1->data<temp2->data)
        {
            new_node->data=temp1->data;
            new_node->next=NULL;
            temp1=temp1->next;
            n1--;
        }
        else
        {
            new_node->data=temp2->data;
            new_node->next=NULL;
            temp2=temp2->next;
            n2--;
        }
        if(*head_ref3==NULL)
        {
            *head_ref3=new_node;
            temp3=*head_ref3;
        }
        else
        {
            temp3->next=new_node;
            temp3=new_node;
        }
    }
    if(n1>0)
    {
        while(temp1!=NULL)
        {
            Node *new_node=new Node();
            new_node->data=temp1->data;
            new_node->next=NULL;
            temp3->next=new_node;
            temp3=new_node;
            temp1=temp1->next;
        }
    }
    else
    {
        while(temp2!=NULL)
        {
            Node *new_node=new Node();
            new_node->data=temp2->data;
            new_node->next=NULL;
            temp3->next=new_node;
            temp3=new_node;
            temp2=temp2->next;
        }
    }
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
    //std::cout << "Hello, World!" << std::endl;
    Node *head1=NULL;
    Node *head2=NULL;
    Node *dummy=NULL;
    int n1;
    cin>>n1;
    int n2;
    cin>>n2;
    for(int i=0;i<n1;i++)
    {
        int a;
        cin>>a;
        append(&head1,a);
    }
    for(int i=0;i<n1;i++)
    {
        int a;
        cin>>a;
        append(&head2,a);
    }
    dummy1(&head1,&head2,&dummy,n1,n2);
    print(&dummy);
    return 0;
}
