#include <iostream>

using namespace std;

void reverse( int* mas , int size ){
    int tmp = 0;
    for( int i = 0; i < size / 2; ++i){
        tmp = mas[i];
        mas[i] = mas[size - i - 1];
        mas[size - i - 1] = tmp;
    }
}

void output( int* mas , int size){
    for( int i = 0; i < size; ++i){
        cout << mas[i] << " ";
    }
}


int main() {
    int n = 0;
    cin >> n;
    if( n > 0 ) {
        int *mas = new int[n];
        for( int i = 0; i < n; ++i ){
            cin >> mas[i];
        }
        reverse(mas, n);
        output(mas, n);
        delete[] mas;
    }else{
        cout << "incorrect input";
    }
    return 0;
}