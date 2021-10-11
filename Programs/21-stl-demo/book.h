#pragma once
#include <iostream>
#include <string>
#include<algorithm>   //all stl component are in std namespace
using namespace std;

struct Book
{
    string title;
    string author;
    int price;
    double rating;

    Book(string title, string author, int price, double rating)
    {
        this->title = title;
        this->author = author;
        this->price = price;
        this->rating = rating;
    }

    //default sorting on title
    bool operator<(const Book&second){
        return title<second.title;
    }

    //Book(){cout<<"Book created with 0 arg constructor"<<endl;}  //I can't have a book that has no information
};

inline ostream &operator<<(ostream &os, const Book &book)
{
    return os << book.price << "\t" << book.rating << "\t" << book.author << "\t" << book.title << endl;
}

template <typename Container>
inline void populateBookList(Container &container)
{

    Book books[] = {
        Book("The Accursed God", "Vivek Dutta Mishra", 399, 4.5),
        Book("Kane and Abel", "Jeffrey Archer", 450, 4.3),
        Book("Brethren", "John Grisham", 250, 4.1),
        Book("Rashmirathi", "Radmdhari Sing Dinkar", 110, 4.7),
        Book("Sins of Father", "Jeffrey Archer", 250, 3.7)};

    for(auto book:books)
        container.push_back(book);
};



template<typename SmartPointer>
inline void displayBooks(SmartPointer first, SmartPointer last, string title = "Books")
{
    cout << title << endl;
   cout << "Price\tRating\tAuthor\tTitle" << endl;
    for_each(first, last, [](auto book)
            { cout << book; });
    cout << endl
         << endl;
}

