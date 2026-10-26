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
    void InsertAt()
    {
        int value;
        int position;
        cout<<"Enter the value :";
        cin>>value;
        cout<<"Enter the position (starting at 1) : ";
        cin>>position;

        if (position < 1)
        {
            cout<<"Position must be at least 1"<<endl;
            return;
        }

        if (position == 1)
        {
            node* newNode = new node{value, head};
            head = newNode;
            cout<<"Value added at position "<<position<<endl;
            return;
        }

        node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; ++i)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout<<"Position is beyond the end of the list"<<endl;
            return;
        }

        node* newNode = new node{value, current->next};
        current->next = newNode;
        cout<<"Value added at position "<<position<<endl;
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
    int len(node* head)
    {
        node* current = head;
        int count = 0;
        while(current->next != nullptr)
        {
            count++;
        }
        return count;
    }
    void AddToHead(node* & head,int value)
    {
        node* new_node = new node{value,head};
        head = new_node;
    }
};



int main()
{
    Linked_List list;
    int check=0;
    int value;
    while(true){
    cout<<"----------List------------\n";
    cout<<"1.InserAt\n";
    cout<<"2.Delete value\n";
    cout<<"3.Output list\n";
    cout<<"4.Exit\n";
    cin>>check;
    switch(check)
    {
        case 1:
        {
        list.InsertAt();
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