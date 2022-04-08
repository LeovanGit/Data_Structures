#include <iostream>
#include <vector>

template <typename T>
std::vector<T> qsort(std::vector<T> & arr)
{
    if (arr.empty() || 1 == arr.size()) return arr;

    std::vector<T> center = { arr[0] }; // it can be any element
    std::vector<T> left; // elements less than center
    std::vector<T> right; // elements more than center

    size_t size = arr.size();

    for (size_t i = 1; i != size; ++i)
    {
        if (arr[i] < center[0]) left.push_back(arr[i]);
        else if (arr[i] > center[0]) right.push_back(arr[i]);
        else center.push_back(arr[i]);
    }

    // just reuse old vectors
    left = qsort(left);
    right = qsort(right);

    // insert in the end of vector another vector
    left.insert(left.end(), center.begin(), center.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
}
