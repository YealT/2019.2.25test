#include <string>
#include <iostream>
#include<deque>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		
		if (s.length() == 0)
			return 0;
		if (s.length() == 1)
			return 1;
		// char *tmp;
		int ret_max,ret_tmp,sub_flag;
		ret_max = ret_tmp = sub_flag = 0;
		deque<char>None_dup;
		const char *tmp_s;
		//tmp_s = new char[s.length()];
		tmp_s = s.c_str();
		None_dup.push_back(s[0]);
		ret_tmp++;
		for (int i = 1; i < s.length(); i++)
		{
			sub_flag = ret_tmp;
			for (deque<char>::iterator iter = None_dup.begin(); iter != None_dup.end(); ++iter)
			{			
				if (s[i] == *iter)
				{
					break;
				}
				sub_flag--;
			}
			if (sub_flag == 0)
			{
				None_dup.push_back(s[i]);
				ret_tmp++;
			}
			if (sub_flag > 0)
			{
				for (int j = 0; j < ret_tmp - sub_flag + 1; j++)
				{
					None_dup.pop_front();
				}
				None_dup.push_back(s[i]);
				ret_tmp = sub_flag ;
			}
			if (ret_tmp > ret_max)
			{
				ret_max = ret_tmp;
			}
		}
		//delete []tmp_s;
		return ret_max;
	}
};


void main2()
{
	string s;
	cin >> s;
	int ret = Solution().lengthOfLongestSubstring(s);
	cout << ret;
	int i = 0;
}