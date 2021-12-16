#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;
class array
{
private:
    int arr[8];
    int *current;
public:
    array();
    ~array();
    int add();
    int get();
    int remove();
    int next();
    int back();
    int start();
    int end();
    int remove();
    int update();
};

array::array()
{
    current = NULL;
}

array::~array()
{
    delete [] current;
}
