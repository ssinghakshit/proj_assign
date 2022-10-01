//1.Create a class which stores name, author and price of a book. Store information for n number of books.
// Display information of all the books in a given price range using friend function.
#include<iostream>
using namespace std;
class Book{
    private:
        string bookname, bookauthor;
        double price;
    public:
        Book (){            
        }
        Book(string n, string a, double p){
            bookname = n;
            bookauthor = a;
            price = p;
        }
        void setDetails(string n, string a, double p){
            bookname = n;
            bookauthor = a;
            price = p;
        }
        string getName(){
            return bookname;
        }
        string getAuthor(){
            return bookauthor;
        }
        double getPrice(){
            return price;
        }
        void printBook(){            
            cout<<"Book name :\t"<<bookname<<endl;
            cout<<"Book author :\t"<<bookauthor<<endl;
            cout<<"Book price: \t"<<price<<endl;
        }
    friend void display(int x);    
};
void display(int x ){
    string bookname, bookauthor;
        double price;    
    Book arr[x];    
    for(int i=0; i<x; i++){
        cout<<"Enter the book name:\n";
        cin>>bookname;
        cout<<"Enter the author:\n";
        cin>>bookauthor;
        cout<<"Enter the book price:\n";
        cin>>price;
        arr[i].setDetails(bookname,bookauthor,price);
    }
     int m,n;
            cout<<"Enter price range :\n";
            cin>>m>>n;
    for(int i=0; i<x; i++){
        if(arr[i].price>=m && arr[i].price<=n){
        cout<<"____"<<endl;
        cout<<"Details of book "<<(i+1)<<"  are:\n";
        arr[i].printBook();
    	}	
    }
}
int main(){
    int x;
    cout<<"Enter the number of books:\n";
    cin>>x;
    display(x);
}