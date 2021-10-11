#pragma once
#include <iostream>
using namespace std;
#include "list.h"
using namespace conceptarchitect::data;
#include "algorithm.h"


struct Book
{
    string title;
    string author;
    int price;
    double rating;

    Book(string title, string author,int price, double rating){
        this->title = title;
        this->author=author;
        this->price=price;
        this->rating=rating;
        
    }

    //Book(){cout<<"Book created with 0 arg constructor"<<endl;}  //I can't have a book that has no information
};

inline ostream& operator<<(ostream & os , const Book& book)
{
    return os<< book.price << "\t" << book.rating << "\t"<<book.author<<"\t"<<book.title<<endl;
}

inline void populateBookList(LinkedList<Book> & books){

    books   <<  Book("The Accursed God","Vivek Dutta Mishra",399,4.5)
            <<  Book("Kane and Abel","Jeffrey Archer", 450, 4.3)
            <<  Book("Brethren","John Grisham", 250, 4.1)
            <<  Book("Rashmirathi","Radmdhari Sing Dinkar", 110, 4.7)
            <<  Book("Sins of Father","Jeffrey Archer", 250, 3.7);

};

inline void displayBooks(LinkedList<Book> &books, string title="Books")
{
    cout<<title<<endl;

    cout<<"Price\tRating\tAuthor\tTitle"<<endl;

    forEach(books.begin(), books.end(), [](auto book){cout<< book;})   ; 

    // for(auto p = books.begin(); p != books.end(); p++)
    //     cout<< *p ;

    cout<<endl<<endl;
}

class BookByAuthor{
    string authorName;
    public:
    BookByAuthor(string authorName):authorName(authorName){}

    bool operator()(const Book &book){
        return book.author==authorName;
    }
};


struct PriceRange{
    int min,max;
    bool operator()(const Book &book){
        return book.price>=min && book.price<max;
    }
};





