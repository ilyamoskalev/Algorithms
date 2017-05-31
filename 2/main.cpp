//2_4.​ “Считалочка”. В круг выстроено N человек, пронумерованных числами от 1 до N. Будем исключать
//каждого k-ого до тех пор, пока не уцелеет только один человек. (Например, если N=10, k=3, то сначала
//умрет 3-й, потом 6-й, затем 9-й, затем 2-й, затем 7-й, потом 1-й, потом 8-й, за ним - 5-й, и потом 10-й. Таким
//образом, уцелеет 4-й.) Необходимо определить номер уцелевшего.
//N, k ≤ 10000.
#include <iostream>
#include <cassert>

using namespace std;

int count( int size , int step ){
    int CurrentPlayer = -1,
        CurrentSize = size;
    bool* mas = new bool[size];
    for( int i = 0; i < size; ++i ){
        mas[i] = true;
    }
    while( CurrentSize != 1 ){
        for( int i = 0; i < step; ++i ){
            ++CurrentPlayer;
            if( CurrentPlayer == size ) {
                CurrentPlayer = 0;
            }
            while( !mas[CurrentPlayer] ) {
                ++CurrentPlayer;
                if ( CurrentPlayer == size ) {
                    CurrentPlayer = 0;
                }
            }
        }
        mas[CurrentPlayer] = false;
        --CurrentSize;
    }
    CurrentPlayer = 0;
    while( !mas[CurrentPlayer]){
        ++CurrentPlayer;
    }
    delete[] mas;
    return ++CurrentPlayer;
}

int main() {
    int size = 0, step = 0;
    cin >> size;
    cin >> step;
    assert( size > 0 );
    assert( step > 0 );
    cout << count( size , step );
    return 0;
}