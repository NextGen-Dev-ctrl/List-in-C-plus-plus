#include<iostream>
using namespace std;
struct node
{
    int val;
    node *next;
};
class Linked_List
{
    private:
    node* head;
    public:
    Linked_List()
    {
        head = nullptr;
    }
    // Getter of head
    node* getHead() 
    {
        return head;
    }
    // Setter for head
    void setHead(node* newHead)
    {
        head = newHead;
    }
    void outputList()
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
    void AddValue()
    {
        int value;
        cout<<"Enter the value :";
        cin>>value;
        node *n = new node{value, nullptr};
        if (head == nullptr)
        {
            head = n;
        }
        else
        {
            node *current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = n;
        }
        cout<<"----------Value is successfully added---------\n";
    }
    void delete_node(int value)
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
        outputList();
    }
};



int main()
{
    Linked_List list;
    int check=0;
    int value;
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
        list.AddValue();
        }
        break;
        case 2:
        value=0;
        cout<<"Enter the value which you want to delete :";
        cin>>value;
        list.delete_node(value);
        break;
        case 3:
        list.outputList();
        break;
        case 4:
        return 0;
        break;
        default:
        cout<<"------------Invalid Input------------\n";
    }
}
   
   
   
}