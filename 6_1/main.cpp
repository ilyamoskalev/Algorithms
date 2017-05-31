#include <iostream>
#include <cassert>


unsigned long long pyramide(int n) {

    long long int **table = new long long int * [n];
    for (int i = 0; i < n; i++) {
        table[i] = new long long int [n];
    }

    for( int i = 0; i < n; ++i ){
        for( int j = 0; j<n; ++j){
            table[i][j] = 0;
        }
    }

    table[0][0] = 1;
    table[1][1] = 1;
    int buffer = 0;
    for (int i = 2; i < n; i++)
    {
        table[i][i] = 1;
        for (int j = i - 1; j >= 0 ; j--)
        {
            buffer = i - j - 1;
            if (buffer < i / 2)
            {
                for (int k = 0; k <= buffer ; ++k)
                {
                    table[i][j] += table[buffer][k];
                }
            } else {
                for (int s = 0; s < j; s++)
                {
                    table[i][j] += table[buffer][s];
                }
            }
        }
    }

    unsigned long long result = 0;
    for (int i = 0; i < n; i++)
    {
        result += table[n - 1][i];
    }

    for (int i = 0; i < n; i++)
    {
        delete [] table[i];
    }
    delete [] table;
    return result;
}

int main() {
    int n = 0;
    std::cin >> n;
    assert( n > 0 );
    int **table = new int * [n];
    for (int i = 0; i < n; i++) {
        table[i] = new int [n];
    }
    std::cout <<  pyramide(n);
    return 0;
}