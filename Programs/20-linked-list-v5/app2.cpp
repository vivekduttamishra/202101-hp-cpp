#include <stdio.h>
#include <iostream>
#include <exception>
#include <string>
#include <time.h>
#include "list.h"
using namespace std;
using namespace conceptarchitect::data;
#include "utils.h" //isPrime
#include "book.h"
#include "algorithm.h"


void printBook(Book &book)
{
    cout<<"Titles "<<book.title<<endl;
    cout<<"Author :"<<book.author<<endl;
    cout<<"Price :"<<book.price<<endl;
    cout<<"rating :"<<book.rating<<endl<<endl<<endl;
}

bool findBookPricedUnder300(Book book)
{
    return book.price<300;
}



int main(){

   LinkedList<Book> books;

   populateBookList(books);

   //displayBooks(books, "Original List");

    forEach(books.begin(), books.end(),printBook);

    LinkedList<Book> result;
    
    find(books.begin(), books.end(),findBookPricedUnder300,result);
    displayBooks(result,"Books under 300");

    find(books.begin(), books.end(),BookByAuthor("Jeffrey Archer"),result.clear());
    displayBooks(result,"Books By Jeffrey Archer");


    find(books.begin(), books.end(), PriceRange{300,400}, result.clear());

    displayBooks(result, "Books in Price Range 300-400");


    //find all books with rating 4.5 and above

    find(books.begin(), books.end(), [](const Book&b){return b.rating>=4.5;}, result.clear());


    cout<<"Books with rating >4.5"<<endl;

    forEach(result.begin(), result.end(), 
            [](Book &book){cout<<book.title<<"\t"<<book.rating<<endl;}  );


    return 0;
}