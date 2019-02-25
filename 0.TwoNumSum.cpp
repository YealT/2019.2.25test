
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> ret;

		for (int i = 0; i<nums.size(); i++)
		{
			for (int j = i + 1; j<nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}

	}
};



void main0()
{
	vector<int>nums;
	int a;
	while (cin >> a)
	{
		if (a == 0)
		break;
		nums.push_back(a);
	}
	int target;
	cin >> target;
	vector<int> ret = Solution().twoSum(nums, target);
	int i = 0;
}
