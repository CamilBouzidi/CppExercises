// Merge Sorted Array
// Thank you Leetcode for the problem
/*
You are given two integer arrays nums1 and nums2, 
sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
void mergeOnNums1(vector<int>& nums1, int m, vector<int>& nums2, int n);
void mergeOnNums1Efficient(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main()
{
    std::vector<int> nums1{ 2, 0 };
    std::vector<int> nums2{ 1 };
    int m = 1;
    int n = 1;
    merge(nums1, m, nums2, n);
    cin.get();
    return 0;
}

// Note that this version of the merge assumes you can return any vector, not necessarily nums1.
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> sol;
    int ind1 = 0;
    int ind2 = 0;
    // Look at ind1 for nums1, ind2 for nums2
    // Have we reached section of 0s at nums1[m]? if so, add the remaining values from nums2 to sol
    // Else, Take the smallest value between nums1[ind1] and nums2[ind2]. add it to sol
    // increment the "used index"
    // Repeat until loop reaches end of nums1
    if (n == 0)
    {
        sol = nums1;
        for (int j : sol) {
            std::cout << j << ' ';
        }
        return;
    }

    if (m == 0)
    {
        sol = nums2;
        for (int j : sol) {
            std::cout << j << ' ';
        }
        return;
    }
    for (int i = 0; i < m + n; i++) 
    {
        if (ind1 >= m && nums1[ind1] == 0)
        {
            sol.push_back(nums2[ind2]);
            ind2++;
        }
        else if (ind2 >= n)
        {
            sol.push_back(nums1[ind1]);
            ind1++;
        }
        else if ((nums1[ind1] <= nums2[ind2])) 
        {
            sol.push_back(nums1[ind1]);
            ind1++;
        }
        else 
        {
            sol.push_back(nums2[ind2]);
            ind2++;
        }
    }

    for (int j : sol) {
        std::cout << j << ' ';
    }

}

void mergeOnNums1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Use sort and its O(mlogm)
    for (int i = 0; i < n; i++) {
        nums1[m + i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}

void mergeOnNumsEfficient(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Thank you to Leodicap99 for the explanation
    // Two pointer approach in O(n+m)

    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
    while (i >= 0)
        nums1[k--] = nums1[i--];
    while (j >= 0)
        nums1[k--] = nums2[j--];
}