#include<bits/stdc++.h>
using namespace std;

void print(void*ptr, char type){
    switch(type){
        case 'i': cout<<*((int*)ptr)<<endl;break;
        case 'c': cout<<*((char*)ptr)<<endl;break;
        case 'd': cout<<*((double*)ptr)<<endl;break;
        case 'f': cout<<*((float*)ptr)<<endl;break;
    }
}

int main()
{
    int  number=5;
    char letter='x';
    double x=123458790;
    print(&number,'i');
    print(&letter,'c');
    print(&x,'d');
    return 0;
}
