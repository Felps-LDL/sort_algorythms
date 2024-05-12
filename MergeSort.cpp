#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

int main()
{
  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];

  auto start = steady_clock::now();
  MergeSort(arr, 0, n - 1);
  auto end = steady_clock::now();

  for (int i = 0; i < n; i++) cout << arr[i] << " ";

  cout << endl;

  auto elapsed = end - start;
  cout << duration_cast<nanoseconds>(elapsed).count() / 1000000.0 << "ms\n";
  return 0;
}
