#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;


/*MERGE SORT*/
void Merge(int arr[], int l, int m, int r)
{
  vector<int> left, right;

  for (int i = l; i <= r; i++)
  {
     if (i <= m) left.push_back(arr[i]);
     else right.push_back(arr[i]);
  }

  left.push_back(INT_MAX);
  right.push_back(INT_MAX);

  int esq = 0, dir = 0;

  for (int i = l; i <= r; i++)
  {
    if (left[esq] <= right[dir])
    {
      arr[i] = left[esq];
      esq++;
    }
    else
    {
      arr[i] = right[dir];
      dir++;
    }
  }
}

void MergeSort(int arr[], int l, int r)
{
  if (l >= r) return;

  int mid = (l + r) / 2;

  MergeSort(arr, l, mid);
  MergeSort(arr, mid + 1, r);
  Merge(arr, l, mid, r);
}
/*MERGE SORT*/

///////////////////////////////////////////////////////////////////////

/*INSERTION SORT*/
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
/*INSERTION SORT*/

///////////////////////////////////////////////////////////////////////

/*BUBBLE SORT*/
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
/*BUBBLE SORT*/

///////////////////////////////////////////////////////////////////////

/*SELECTION SORT*/
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
/*SELECTION SORT*/

int main()
{
    /*TAMANHO DO VETOR QUE SERÁ TESTADO*/
    int n;
    cin >> n; 
    int valores[n];

    auto selectiontime = steady_clock::duration::zero();
    auto insertiontime = steady_clock::duration::zero();
    auto bubbletime = steady_clock::duration::zero();
    auto mergetime = steady_clock::duration::zero();

    /*SERÁ TESTADO 5 VEZES CADA VETOR DE TAMANHO DIFERENTE*/
    for( int i = 0 ; i < 5 ; i++ )
    {
        int valorestest[n];

        cout << "TESTE " << i << ":" << endl;
        for( int i = 0 ; i < n ; i++ ) cin >> valores[i];
        
        for( int i = 0 ; i < n ; i++ ) valorestest[i] = valores[i];
        auto startselection = steady_clock::now();
        SelectionSort(valorestest, n);
        auto endselection = steady_clock::now();
        auto elapsedselection = endselection - startselection;
        selectiontime += elapsedselection;

        for( int i = 0 ; i < n ; i++ ) valorestest[i] = valores[i];
        auto startinsertion = steady_clock::now();
        InsertionSort(valorestest, n);
        auto endinsertion = steady_clock::now();
        auto elapsedinsertion = endinsertion - startinsertion;
        insertiontime += elapsedinsertion;

        for( int i = 0 ; i < n ; i++ ) valorestest[i] = valores[i];
        auto startbubble = steady_clock::now();
        BubbleSort(valorestest, n);
        auto endbubble = steady_clock::now();
        auto elapsedbubble = endbubble - startbubble;
        bubbletime += elapsedbubble;

        for( int i = 0 ; i < n ; i++ ) valorestest[i] = valores[i];
        auto startmerge = steady_clock::now();
        MergeSort(valorestest, 0, n - 1);
        auto endmerge = steady_clock::now();
        auto elapsedmerge = endmerge - startmerge;
        mergetime += elapsedmerge;

    }

    selectiontime /= 5;
    insertiontime /= 5;
    bubbletime /= 5;
    mergetime /= 5;

    
    cout << "SELECTION SORT TIME:" << duration_cast<nanoseconds>(selectiontime).count() / 1000000.0 << "ms\n";
    cout << "INSERTION SORT TIME:" << duration_cast<nanoseconds>(insertiontime).count() / 1000000.0 << "ms\n";
    cout << "BUBBLE SORT TIME:" << duration_cast<nanoseconds>(bubbletime).count() / 1000000.0 << "ms\n";
    cout << "MERGE SORT TIME:" << duration_cast<nanoseconds>(mergetime).count() / 1000000.0 << "ms\n";

    return 0;    
}