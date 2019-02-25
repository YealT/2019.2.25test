#include<vector>
#include<iostream>
using namespace std;

//==============µÝ¹éËã·¨Ì½Ë÷==============
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> All_ret_str;
		vector<string > Per_ret_str;
		if (n < 1)
		{
			return All_ret_str;
		}
		int *Permited_Pos = new int[n];
		recurrence_pos(Permited_Pos, 0, n);

	}

	void recurrence_pos(int * Permited_Pos, int row_idx, int N)
	{
		for (int i = 0; i < N; i++)
		{
			if (ispermited_pos(Permited_Pos, row_idx + 1,i ))
			{
				Permited_Pos[row_idx] = i;
				recurrence_pos(Permited_Pos, row_idx+1,N);
			}
		}    

	}

	bool ispermited_pos(int *Permited_Pos,int row_idx,int col_idx)
	{	
		int flag = 0;
		for (int i = 0; i < row_idx; i++)
		{
			if (Permited_Pos[i] != col_idx && i - row_idx != Permited_Pos[i] - col_idx);
			flag++;
		}
		if (flag == row_idx)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


void main()
{
	int n;
	cin >> n;
	vector<vector<string>> ret;
	
	ret=Solution().solveNQueens(n);

	int p = 4l;
}



