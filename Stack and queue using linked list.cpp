#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;

class node
{
public:
    int data;
    node *next;
};


class Stack
{
    node *top;
public:
    Stack()
    {
        top=NULL;
    }

    void push(int x)
    {
        node *tmp=new node();
        if(!tmp)
        {
            cout<<"overflowed"<<endl;
            return;
        }
        tmp->data=x;
        tmp->next=top;
        top=tmp;
    }


    void pop()
    {
        node* temp;
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        else
        {
            temp = top;
            top = top->next;
            free(temp);
        }
    }

    void display()
    {
        node* temp;
        if (top == NULL)
        {
            cout << "Stack Underflow"<<endl;
            return;
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }

    int isEmpty()
    {
        return top == NULL;
    }
};


class Queue
{
    node *top,*last;
    public:
    Queue()
    {
        top=last=NULL;
    }

    void enqueue(int x)
    {
        node *temp = new node();
        temp->data=x;
        temp->next=NULL;
        if (last == NULL) {
            top = last = temp;
            return;
        }
        last->next = temp;
        last = temp;
    }

    void dequeue()
    {
        if (top == NULL)
        {
               return;
        }
        node *temp = top;
        top = top->next;
        if (top == NULL){
               last = NULL;
        }
        delete (temp);
    }
    void display()
    {
        node* temp;
        if (top == NULL)
        {
            cout << "queue Underflow"<<endl;
            return;
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
      int isEmpty()
    {
        return top == NULL;
    }

};

int main()
{
    Stack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.display();
    a.pop();
    a.display();
    cout<<"queue"<<endl;
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}

