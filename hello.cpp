#include<iostream>
using namespace std;
struct node
{
    int val;
    node *next;
};
*node createNode(node *current, int value)
{
    node *n;
    n=new node;
    n->val=vlaue;
    n->next=NULL;
    current->next=n;
    return n;
}
int main()
{
    
}