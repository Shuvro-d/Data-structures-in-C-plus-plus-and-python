#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()          //default constructor
    {
        head = NULL;
        tail = NULL;
    }

    void append(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        tmp->prev = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tmp->prev=tail;
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void prepend(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        tmp->prev=NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            head->prev=tmp;
            tmp->next = head;
            head=tmp;
        }
    }


    void insert_at_nth(int n,int pos)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        tmp->prev=NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            if(pos==1)
            {
                head->prev=tmp;
                tmp->next=head;
                head=tmp;
                return;
            }
            int x=1;
            node *v=head;
            while(v->next!=NULL)
            {
                if(x==pos-1)
                {
                    tmp->next=v->next;
                    tmp->prev=v->next->prev;
                    v->next=tmp;
                    tmp->next->prev=tmp;
                }
                x++;
                v=v->next;
            }
        }
    }


    void deleteNode(int n)
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->data==n)   //if n is first node
        {
            head=head->next;
            head->prev=NULL;
            return;
        }
        node *ptr=head;
        while(ptr->next!=NULL)
        {
            if(ptr->next->data==n)
            {
                ptr->next=ptr->next->next;
                if(ptr->next==NULL)
                {
                    tail=ptr;
                }
                return;
            }
            ptr=ptr->next;
        }
    }


    void printList()
    {
        node *tmp=new node;
        tmp=head;
        while(tmp->next!=NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<tmp->data<<endl;
    }

    void printListReverse()
    {
        node *tmp=new node;
        tmp=tail;
        while(tmp->prev!=NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->prev;
        }
        cout<<tmp->data<<endl;
    }
};

int main()
{
    linked_list a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.append(5);
    a.prepend(10);
    a.prepend(77);
    a.printList();
    a.insert_at_nth(111,3);
    a.printList();
    a.deleteNode(77);
    a.printList();
    a.deleteNode(5);
    a.printList();
    a.printListReverse();
    return 0;
}

