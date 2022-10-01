//4.Write a program to count number of objects created from a class using concept of static data member and static member function.
#include <iostream>
using namespace std;
class check{
    private:
        int count;
        static int static_count;        
    public:
        check(){
            count=++static_count;
        }
        void display_number(){
            cout<<"Object Number: "<<count<<endl;
        }
        static void display_count(){
            cout<<"Object Count: "<<static_count<<endl;
        }
};
int check::static_count;
int main(){
    check c1;
    check::display_count();
    check c2,c3;
    check::display_count();    
    c1.display_number();
    c2.display_number();
    c3.display_number();
    return 0;
}
