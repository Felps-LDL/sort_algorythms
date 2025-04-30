#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <ctime>

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

    auto selectiontime = 0;
    auto insertiontime = 0;
    auto bubbletime = 0;
    auto mergetime = 0;

    vector<double> selectionTIMES(5);
    vector<double> insertionTIMES(5);
    vector<double> bubbleTIMES(5);
    vector<double> mergeTIMES(5);

    /*SERÁ TESTADO 5 VEZES CADA VETOR DE TAMANHO DIFERENTE*/
    for( int i = 0 ; i < 5 ; i++ )
    {
        int valorestest[n];

        unsigned seed = time(0);
        srand(seed);
        for( int j = 0 ; j < n ; j++ )
        {
            valores[j] = rand();
        }
        
        for( int j = 0 ; j < n ; j++ ) valorestest[j] = valores[j];
        auto startselection = steady_clock::now();
        SelectionSort(valorestest, n);
        auto endselection = steady_clock::now();
        auto elapsedselection = endselection - startselection;
        selectiontime += duration_cast<nanoseconds>(elapsedselection).count();
        selectionTIMES[i] = duration_cast<nanoseconds>(elapsedselection).count();

        for( int j = 0 ; j < n ; j++ ) valorestest[j] = valores[j];
        auto startinsertion = steady_clock::now();
        InsertionSort(valorestest, n);
        auto endinsertion = steady_clock::now();
        auto elapsedinsertion = endinsertion - startinsertion;
        insertiontime += duration_cast<nanoseconds>(elapsedinsertion).count();
        insertionTIMES[i] = duration_cast<nanoseconds>(elapsedinsertion).count();


        for( int j = 0 ; j < n ; j++ ) valorestest[j] = valores[j];
        auto startbubble = steady_clock::now();
        BubbleSort(valorestest, n);
        auto endbubble = steady_clock::now();
        auto elapsedbubble = endbubble - startbubble;
        bubbletime += duration_cast<nanoseconds>(elapsedbubble).count();
        bubbleTIMES[i] = duration_cast<nanoseconds>(elapsedbubble).count();

        for( int j = 0 ; j < n ; j++ ) valorestest[j] = valores[j];
        auto startmerge = steady_clock::now();
        MergeSort(valorestest, 0, n - 1);
        auto endmerge = steady_clock::now();
        auto elapsedmerge = endmerge - startmerge;
        mergetime += duration_cast<nanoseconds>(elapsedmerge).count();
        mergeTIMES[i] = duration_cast<nanoseconds>(elapsedmerge).count();

    }

    selectiontime /= 5;
    insertiontime /= 5;
    bubbletime /= 5;
    mergetime /= 5;

    /*VARIÁVEIS DO DESVIO PADRÃO*/
    auto varSelection = 0;
    auto varInsertion = 0;
    auto varBubble = 0;
    auto varMerge = 0;

    for( int i = 0 ; i < 5 ; i++ )
    {
        auto v1 = selectionTIMES[i] - selectiontime;
        varSelection += v1 * v1;

        auto v2 = insertionTIMES[i] - insertiontime;
        varInsertion += v2 * v2;

        auto v3 = bubbleTIMES[i] - bubbletime;
        varBubble += v3 * v3;

        auto v4 = mergeTIMES[i] - mergetime;
        varMerge += v4 * v4;
    }

    auto dpSelection = sqrt(varSelection / 5);
    auto dpInsertion = sqrt(varInsertion / 5);
    auto dpBubble = sqrt(varBubble / 5);
    auto dpMerge = sqrt(varMerge / 5);
    
    cout << "SELECTION SORT TIME: " << selectiontime / 1000000.0 << "ms -------- DPadrao: " << dpSelection / 1000000.0  << "ms\n";
    cout << "INSERTION SORT TIME: " << insertiontime / 1000000.0 << "ms -------- DPadrao: " << dpInsertion / 1000000.0  << "ms\n";
    cout << "BUBBLE SORT TIME: " << bubbletime / 1000000.0 << "ms -------- DPadrao: " << dpBubble / 1000000.0  << "ms\n";
    cout << "MERGE SORT TIME: " << mergetime / 1000000.0 << "ms -------- DPadrao: " << dpMerge / 1000000.0  << "ms\n";

    return 0;    
}