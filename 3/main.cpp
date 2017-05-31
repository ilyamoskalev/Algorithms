#include <iostream>
#include <cassert>

using namespace std;


int BinarySearch( int* arr, int count, int element, int start)

{
    int first = start;
    int last = count;
    while( first < last ) {
        int mid = ( first + last ) / 2;
        if( element <= arr[mid] )
            last = mid;
        else
            first = mid + 1;
    }
    return first;

}

int main() {
    int first = 0;
    int second = 0;
    cin >> first;
    cin >> second;
    int* mas1 = new int[first];
    for( int i = 0; i < first; ++i){
        cin >> mas1[i];
    }
    int* mas2 = new int[second];
    for( int i = 0; i < second; ++i){
        cin >> mas2[i];
    }
    int start = 0;
    for( int i = 0; i < second; ++i ) {
        start = BinarySearch(mas1  , first , mas2[i], start);
        if(mas1[start] == mas2[i]){
            cout << mas2[i] << " ";
        }
    }
    delete[] mas1;
    delete[] mas2;
    return 0;
}