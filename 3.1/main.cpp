//3_3. ​Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию. A[0..n-1] и B[0..m-1].
//
//n >> m. Найдите их пересечение. Требуемое время работы: O(m * log k), где k - позиция элементта B[m-1] в
//
//        массиве A.. В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом поиска
//
//элемента B[i-1].
//
//n, k ≤ 10000.

#include <iostream>

using namespace std;


int BinarySearch( int* arr, int element, int start, int finish)
{
    int first = start;
    int last = finish;
    while( first < last ) {
        int mid = ( first + last ) / 2;
        if( element <= arr[mid] )
            last = mid;
        else
            first = mid + 1;
    }
    return first;
}

void Search( int* mas1, int* mas2, size_t size_1, size_t size_2){
    int start = 0;
    int finish = 2;
    size_1 = BinarySearch(mas1, mas2[size_2 - 1], 0, size_1);
    for ( size_t i = 0; i < size_2 - 1; ++i){
        if(mas2[i] > mas1[size_1 - 1]){
            break;
        }
        while (mas2[i] > mas1[finish]){
            finish *= 2;
            if(finish > size_1){
                finish = size_1 - 1;
            }
        }
        start = BinarySearch(mas1, mas2[i], start, finish);
        if(mas1[start] == mas2[i]){
            cout << mas2[i] << " ";
        }
    }
    if( mas2[size_2 - 1] == mas1[size_1]){
        cout << mas2[size_2 - 1] << " ";
    }
}

int main() {
    size_t first = 0;
    size_t second = 0;
    cin >> first;
    cin >> second;
    int *mas1 = new int[first];
    for (int i = 0; i < first; ++i) {
        cin >> mas1[i];
    }
    int *mas2 = new int[second];
    for (int i = 0; i < second; ++i) {
        cin >> mas2[i];
    }
    Search(mas1, mas2, first, second);
    delete[] mas1;
    delete[] mas2;
}