#include <iostream>

#define BitsInWord 63

int digit(long long value, int bits_number) {
    return ( value >> ( BitsInWord - bits_number - 1 ) & 1 );
}



void BinaryQuickSort( unsigned long long* a, int l, int r, int w ) {
    if( r <= l || w > BitsInWord )
        return;
    int i = l, j = r;
    while( i != j ) {
        while( digit( a[i], w ) == 0 && i < j ) ++i;
        while( digit( a[j], w ) == 1 && i < j ) --j;
        std::swap( a[i], a[j] );
    }
    if( digit( a[r], w ) == 0 )
        ++j;
    BinaryQuickSort( a, l, j - 1, w + 1 );
    BinaryQuickSort( a, j, r, w + 1 );
}

int main() {
    int count = 0;
    std::cin >> count;
    unsigned long long* arr = new unsigned long long[count];
    for (int i = 0; i < count; ++i )
        std::cin >> arr[i];
    BinaryQuickSort(arr, 0, count - 1, 0);
    for (int i = 0; i < count; ++i )
    std::cout << arr[i] << " ";
    delete[] arr;
}