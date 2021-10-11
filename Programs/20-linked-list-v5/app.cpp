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


int main(){

   LinkedList<Book> books;

   populateBookList(books);

   displayBooks(books, "Original List");

   
    return 0;
}