#include <iostream>
#include <vector>

using namespace std;

int get_par(int idx)
{
    return (idx - 1) / 2;
}

int left_child(int idx)
{
    return (2 * idx + 1);
}

int right_child(int idx)
{
    return (2 * idx + 2);
}

void max_heapify(vector<int> &v, int idx, int size)
{
    if (idx >= size)
    {
        return;
    }

    int lc = left_child(idx);
    int rc = right_child(idx);

    int mi = idx;
    if (lc < size && v[lc] > v[idx])
    {
         mi = lc;
    }

    if (rc < size && v[rc] > v[mi])
    {
        mi = rc;
    }

    if (mi != idx)
    {
        int tmp = v[mi];
        v[mi] = v[idx];
        v[idx] = tmp;
        max_heapify(v, mi, size);
    }
}

void build_max_heap(vector<int> &v)
{
    int size = v.size();
    for (int i = size - 1 / 2; i >= 0; --i)
    {
        max_heapify(v, i, size);
    }
}

void heap_sort(vector<int> &v)
{
    build_max_heap(v);
    int size = v.size();
    for (int i = size - 1; i > 0; --i)
    {
        int tmp = v[i];
        v[i] = v[0];
        v[0] = tmp;
        max_heapify(v, 0, i);
    }
}

int main()
{
    vector<int> v = {5, 8, 9, 4, 5, 10, 20, 8, 22, 15, 47};
    heap_sort(v);
    cout << "sorted order:" << endl;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;
}