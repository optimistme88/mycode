#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int s_idx, int mid, int e_idx)
{
    if (mid < s_idx || (e_idx < mid + 1))
    {
        return;
    }
    vector<int> v1(mid - s_idx + 1);
    vector<int> v2(e_idx - mid);
    int n = (mid - s_idx + 1);

    for (int i = 0; i < n; ++i)
    {
        v1[i] = v[s_idx + i];
    }

    n = (e_idx - mid);
    for (int i = 0; i < n; ++i)
    {
        v2[i] = v[mid + 1 + i];
    }

    // merge v1 and v2
    n = (e_idx - s_idx + 1);
    int i = 0;
    int j = 0;
    int k = 0;
    
    while (k < n)
    {
         if (i < v1.size() && j < v2.size())
         {
             if (v1[i] < v2[j])
             {
                  v[s_idx + k] = v1[i];
                  ++i;
             }
             else
             {
                 v[s_idx + k] = v2[j];
                 ++j;
             }
         }
         else if (i < v1.size())
         {
             v[s_idx + k] = v1[i];
             ++i;
         }
         else
         {
             v[s_idx + k] = v2[j];
             ++j;
         }
         ++k;
    }
}

void merge_sort(vector<int> &v, int s_idx, int e_idx)
{
    if (s_idx < e_idx)
    {
        int mid = s_idx + (e_idx - s_idx) / 2;
        merge_sort(v, s_idx, mid);
        merge_sort(v, mid + 1, e_idx);
        merge(v, s_idx, mid, e_idx);
    }

}

int main()
{
    vector<int> v = {7, 6, 5, 4, 3, 2, 1};
    merge_sort(v, 0, v.size() - 1);
    cout << "sorted order:" << endl;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;
}