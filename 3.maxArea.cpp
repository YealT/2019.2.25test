#include <vector>
#include<iostream>
using namespace std;


class Solution {
public:
		int maxArea_1(vector<int>& height) {//通过，但效果极差
			int n = height.size();
			int area=0,tmp_area = 0,tmp_height=0;
			for (int i = 0; i < n; i++)
			{
				for (int j = n-1; j >=i; j--)
				{
					tmp_height = height[i]< height[j] ? height[i] : height[j];
					tmp_area = tmp_height * (j - i);
					area = tmp_area > area ? tmp_area : area;
				}
			}
			return area;
		}

	int maxArea_2(vector<int>& height) {

		int n = height.size();
		int area = 0, tmp_area = 0, tmp_height = 0;
		int P1 = 0, P2 = n - 1;
		for (int i = 0; i < n; i++)
		{
			if (P2>P1)
			{
				tmp_height = height[P1]< height[P2] ? height[P1] : height[P2];
				tmp_area = tmp_height * (P2 - P1);
				area = tmp_area > area ? tmp_area : area;

				if (height[P1] < height[P2])
					P1++;
				else if (height[P2]<=height[P1])
					P2--;
			}
			else
				break;
		}
		return area;
	
		//bug1:输入为[1,1]时
		//bug2:
	}
};

void main3()
{
	vector<int >height_cin;
	int ret;
	while (cin >> ret)
	{
		if (ret != -1)
			height_cin.push_back(ret);
		else
			break;
	}
	ret = Solution().maxArea_2(height_cin);

	cout << ret;
}	