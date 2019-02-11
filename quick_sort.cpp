#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int s_idx, int e_idx)
{
    if (s_idx >= e_idx)
    {
        return s_idx;
    }

    int pivot = v[e_idx];
    int i = s_idx - 1;
    int j = s_idx;
    while (j <= e_idx)
    {
        if (v[j] > pivot)
        {
            j += 1;
        }
        else
        {
            i += 1;
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            j += 1;
        }
    }
    return i;
}

void quick_sort(vector<int> &v, int s_idx, int e_idx)
{
    if (s_idx < e_idx)
    {
        int q = partition(v, s_idx, e_idx);
        quick_sort(v, s_idx, q - 1);
        quick_sort(v, q + 1, e_idx);
     }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    quick_sort(v, 0, 4);
    cout << "sorted order:" << endl;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;
}