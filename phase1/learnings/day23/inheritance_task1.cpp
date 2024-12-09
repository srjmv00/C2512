// Question 14: `Publishing Workflow`
// - `Base Class:` Document `{field: content, behavior: edit()}`
// - `Derived Class 1:` Article `{field: wordCount, behavior: review()}`
// - `Derived Class 2:` Blog `{field: views, behavior: publish()}

#include <iostream>
#include <string>

using namespace std;

class Document{
    protected:
        string content;
    
    public:
        Document(const string content):content(content){
            cout << "Document contructor...."<< endl;
        }
        ~Document(){
            cout << "Document destructor...."<< endl;
        }
        void Edit(){
            cout << "Edit...." << endl;
        }
};

class Article:virtual public Document{
    private:
        int wordcount;

    public:
        Article(const string content,int wordcount):Document(content),wordcount(wordcount){
            cout << "Article constructor...."<< endl;
        }
        ~Article(){
            cout << "Article destructor...."<< endl;
        }
        void Review(){
            cout << "Review...." << endl;
        }
};

class Blog:virtual public Document{
    private:
        int views;

    public:
        Blog(const string content,int views):Document(content),views(views){
            cout << "Blog constructor...." << endl;
        }
        ~Blog(){
            cout << "Blog destructor...." << endl;
        }
        void Publish(){
            cout << "Publish...." << endl;
        }
};

class FeaturedContent:public Article,public Blog{
    private:
        string featuredDate;

    public:
        FeaturedContent(const string content,int wordcount,int views,const string featuredDate)
        :Document(content),Article(content,wordcount),Blog(content,views),featuredDate(featuredDate){
            cout << "Featured content consturctor... " << endl; 
            cout <<content<< " " <<wordcount<< " "<<views<< " " <<featuredDate<< endl;
        }
        ~FeaturedContent(){
            cout << "Featured Content destructor...."<< endl;
        }
        void Boost(){
            cout << "Boost...."<< endl;
        }
};

// Create one static object for final-derived class
// and call all behaviours
// and 
// one dynamic object for final-derived class 
// and call all behaviours

int main(){
    FeaturedContent f("Document writing",545,300,"12/12/2024");
    f.Edit();
    f.Review();
    f.Publish();
    f.Boost();

    FeaturedContent* dynf = new FeaturedContent("Article writing",405,210,"21/11/2024");
    dynf->Edit();
    dynf->Review();
    dynf->Publish();
    dynf->Boost();

    delete dynf;

    return 0;
}