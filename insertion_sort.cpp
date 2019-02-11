#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &arr)
{
     int size = arr.size();
     int j = 0;
     int val;

     for (int i = 1; i < size; ++i)
     {
	j = i - 1;
        val = arr[i];
        while (j >= 0)
        {
	    if (arr[j] > val)
            {
		arr[j + 1] = arr[j];
                --j;
            }
 	    else
            {
		break;
            }
        }
	arr[j + 1] = val;
     }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    insertion_sort(v);

    cout << "sorted output: " << endl;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
	cout << *it << ", ";
    }
    cout << endl;
}