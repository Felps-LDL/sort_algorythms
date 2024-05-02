#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << "x = " << x << endl;
#define ll long long
#define pii pair<int, int> 
#define piii pair<pair<int,int>, int>
#define ALL(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll

using namespace std;

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
    optimize;

    int valores[6];
    for (int i = 0; i < 6; i++) cin >> valores[i];

    QuickSort(valores, 0, 5);

    for (int i = 0; i < 6; i++) cout << valores[i] << " ";
    cout << endl;

    return 0;
}
