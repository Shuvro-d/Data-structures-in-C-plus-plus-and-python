#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ara[5]={1,2,3,4,5};
    cout<<ara<<endl;
    cout<<&ara[0]<<endl;
    for(int i=0;i<5;i++){
        cout<<*(ara+i)<<endl;
    }
    return 0;
}
