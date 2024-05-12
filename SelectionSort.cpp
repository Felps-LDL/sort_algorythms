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

int menor(int v[], int e, int d)
{
    int menor = e;

    for (int i = e + 1; i < d; i++)
    {
        if (v[i] < v[menor]) menor = i;
    }

    return menor;
}

void SelectionSort (int v[], int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        swap(v, i, menor(v, i, tam));
    }
}

int main()
{
    int n;
    cin >> n;

    int valores[n];
    for (int i = 0; i < n; i++) cin >> valores[i];

    auto start = steady_clock::now();
    SelectionSort(valores, n);
    auto end = steady_clock::now();

    for (int i = 0; i < n; i++) cout << valores[i] << " ";
    cout << endl;

    auto elapsed = end - start;
    cout << duration_cast<nanoseconds>(elapsed).count() / 1000000.0 << "ms\n";

    return 0;
}
