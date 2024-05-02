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
    optimize;

    int valores[6];
    for (int i = 0; i < 6; i++) cin >> valores[i];

    SelectionSort(valores, 6);

    for (int i = 0; i < 6; i++) cout << valores[i] << " ";
    cout << endl;

    return 0;
}
