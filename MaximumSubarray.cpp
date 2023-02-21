// Maximum Subarray
// Thank you Leetcode for the problem
// Given an integer array nums, find the subarray with the largest sum, and return its sum.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumSubarray(std::vector<int>& nums);

int main()
{
	std::vector<int> vect{ -2,1,-3,4,-1,2,1,-5,4 };
	std::cout << maximumSubarray(vect);
}

int maximumSubarray(std::vector<int>& nums) {

	// Keep local max and compare it to current absolute max
	// O(n) complexity.
	// Uses functional programming
	int current_sum = nums[0];
	int max_sum = nums[0];
	int num_size = nums.size();

	for (int i = 1; i < num_size; i++) {
		current_sum = max(nums[i], current_sum + nums[i]);
		max_sum = max(current_sum, max_sum);
	}

	return max_sum;
}