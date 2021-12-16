#include<iostream>

using namespace std;

//pointer pass by reference

void myFun(int *& a){

    *a = *a+1;

    cout<<"Value of a:  "<<*a<<endl;

}

int main( ){

    int myInt = 90;
    
   

    cout<<"Value of myInt:  "<<myInt<<endl;


    cout << "Address of myInt is:   "<<&myInt<<endl;


    int *ptr; //dangling pointer 

    ptr = &myInt;


    cout<<"Address of ptr:  "<<&ptr<<endl;
    cout<<"Address stored in ptr:   "<<ptr<<endl;

    cout<<"Value pointed by ptr:    "<<*ptr<<endl;



 


    myFun(ptr);

    cout<<"Value of myInt:  "<<myInt<<endl;


    return 0;
}