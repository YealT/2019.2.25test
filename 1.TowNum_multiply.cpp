
#include<string>
#include<iostream>

#define MAXLEN 110

using namespace std;

class tyx123 {
public:
	string multiply(string num1, string num2) {
		//1.Length prepare

		if (num1[0] == '0'||num2[0]=='0')
		{
			return "0";
		}
		int Len_num1, Len_num2, len_ret;
		Len_num1 = num1.length();
		Len_num2 = num2.length();
		len_ret = Len_num1 + Len_num2;
		//2.array init
		int * ret_int = new int[len_ret];
		memset(ret_int, 0, (len_ret)*sizeof(int));
		//3.ÿһ��λ�õľ���ֵ
		for (int i = Len_num1-1; i >=0; i--)
		{
			for (int j = Len_num2-1; j >=0; j--)
			{
				ret_int[j + i+1] += (num1[i] - '0') * (num2[j] - '0');
			}
		}
		//4.���λ
		for (int i = len_ret-1; i >= 0; i--)
			{
				if (ret_int[i] >= 10)
				{
					ret_int[i-1] += ret_int[i] / 10;
					ret_int[i] = ret_int[i] % 10;
				}
			}
		//5.intת��string���

		string num3(len_ret,0);
		int zuigaowei=0;
		for (int i = 0; i <= len_ret - 1; i++)
		{
			if (i == 0 && ret_int[i] == 0)
			{
				zuigaowei++;
				continue;
			}
			num3[i - zuigaowei] = ret_int[i] + '0';
		}
		return num3;
	}
};

//void main1()
void main1()
{
				//=============copy===============//
				//char a[MAXLEN];
				//char b[MAXLEN];
				//char c[2 * MAXLEN];
				//while (scanf("%s + %s", a, b) != EOF)
				//{
				//	//add(a, b, c);
				//	printf("%s + %s = ", a, b);
				//	puts(c);
				//}
				//return 0;
				//=============copy===============//
		string num1,num2;
		cin >> num1 >> num2;
		string ret = tyx123().multiply(num1, num2);
		cout << ret;
		int p = 0;
}

////================note:===========================//
//1.string->int : to_string() ; int->string :stoi()
//2.string->char : data() or s.c_str ;char->string forѭ��
//3.���⣺�������ַ��˷���
//  ��string���Ϊ110->��֪��Ҫ2���Ƶ�λ����370λ����