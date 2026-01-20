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
    cout<<"[ ";
     while(current != NULL)
    {
        cout<<current->val<<" ";
        current=current->next;
    }
    cout<<"]\n";
}
node* AddValue(node *current)
{
    node *ret;
    int value;
    cout<<"Enter the value :";
    cin>>value;
    ret=createNode(current,value);
    cout<<"----------Value is successfully added---------\n";
    return ret;
}
void delete_node(node* &head, int value)
{
    if (head == NULL)
        return;

    // If head needs to be deleted
    if (head->val == value)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node *cur = head;
    while (cur->next != NULL && cur->next->val != value)
    {
        cur = cur->next;
    }

    if (cur->next == NULL)
    {
        cout << "Value not found\n";
        return;
    }

    node *temp = cur->next;
    cur->next = temp->next;
    delete temp;
    outputList(head);
}

int main()
{
    node *current;
    node *head;
    head = new node;
    current = head;
    head->next=NULL;
    head->val=0;
    int check=0;
    int value;
    int firstVal=0;
    while(true){
    cout<<"----------List------------\n";
    cout<<"1.Add member\n";
    cout<<"2.Delete value\n";
    cout<<"3.Output list\n";
    cout<<"4.Exit\n";
    cin>>check;
    switch(check)
    {
        case 1:
        {
        if(firstVal > 0)
        {
        current = AddValue(current);
        }
        else
        {
        cout<<"Enter the value :";
        cin>>value;
        head->val=value;
        firstVal++;
        }
        }
        break;
        case 2:
        value=0;
        cout<<"Enter the value which you want to delete :";
        cin>>value;
        delete_node(head,value);
        break;
        case 3:
        outputList(head);
        break;
        case 4:
        return 0;
        break;
        default:
        cout<<"------------Invalid Input------------\n";
    }
}
   
   
   
}