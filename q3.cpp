// 3.Write a program to create a class to store details of an employee like name , age,  job_id and department name(common to all).
// Input display details of 3 employees using array of objects concept.
#include <iostream>
using namespace std;
class employee{
        char name[30];
        int age;
        int job_id;
        char department[40];
    public:
        void getDetails(void);
        void putDetails(void);
};
void employee::getDetails(void){
    std::cout<<"Enter the name: " ;
    cin>>name;
      std::cout<<"Enter the age: ";
    cin>>age;
      std::cout<<"Enter the job ID: ";
    cin>>job_id;
}
void employee::putDetails(void){
  std::cout<<"Employee details:\n";
  std::cout<<"Name:"<<name<<",Age:"<<age<<",Job ID:"<<job_id<<endl;
  std::cout<<"department Account"<<'\n';
}
int main(){
        int hg=98;
    int n,i;
    cout<<"Enter total number of employee: ";
    cin>>n;
    employee e[n];
    for(i=0;i< n;i++)    {
        cout<<"Enter details of employee "<<i+1<<":\n";
        e[i].getDetails();
    }
    cout<<endl;
    for(i=0;i< n;i++){
        cout<<"Details of employee "<<(i+1)<<":\n";
        e[i].putDetails();
    }
    return 0;
}
