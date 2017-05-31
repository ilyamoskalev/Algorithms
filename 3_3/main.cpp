#include <iostream>
#include <array>
#include <cassert>
#include <vector>

struct point{
    int coordinate;
    bool isBegin;
};

void siftDown(std::vector<point> &arr, int index, int size ){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if( left < size && arr[left].coordinate > arr[index].coordinate )
        largest = left;
    if( right < size && arr[right].coordinate > arr[largest].coordinate )
        largest = right;
    if( largest != index ){
        std::swap( arr[index], arr[largest] );
        siftDown( arr, largest, size );
    }
}

void buildHeap( std::vector<point> &arr ){
    for( int i = arr.size() / 2 - 1; i >= 0; --i )
        siftDown( arr, i, arr.size() );
}

void heapSort( std::vector<point> &arr ){
    int heapSize = arr.size();
    buildHeap( arr );
    while( heapSize > 1 ){
        std::swap( arr[0] , arr[heapSize - 1]);
        --heapSize;
        siftDown( arr, 0, heapSize);
    }
}

int length(std::vector<point> arr){
    int layer = 0, len = 0, begin_pos = 0;
    for (int i = 0; i < arr.size(); i++){
        if(arr[i].isBegin == 1){
            layer++;
            if (layer == 1)
                begin_pos = arr[i].coordinate;
        }
        else{
            layer--;
            if(layer == 0)
                len += arr[i].coordinate - begin_pos;
        }
    }
    return len;
}

int main() {
    int count = 0;
    std::cin >> count;
    assert( count > 0 );
    std::vector<point> arr;
    for( int i = 0; i < count; ++i){
        point tmp;
        std::cin >> tmp.coordinate;
        tmp.isBegin = 1;
        arr.push_back(tmp);
        std::cin >> tmp.coordinate;
        tmp.isBegin = 0;
        arr.push_back(tmp);
    }
    heapSort(arr);
    std::cout << length(arr);
}


