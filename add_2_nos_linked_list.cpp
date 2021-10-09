#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
void add(Node **head_ref1,Node **head_ref2,Node **head_ref3,int n,int m)
{
    Node *t1=*head_ref1,*t2=*head_ref2,*t3;
    int carry=0,max;
    if(n>=m)
    {
        max=n;
    }
    else
    {
        max=m;
    }
    while(max--)
    {
        Node *new_node=new Node();
        if(m==n && max==0)
        {
            new_node->data=t1->data+t2->data+carry;
            new_node->next=NULL;
            if(*head_ref3==NULL)
            {
                *head_ref3=new_node;
                t3=*head_ref3;
            }
            else
            {
                t3->next=new_node;
                t3=new_node;
            }
        }
        else {
            if(n>0 && m>0) {
                new_node->data = (t1->data + t2->data + carry) % 10;
                new_node->next=NULL;
                if (t1->data + t2->data >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                t1 = t1->next;
                t2 = t2->next;
            }
            else if(n>0 && m<=0)
            {
                if(n==1)
                {
                    new_node->data=t1->data+carry;
                    new_node->next=NULL;
                }
                else
                {
                    new_node->data=(t1->data+carry)%10;
                    new_node->next=NULL;
                    if(t1->data+carry>=10)
                    {
                        carry=1;
                    }
                    else
                    {
                        carry=0;
                    }
                }
                t1=t1->next;
            }
            else if(n<=0 && m>0)
            {
                if(m==1)
                {
                    new_node->data=t2->data+carry;
                    new_node->next=NULL;
                }
                else
                {
                    new_node->data=(t2->data+carry)%10;
                    new_node->next=NULL;
                    if(t2->data+carry>=10)
                    {
                        carry=1;
                    }
                    else
                    {
                        carry=0;
                    }
                }
                t2=t2->next;
            }
            if (*head_ref3 == NULL)
            {
                *head_ref3 = new_node;
                t3 = *head_ref3;
            } else {
                t3->next = new_node;
                t3 = new_node;
            }
            n--;
            m--;
        }
    }
}
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
        cout<<t->data;
        t=t->next;
    }
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Node *head1=NULL,*head2=NULL,*head3=NULL;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        push(&head1,a);
    }
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        push(&head2,a);
    }
    reverse(&head1);
    reverse(&head2);
    add(&head1,&head2,&head3,n,m);
    reverse(&head3);
    print(&head3);
    return 0;
}
