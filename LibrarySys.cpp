#include <iostream>

using namespace std;

 class Lending;
 static Lending *start = nullptr ;
 class Medium
 {
 private:
    unsigned int number;
    string title;
 public:
    Medium (unsigned int, string);
    ~Medium()
    { }
    void set_title (string);

    string get_title ()
    {
        return title;
    }
    unsigned int get_number()
    {
        return number;
    }
    virtual void print() = 0;
 };

 Medium::Medium (unsigned int num, string t) : number(num), title(t)
 {  }
 void Medium::set_title (string t)
 {
     title = t;
 }
 class PrintMedium : public Medium
 {
 public:
    PrintMedium(unsigned int num , string t) : Medium(num, t)
    {  }
 };
 class Book : public PrintMedium
 {
 private:
    unsigned int isbn;
 public:
    Book (unsigned int num, string t, unsigned int i) : PrintMedium(num, t), isbn(i)
    {  }
    void print();
 };
 void Book::print()
 {
     cout << "book number: "<< get_number() <<". " << "Title: " << get_title()<< ". " << "ISBN: " << isbn <<endl;

 }
 class Person
{
private:
    unsigned int number;
    string name;
public:
    Person(unsigned int n, string s) : number(n), name(s)
    { }
void print()
{
    cout << "person with passport number: " << number << ", " << "name: " << name <<endl;
}
};
class Lending
{
private:
    Medium *medium;
    Person *person;
    Lending *next ;
public:
    Lending(Medium *m, Person *p, Lending *l) : medium(m), person(p),  next(l)
    {
      }
void print()
{
    cout << "Lending" << endl;
    person->print( );
    medium->print();
}
void printAll()
{ Lending *p = this;
 while(p!=nullptr)
 {
    p->print();
     p = p->next;

 }
}
};

int main ()
{
    Book b1(43,"America",22222);
    Person p1(66,"Maria");
    Lending l1(&b1,&p1,start);


    Book *b2 = new Book(63,"Asien",55555);
    Person p2(88,"Lara");
    Lending l2(b2,&p2,&l1);
    l2.printAll();
    delete b2;
return 0;
}
