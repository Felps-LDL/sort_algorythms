#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void heapSort(int arr[], int n)
{
    // Convert array to vector
    vector<int> v(arr, arr + n);

    // Convert vector to Max Heap
    make_heap(v.begin(), v.end());

    // Sort Max Heap
    sort_heap(v.begin(), v.end());

    // Copy sorted vector back to array
    copy(v.begin(), v.end(), arr);
}

int main()
{
    int tam;
    cin >> tam;

    int arr[tam];
    for (int i = 0; i < tam; i++) cin >> arr[i];

    auto start = steady_clock::now();
    heapSort(arr, tam);
    auto end = steady_clock::now();

    auto elapsed = end - start;
    cout << duration_cast<nanoseconds>(elapsed).count() / 1000000.0 << "ms\n";
    cout << endl;
}
