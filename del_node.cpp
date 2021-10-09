#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
int f=0;
void append(Node **head_ref,int data)
{
    Node *new_node=new Node();
    new_node->data=data;
    new_node->next=NULL;
    if(*head_ref!=NULL)
    {
        Node *temp=*head_ref;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
    else
    {
        *head_ref=new_node;
    }
}
void delNodeInd(Node **head_ref,int index)
{
    index--;
    int s=0;
    Node *temp=*head_ref;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        s++;
    }
    if(index<=s)
    {
        Node *temp1=*head_ref;
        Node *temp2=*head_ref;
        while(index--)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=temp1->next;
        delete temp1;
    }
    else
    {
        cout<<"Overflow";
    }
}
void print(Node **head_ref)
{
    if(f==0) {
        Node *t = *head_ref;
        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
}
void delNodeKey(Node **head_ref,int elt)
{
    Node *t1=*head_ref,*t2=*head_ref;
    while(t1!=NULL && t1->data!=elt)// note:when t1 crosses last elt assign it as null
    {
        t2=t1;
        t1=t1->next;
    }
    if(t2->next==NULL)
    {
        cout<<"Overflow";
    }
    else
    {
        t2->next=t1->next;
        delete t1;
        print(head_ref);
    }
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Node *head=NULL;
    append(&head,0);
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    print(&head);
    cout<<"Options:\n1.To delete with index enter 1:\n2.To delete with elt enter 2:\n";
    int option;
    cin>>option;
    if(option==1) {
        delNodeInd(&head, 3);
        print(&head);
    }
    else
    {
        delNodeKey(&head,5);
    }
    return 0;
}
