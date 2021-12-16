
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode
//sir kindly run this code in onlinecpp compilor it wont execute on vscode






#include<iostream>
#include<string>
using namespace std;
class List
{
    int* array;
    int* current;
    int length;
    int size;
    int d;
public:
    List()
    {
        length = 0;
        size = 0;
        d = 0;
        cout << "Enter the size of ARRAY :";
        cin >> size;
        array = new int[size];
    }

    void Listlength()
    {
        length = size;
        cout << endl;
            cout<<"----------Enter the Numbers--------"<<endl;
                for(int i=0;i<length;i++)
                {
                    cin>>d;
                    *(array+i)=d;
                    current++;
                }
            cout << "----------Numbers are----------" << endl;
        for (int i = 0; i <size; i++)
        {
            cout << *(array+i) << "   " ;
            current++;
        }
    }

    void start()
    {
        current = array;
    }

    void end()
    {
        for (int i = 1; i < length; i++)
        {
            current++;
        }
    }

    void next()
    {
        start();
        current++;
    }

    void back()
    {
        current--;
    }

    void ADD(int value, int position)
    {
        start();
        end();
        int newsize = size + 1;
        int j = 0;
        int* newarray = new int [newsize];
        for(int i = 0; i < newsize; i++){
            if(i == position){
                newarray[i] = value;
                continue;
            }
            newarray[i] = array[j];
            j++;
        }
        array = newarray;
        size++;
    }

    void remove(int position)
    {
        int newsize = size;
        int* newarray = new int [newsize];
        int j = 0;
        for(int i = 0; i < size ; i++){
            if( array[i] != position){
                newarray[j] = array[i];
                j++;
            }
        }
        array = newarray;
        size--;
    }

    int get(int position)
    {
        int num = 0;
        for (int i = 0; i < size; i++)
        {
            if(i == position){
                num = array[i];
                break;
            }
        }
        return num;
    }

    void update(int value, int position)
    {
        for (int i = 0; i < size; i++)
        {
            if(i == position){
                array[i] = value;
                break;
            }
        }
    }

    bool find(int value)
    {
        bool found = false;
        start();
        for (int i = 0; i < size; i++)
        {
            if (*current == value)
            {
                found = true;
                break;
            }
            next();
        }
        return found;
    }
    void print()
    {
        start();
        cout<<" Start : "<<*current<<endl;
        end();
        cout<<"End :"<<*current<<endl;
        next();
        cout<<"Next :"<<*current<<endl;
        back();
        cout<<"Back :"<<*current<<endl;
    }
    void print1(){
        for(int i = 0; i < size; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    int getsize(){
        return size;
    }
};

int main()
{
    int i = 0;
    int j = 0;
    List l;
    l.Listlength();
    cout<<endl;
    l.print();
    l.print1();
    cout<<"Enter number to remove: ";
    cin>>i;
    l.remove(i);
    l.print1();
    cout<<"Enter number to add into the list: ";
    cin>>i;
    error1:
    cout<<"Enter the position: ";
    cin>>j;
    if(j > l.getsize()){
        cout<<"ERROR!! POSITION CANNOT BE GREATER THAN SIZE\n";
        goto error1;
    }
    l.ADD(i, j);
    l.print1();
    error2:
    cout<<"Enter position to view in list: "; 
    cin>>i;
    if(i > l.getsize()){
        cout<<"ERROR!! POSITION CANNOT BE GREATER THAN SIZE\n";
        goto error2;
    }
    cout<<l.get(i)<<endl;
    l.print1();
    cout<<"Enter number to update in list: ";
    cin>>i;
    error3:
    cout<<"Enter position: ";
    cin>>j;
    if(j > l.getsize() - 1){
        cout<<"ERROR!! POSITION CANNOT BE GREATER THAN SIZE\n";
        goto error3;
    }
    l.update(i,j);
    l.print1();
    cout<<"Enter number to find: ";
    cin>>i;
    if(l.find(i)){
        cout<<"Number exists in list"<<endl;
    }else{
        cout<<"Number doesnot exist in list"<<endl;
    }
    l.print1();
    return 0;
}