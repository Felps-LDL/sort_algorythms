#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int v[], int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void InsertionSort (int v[], int tam)
{
    for (int i = 1; i < tam; i++)
    {
        int temp = i;

        while(v[temp] < v[temp - 1] && temp >= 1)
        {
            swap(v, temp, temp - 1);
            temp--;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int valores[n];
    for (int i = 0; i < n; i++) cin >> valores[i];

    auto start = steady_clock::now();
    InsertionSort(valores, n);
    auto end = steady_clock::now();

    for (int i = 0; i < n; i++) cout << valores[i] << " ";
    cout << endl;

    auto elapsed = end - start;
    cout << duration_cast<nanoseconds>(elapsed).count() / 1000000.0 << "ms\n";

    return 0;
}
