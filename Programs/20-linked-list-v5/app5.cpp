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
    cout << "Titles " << book.title << endl;
    cout << "Author :" << book.author << endl;
    cout << "Price :" << book.price << endl;
    cout << "rating :" << book.rating << endl
         << endl
         << endl;
}

bool findBookPricedUnder300(Book book)
{
    return book.price < 300;
}

int main()
{

    LinkedList<Book> books = {
        Book{"The Accursed God", "Vivek Dutta Mishra", 399, 4.5},
        Book("Kane and Abel", "Jeffrey Archer", 450, 4.3),
        Book("Brethren", "John Grisham", 250, 4.1),
        Book("Rashmirathi", "Radmdhari Sing Dinkar", 110, 4.7),
        Book("Sins of Father", "Jeffrey Archer", 250, 3.7)

    };

    //populateBookList(books);

    double avgPrice = average(books.begin(), books.end(), [](auto book)
                              { return book.price; });
    cout << "average price is :" << avgPrice << endl;

    double avgRatings = average(books.begin(), books.end(), [](auto book)
                                { return book.rating; });
    cout << "average rating is :" << avgRatings << endl;

    //what if I want to sum the total cost of all the books. I don't have a function for this
    //I can use forEach function

    double sum = 0;

    forEach(books.begin(), books.end(),
            [&sum](auto book)
            {
                sum += book.price;
            });

    cout << "Total Cost is " << sum << endl;

    return 0;
}