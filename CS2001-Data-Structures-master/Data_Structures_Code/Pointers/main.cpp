#include <iostream>
#include <type_traits>

using namespace std;

int main() {



    int *ptr, score,test_int_to_check_constPtr;
    score = 1000;
    ptr = &score;
    test_int_to_check_constPtr = 2000;

    int* const ptr1 = &score;


    cout<<"the score is "<<*ptr1<<endl;



    cout<<"The size of scrose is : "<<sizeof(*ptr)<<endl;


    cout << "The address of score is : " << &score << endl;
    cout << "The address stored in ptr is :" << ptr << endl;


    cout << "the size of ptr is :" << sizeof(ptr) << endl;
    cout << "The size of int test_int is :" << sizeof(score) << endl;


    if (is_pointer<decltype(ptr)>::value)
        cout << "the ptr is a pointer " << endl;
    else
        cout << "the ptr is not a pointer" << endl;
    if (is_pointer<decltype(score)>::value)
        cout << "The score is a pointer" << endl;
    else
        cout << "The score is not a pointer" << endl;


    return 0;
}
