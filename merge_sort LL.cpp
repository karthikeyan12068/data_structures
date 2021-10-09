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
void merge(Node **head_ref,int left,int mid,int right)
{
    int a1=mid-left+1;
    int a2=right-mid;
    Node *new_arr1=NULL;
    Node *new_arr2=NULL;
    Node *temp=*head_ref;
    for(int i=0;i<left;i++)
    {
        temp=temp->next;
    }
    for(int i=0;i<a1;i++)
    {
        push(&new_arr1,temp->data);
        temp=temp->next;
    }
    Node *temp1=*head_ref;
    for(int i=0;i<mid+1;i++)
    {
        temp1=temp1->next;
    }
    for(int i=0;i<a2;i++)
    {
        push(&new_arr2,temp1->data);
        temp1=temp1->next;
    }
    int ind1=0,ind2=0,ind3=left;
    Node *t1=new_arr1,*t2=new_arr2,*t3=*head_ref;
    for(int i=0;i<ind3;i++)
    {
        t3=t3->next;
    }
    while(ind1<a1 && ind2<a2)
    {
        if(t1->data<=t2->data)
        {
            t3->data=t1->data;
            t1=t1->next;
            ind1++;
        }
        else
        {
            t3->data=t2->data;
            t2=t2->next;
            ind2++;
        }
        t3=t3->next;
    }
    while(ind1<a1)
    {
        t3->data=t1->data;
        t1=t1->next;
        t3=t3->next;
        ind1++;
    }
    while(ind2<a2)
    {
        t3->data=t2->data;
        t2=t2->next;
        t3=t3->next;
        ind2++;
    }

}
void MergeSort(Node **head_ref,int begin,int end)
{
    if(begin>=end)
    {
        return;
    }
    int mid=begin+(end-begin)/2;
    MergeSort(head_ref,begin,mid);
    MergeSort(head_ref,mid+1,end);
    merge(head_ref,begin,mid,end);
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
    MergeSort(&head,0,n-1);
    print(&head);
    return 0;
}
