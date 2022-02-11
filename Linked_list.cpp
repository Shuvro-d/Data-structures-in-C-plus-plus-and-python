#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    int siz=0;
    linked_list()    //default constructor
    {
        head = NULL;
        tail = NULL;
    }

    void append(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        siz++;
    }

    void prepend(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tmp->next = head;
            head=tmp;
        }
        siz++;
    }


    void insert_at_nth(int n,int pos)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
            siz++;
        }
        else if(pos>siz)
        {
            append(n);
        }
        else
        {
            if(pos==1)
            {
                tmp->next=head;
                head=tmp;
                siz++;
                return;
            }
            int x=1;
            node *v=head;
            while(v->next!=NULL)
            {
                if(x==pos-1)
                {
                    tmp->next=v->next;
                    v->next=tmp;
                }
                x++;
                v=v->next;
            }
            siz++;
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
            siz--;
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
                siz--;
                return;
            }
            ptr=ptr->next;
        }
    }


    void reverse_list()
    {
        node *temp = NULL;
        node *prev = NULL;
        node *current = head;
        while(current != NULL)
        {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        head= prev;
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
    a.reverse_list();
    a.printList();
    return 0;
}
