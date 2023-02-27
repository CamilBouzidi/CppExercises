// Maximum Subarray
// Thank you Leetcode for the problem
// Given an integer array nums, find the subarray with the largest sum, and return its sum.
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
		int complement = target - num;
		if (seen.count(complement)) {
			std::vector<int> solution(seen.at(0), i);
			return solution;
		}
		seen[num] = i;
	}

	return {};
}s