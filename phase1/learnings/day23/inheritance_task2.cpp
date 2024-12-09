// Problem 14: `Publishing System`
// - Create a base class `Publication` with fields `title` and `author`, and a behavior `printDetails()`.
// - Derive a class `Magazine` with fields `issueNumber` and a behavior `publish()`.


#include <iostream>
#include <string>

using namespace std;

class Publication{
    protected:
        string title;
        string author;

    public:
        Publication(const string title,const string author):title(title),author(author){
            cout << "Publication Contructor.... " << title<< endl;
        }
        ~Publication(){
            cout << "Publication Destructor...." << endl;
        }
        void printDetails(){
            cout << "Print Details...." << endl;
        }
};

class Magazine:public Publication{
    private:
        int issueNumber;
    
    public:
        Magazine(const string title,const string author,int issueNumber)
        :Publication(title,author),issueNumber(issueNumber){
            cout << "Magazine Constructor.... "<< title <<" issue Number is "<< issueNumber<<endl;  
        }
        ~Magazine(){
            cout << "Magazine Destructor.... " <<endl;
        }
        void Publish(){
            cout << "Publish...."<< endl;
        }
};
// Create two static objects for Both Base and Derived class
// and call all behaviours
// and 
// one two dynamic objects for Base and Derived class 
// and call all behaviours

int main(){
    Publication p("mowgli","Kipling");
    p.printDetails();
    Magazine m("pride and prejudice","Jane Austen",234);
    m.printDetails();
    m.Publish();

    Publication* dynp = new Publication("war and peace","Leo Tolstoy");
    dynp -> printDetails();
    Magazine* dynm = new Magazine("catch 22","Joseph Heller",551);
    dynm -> printDetails();
    dynm -> Publish();

    delete dynp;
    delete dynm;

    return 0;
}


