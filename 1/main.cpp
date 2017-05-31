

//  1_6. ​Дан массив целых чисел A[0..n). Не используя других массивов переставить элементы массива A в
//  обратном порядке за O(n).
//  n ≤ 10000.


#include <iostream>
#include <cassert>

using namespace std;

void reverseMas( int* mas , int size ){
    for( int i = 0; i < size / 2; ++i ){
        int tmp = mas[i];
        mas[i] = mas[size - i - 1];
        mas[size - i - 1] = tmp;
    }
}

void output( int* mas , int size ){
    for( int i = 0; i < size; ++i ){
        cout << mas[i] << " ";
    }
}

int main() {
    int count = 0;

    cin >> count;
    assert( count > 0 );

    int *mas = new int[count];

    for( int i = 0; i < count; ++i ){
        cin >> mas[i];
    }

    reverseMas( mas, count );
    output( mas, count );
    delete[] mas;
    return 0;
}