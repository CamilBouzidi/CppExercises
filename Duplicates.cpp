// Duplicate
// Thank you Leetcode for problem and solution!
// Given an integer array nums, 
// return true if any value appears at least twice in the array, 
// and return false if every element is distinct.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool containsDuplicateLong(std::vector<int>& nums);
bool containsDuplicateShorter(std::vector<int>& nums);

int main()
{
	std::vector<int> vect{ 0, 1, 2, 3, 1 };
	std::cout << containsDuplicateShorter(vect);
}

bool containsDuplicateLong(std::vector<int>& nums) {
	
	// Just iterate through
	// O(n^2) complexity.
	// This is not optimal, as you would quickly have a long search
	int current_ind = 0;
	int num_size = nums.size();
	for (int i = 0; i < num_size; i++) {
		current_ind = i;
		for (int j = 0; j < num_size; j++) {
			if (j == current_ind)
				continue;
			if (nums[j] == nums[current_ind])
				return true;
		}
	}
	return false;
}

bool containsDuplicateShorter(std::vector<int>& nums) {

	// Sort the array
	// Compare entry to the one before it, starting at n = 1.
	// O(nlogn) complexity because of the Cpp sorting.
	// Much faster than previous solution.
	sort(nums.begin(), nums.end());
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i - 1] == nums[i])
			return true;
	}
	return false;
}