#include <iostream>
#include <array>
#include <cassert>
#include <vector>

class heap{
public:
    heap( std::vector<int> &arr );

    int CountSum();

private:
    void BuildHeap();

    void SiftDown( int i );

    int ExtractMin();

    std::vector<int> _arr;
    int _count;
};

void heap::SiftDown( int i )

{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if( left < _count && _arr[left] < _arr[i] )
        largest = left;
    if( right < _count && _arr[right] < _arr[largest] )
        largest = right;
    if( largest != i ) {
        std::swap( _arr[i], _arr[largest] );
        SiftDown( largest );
    }
}

void heap::BuildHeap()
{
    for( int i = _count/2 - 1; i >= 0; --i ){
        SiftDown( i );
    }
}


int heap::ExtractMin()
{
    int result = _arr[0];
    _arr[0] = _arr[_count - 1];
    --_count;
    if( _count != 0 ) {
        SiftDown( 0 );
    }
    return result;
}

int heap::CountSum(){
    int sum = 0;
    while( _count != 1){
        int tmp1 = ExtractMin();
        _arr[0] += tmp1;
        sum += _arr[0];
        SiftDown(0);
    }
    return sum;
}

heap::heap(std::vector<int> &arr) {
    _arr.swap( arr );
    _count = _arr.size();
    BuildHeap();
}


int main() {
    int count = 0;
    std::cin >> count;
    assert(count > 0 );
    std::vector<int> arr;
    for( int i = 0; i < count; ++i){
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    heap Heap( arr );
    std::cout << Heap.CountSum();
}