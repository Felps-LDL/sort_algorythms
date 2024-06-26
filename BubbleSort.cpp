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

void BubbleSort(int v[], int tam)
{
    for (int i = tam - 1; i >= 1; i--)
    {
        int troca = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1]) 
            {
              swap(v, j, j + 1);
              troca = 1;
            }
        }

        if (troca == 0) return;
    }
}

int main()
{
    int n;
    cin >> n;

    int valores[n];
    for (int i = 0; i < n; i++) cin >> valores[i];

    auto start = steady_clock::now();
    BubbleSort(valores, n);
    auto end = steady_clock::now();
  
    for (int i = 0; i < n; i++) cout << valores[i] << " ";
    cout << endl;

    auto elapsed = end - start;
    cout << duration_cast<nanoseconds>(elapsed).count() / 1000000.0 << "ms\n";

    return 0;
}
