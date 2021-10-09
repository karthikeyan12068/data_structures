#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
void push(Node **head_ref,int d)// to add at the front
{
    Node *new_node=new Node();
    new_node->data=d;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

/* steps to be followed
 * 1.make a new node and assgn data
 * 2. assign next of new node as head node reference
 * 3.tranfer the head node reference to new node*/

void append(Node **(head_ref),int d)// to add at the end
{
    Node *new_node=new Node();
    new_node->data=d;
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

/* Steps involved
 * 1.Create a new node and assign the data and next as NULL
 * 2.check if head is NULL
 * 3.If true the assgign head as the new data
 * 4.else traverse upto ed of the LL and assgn last next vae to the new node*/

void insert_after(Node **head_ref,int d,int index)
{
    Node *temp=*head_ref;
    int c=0;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        c++;
    }
    if(c>=index)
    {
        if(index==0)
        {
            push(head_ref,d);
        }
        else if(index==c)
        {
            append(head_ref,d);
        }
        else {
            Node *new_node=new Node();
            Node *temp1 = *head_ref;
            while (index--) {
                temp1 = temp1->next;
            }
            new_node->data=d;
            new_node->next = temp1->next;
            temp1->next = new_node;
            temp1=new_node;
        }
    }
    else
    {
        cout<<"Overflow";
    }
}

/*Steps to be followed
 * 1.using a temp head refernce count the number of elements inLL
 * 2.ift he index==0(1st elt) call the push fn
 * 3.if the index== last index claa the append function
 * 4.else traverse with a temp head ref node upto the index
 * 5.make the next of the new node to the next of the current node and next of the current node
 * 6.next of current node assigned as new node
 */

void print_LL(Node **head_ref)
{
    Node *temp=*head_ref;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    Node *head=NULL;
    append(&head,1);
    append(&head,2);
    push(&head,0);
    insert_after(&head,8,1);
    print_LL(&head);
    return 0;
}
