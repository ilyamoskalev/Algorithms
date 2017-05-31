#include <iostream>
#include <cassert>
#include <functional>
#include <vector>

using namespace std;

struct point {
    int x;
    int y;
};

void sort( vector<point> &arr, int n , std::function<bool( point, point )>& func){
    for( int i=1; i < n; i++ ){
        point tmp = arr[i];
        int j= i - 1;
        for( ; j >= 0 && func( arr [j], tmp ) ; --j ){
            arr[j + 1]=arr[j];
        }
        arr[j + 1] = tmp;
    }
}

bool func( point a, point b){
    return a.x > b.x || (a.x == b.x && a.y > b.y);
}





int main() {
    int n = 0;
    cin >> n;
    assert( n > 0 );
    vector<point> mas;
    for( int i = 0; i < n; i++ ){
        point tmp;
        cin >> tmp.x;
        cin >> tmp.y;
        mas.push_back(tmp);
    }
    std::function<bool( point , point)> f_func = func;
    sort(mas , n, f_func);
    for( int i = 0; i < n; i++ ){
        cout << mas[i].x << " ";
        cout << mas[i].y << "\n";
    }
    return 0;
}