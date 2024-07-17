#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void troca(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Retorna a posição do pivo
int particao(int arr[], int e, int d)
{
    int pos = e, pivo = arr[d];

    for (int i = e; i < d; i++)
    {
        if (arr[i] <= pivo)
        {
            troca(arr, pos, i);
            pos++;
        }
    }

    troca(arr, pos, d);

    return pos;
}

void QuickSort(int arr[], int e, int d)
{
    if (e >= d) return; // condição de parada

    int q = particao(arr, e, d);
    QuickSort(arr, e, q - 1);
    QuickSort(arr, q + 1, d);
}   

int main()
{
    int n;
    cin >> n;

    int valores[n];
    for (int i = 0; i < n; i++) cin >> valores[i];

    auto start = steady_clock::now();
    QuickSort(valores, 0, n - 1);
    auto end = steady_clock::now();

    for (int i = 0; i < n; i++) cout << valores[i] << " ";
    cout << endl;

    auto elapsed = end - start;
    cout << duration_cast<nanoseconds>(elapsed).count() / 1000000.0 << "ms\n";

    return 0;
}
