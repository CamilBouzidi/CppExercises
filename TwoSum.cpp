// Maximum Subarray
// Thank you Leetcode for the problem
// Given an array of integers numsand an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> twoSum(std::vector<int>& nums, int target);

int main()
{
	std::vector<int> vect{ 1,3,8 };
	std::cout << twoSum(vect, 9).size();
}

vector<int> twoSum(std::vector<int>& nums, int target) {
	// O(n) complexity. Thank you to www.nileshblog.com for the help
	// If current number's complement is present in hashmap, return current's and complement's indices
	// else, add current as key and index as value to hashmap
    unordered_map<int, int> seen;
    int size = nums.size();
    int num, complement = 0;
    for (int i = 0; i < size; i++) {
        num = nums[i];
        // cout << "num" << num << "at i" << i << "\n";
        int complement = target - num;
        // cout << "current complement: " << complement << "\n";
        if (seen.count(complement)) {
            // cout << "complement FOUND: " << seen.at(complement);
            std::vector<int> solution{ seen.at(complement), i };
            // cout << "solution: " << solution.size();
            return solution;
        }
        seen[num] = i;
    }
    return {};
}