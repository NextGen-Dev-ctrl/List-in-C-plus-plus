#include<iostream>
using namespace std;
struct node
{
    int val;
    node *next;
};
node* createNode(node *current, int value)
{
    node *n;
    n=new node;
    n->val=value;
    n->next=NULL;
    current->next=n;
    return n;
}
void outputList(node *head)
{
    node *current;
    current=head;
     while(current != NULL)
    {
        cout<<current->val<<endl;
        current=current->next;
    }
}
int main()
{
    node *current;
    node *head;
    head = new node;
    current = head;
    current->val = 4;
    current = createNode(current,5);
    current = createNode(current,6);
    current = createNode(current,7);
    outputList(head);
   
}