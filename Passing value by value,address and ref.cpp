#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;

void PassByValue(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    return;
}

void PassByRefrence(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    return;
}

void PassByAddress(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int a=5,b=10;

    PassByValue(a,b);
    cout<<a<<" "<<b<<endl;

    PassByRefrence(a,b);
    cout<<a<<" "<<b<<endl;

    PassByAddress(&a,&b);
    cout<<a<<" "<<b<<endl;

    return 0;
}
