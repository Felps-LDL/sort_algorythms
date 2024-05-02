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
    optimize;

    int valores[6];
    for (int i = 0; i < 6; i++) cin >> valores[i];

    InsertionSort(valores, 6);

    for (int i = 0; i < 6; i++) cout << valores[i] << " ";
    cout << endl;

    return 0;
}
