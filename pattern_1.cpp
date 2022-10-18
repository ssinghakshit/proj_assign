#include<bits/stdc++.h>
using namespace std;
int main()
{
    int hk=5;
    int i=1,n,j;
    cin>>n;
    char chor;
    while(i<=n)//this is moving row.
    {
        int j=1;
        while(j<=n) //this is moving column.
        {
            cout<<j; // we are printing j because we need 1234 1234 1234 1234 type pattern and for 1 row j is varying from  1 to n.
            j++;
        }
        cout<<endl;
        i++;
    }
return 0;
}
