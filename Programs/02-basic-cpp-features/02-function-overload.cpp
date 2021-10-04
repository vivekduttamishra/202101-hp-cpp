#include <iostream>

void show(int value){
    std::cout<<"int: "<<value<<"\n";
}

void show(long value){
    std::cout<<"int: "<<value<<"\n";
}

void show(const char* value){
    std::cout<<"string: "<<value<<"\n";
}

void show(int size, int * array){
    std::cout<<"numbers: ";

    for(int i=0;i<size;i++){
        std::cout<< array[i]<<"\t";
    }

    std::cout<< std::endl;
}



int main(){

    std::cout<<"Method overload test\n";

    show(200);

    show("Hello World");

    int arr[]={2,3,9,5,2};

    show(3, arr);

    //show(3.5);  

    return 0;
}