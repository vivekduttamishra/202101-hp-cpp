#include <iostream>
#include <vector>   //all stl component are in std namespace
#include <algorithm>
#include "book.h"


using namespace std; 


template<class T>
void showList(const T &items,string header=""){
    cout<<header<<" : ";
     for(auto item:items)
        cout<<item<<"\t";

    cout<<endl;

}

int main(){

    vector<Book> books={
        Book{"The Accursed God", "Vivek Dutta Mishra", 399, 4.5},
        Book("Kane and Abel", "Jeffrey Archer", 450, 4.3),
        Book("Brethren", "John Grisham", 250, 4.1),
        Book("Rashmirathi", "Radmdhari Sing Dinkar", 110, 4.7),
        Book("Sins of Father", "Jeffrey Archer", 250, 3.7)
    };


    

    displayBooks(books.begin(), books.end(),"Original List");
  
    //how do I sort the books?





    sort(books.begin(), books.end()); //natural order using operator<


    displayBooks(books.begin(), books.end(),"Sorted Book List");






    //how do I sort the books on author name? or rating or price?
    //sort function takes a predicate, that compares two value return true if first is less than second

    sort(books.begin(), books.end(),[](auto b1,auto b2){ 
        return b1.author<b2.author;
    });

    displayBooks(books.begin(), books.end(),"Sorted on Author");


    //how do I sort on rating (highest first)

    sort(books.begin(), books.end(), [](auto b1, auto b2){ 
        return b2.rating<b1.rating;
    });

    displayBooks(books.begin(), books.end(),"Sorted on Rating");

    return 0;
}