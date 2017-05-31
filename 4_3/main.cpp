#include <iostream>


int partition(int* &arr, int start, int end)
{
    if ( start == end )
        return start;

    int pivot = rand() % (end - start + 1) + start;
    std::swap(arr[pivot], arr[end]);
    pivot = end;
    int i = start;
    int j = i;
    while ( j < end )
    {
        if ( arr[j] <= arr[pivot] )
        {
            std::swap(arr[j], arr[i]);
            ++i;
            ++j;
        }
        while ( arr[j] > arr[pivot] ) ++j;
    }
    std::swap(arr[i], arr[pivot]);
    pivot = i;
    return pivot;
}

int findElem(int* &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int p = -1;
    while ( p != k )
    {
        p = partition(arr, start, end);
        if ( k > p )
            start = p + 1;
        if ( k < p )
            end = p - 1;
    }
    return arr[k];
}

int main()
{
    int n = 0;
    int k = 0;
    std::cin >> n;
    std::cin >> k;
    int* arr = new int[n];
    for( int i = 0; i < n; ++i)
        std::cin >> arr[i];
    std::cout << findElem(arr, n, k);
    delete[] arr;
    return 0;
}
