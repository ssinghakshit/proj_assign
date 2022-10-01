//2.Write a program to create  a class to store details of a student ( name, roll and 3 subject marks ).
// Input details for 2 students and assign all the details of that student who is having higher average mark to a new student. 
// i) use member function 
// ii) use friend function
#include <iostream>
using namespace std;
class student{
public:
    string name;
    int roll, math, phy, chem;
    float avg;
    void input(){
        cout << "Name: ";
        cin >> name;
        cin.ignore();
        cout << "Roll: ";
        cin >> roll;
        cout << "Enter 3 marks Marks: ";
        cin >>math>>phy>>chem;
        avg= (math+phy+chem)/3;
    }
    void display(){
        cout << "Name:" << name << "\t Roll: " << roll << "\tMarks: " << math << "," << phy << "," << chem<<endl;
    }
    friend void store(student &s, student &s1){
        s=s1;
    }
    void storemb(student &s, student &s1){
        s=s1;
    }
};
int main()
{
    student b[2];
    student sff, smb;
    for (int i = 0; i < 2; i++){
        cout << "Enter details of the student " << i + 1 << endl;
        b[i].input();
    }
    for (int i = 0; i < 2; i++){
        b[i].display();
    }
    if(b[0].avg> b[1].avg){
        store(sff, b[0]);
        smb.storemb(smb, b[0]);
    }
    else{
        store(sff, b[1]);
        smb.storemb(smb, b[1]);
        
    }
    cout<<"New Student details:\n";
    sff.display();
    smb.display();
}