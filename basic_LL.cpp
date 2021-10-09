#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
int main() {
    Node *head=new Node();
    Node *second=new Node();
    Node *third=new Node();
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    /*|
    |
    +---+---+     +---+---+     +----+------+
    | 1 | o----->| 2 | o-----> | 3 | NULL |
    +---+---+     +---+---+     +----+------+*/
    return 0;
}
/* basis of creating a singly linked list and remember to use datatype as Node*/

