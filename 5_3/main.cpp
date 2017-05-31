#include <iostream>
#include <vector>
#include <cstring>

int64_t Merge( const int* a, int aLen, const int* b, int bLen, int* c ) {
    int i = 0, j = 0;
    int64_t res = 0;
    while( i < aLen && j < bLen ) {
        if( a[i] <= b[j] ) {
            c[i + j] = a[i];
            ++i;
        }
        else {
            c[i + j] = b[j];
            ++j;
            res += aLen - i;
        }
    }
    if( i == aLen ) {
        while( j < bLen ) {
            c[i + j] = b[j];
            ++j;
        }
    }
    else {
        while( i < aLen ) {
            c[i + j] = a[i];
            ++i;
        }
    }
    return res;
}

void MergeSort( int* a, int aLen , int64_t &res) {
    if( aLen <= 1 ) {
        return;
    }
    int firstLen = aLen / 2;
    int secondLen = aLen - firstLen;
    MergeSort( a, firstLen , res);
    MergeSort( a + firstLen, secondLen ,res);
    int* c = new int[aLen];
    res += Merge( a, firstLen, a + firstLen, secondLen, c );
    memcpy( a, c, sizeof( int ) * aLen );
    delete[] c;
}


int main() {
    int64_t res = 0;
    std::vector<int> arr;
    int tmp = 0;
    for(int i = 0; i<116;++i) {
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    MergeSort(&arr[0] , arr.size(), res);
    double sum = 0;
    for(int i = 0; i<116;++i)
        sum += (arr[i]-163.819)*(arr[i]-163.819);
    std::cout << sum/115 <<"\n";
}