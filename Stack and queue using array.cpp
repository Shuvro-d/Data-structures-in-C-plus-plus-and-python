#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;

#define n    100

class Stack
{
    int* arr;
    int top;

public:
    Stack()
    {
        arr=new int[n];
        top=-1;
    }

    void push(int x)
    {
        if(top==n-1){
            cout<<"overflowed"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"no element"<<endl;
        }
        top--;
    }

    int Top(){
    if(top==-1)
    {
        cout<<"no element"<<endl;
        return -1;
    }
    return arr[top];
    }

    bool empty()
    {
        return top==-1;
    }
};


class Queue
{
    int* arr;
    int frnt;
    int bck;

public:
    Queue(){
    arr=new int[n];
    frnt=-1;
    bck=-1;
    }

    void push(int x)
    {
        if(bck==n-1)
        {
            cout<<"Overflowed"<<endl;
            return;
        }
        bck++;
        arr[bck]=x;
        if(frnt==-1)
        {
            frnt++;
        }
    }

    void pop()
    {
        if(frnt==-1 or frnt>bck)
        {
            cout<<"no element"<<endl;
            return;
        }
        frnt++;
    }

    int peek()
    {
        if(frnt==-1 or frnt>bck)
        {
            cout<<"no element"<<endl;
            return -1;
        }
        return arr[frnt];
    }

    bool empty()
    {
        if(frnt==-1 or frnt>bck)
        {
            cout<<"no element"<<endl;
            return true;
        }
        return false;
    }
};



int main()
  {
      Stack st;
      st.push(1);
      st.push(2);
      st.push(3);
      st.push(4);
      cout<<st.Top()<<endl;
      st.pop();
      st.pop();
      cout<<st.Top()<<endl;

      cout<<"queue"<<endl;
      Queue qt;
      qt.push(1);
      qt.push(2);
       qt.push(3);
      qt.push(4);
      cout<<qt.peek()<<endl;
      qt.pop();
    cout<<qt.peek()<<endl;
    return 0;
  }
