#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

/*
��һɫ���齫����֮һ��ָ��һ�ֻ�ɫ����������ɵĺ��ơ�
����1-9��ÿ�����������4����
���ǲ����Ǿ��廨ɫ������ֻ��������ϡ�
���ӣ�����һ�����ƣ���: 111, 222, 333, ..., 999
˳�ӣ������������ƣ���: 123, 234, 345, ..., 789
���ӣ�������ͬ���ƣ���: 11, 22, 33, ..., 99
��Ҫʵ��һ�������жϸ����ƣ��Ƿ���Ժ��ƣ����ƣ���

����Ҫ��:
- �齫������ֻ���� 2, 5, 8, 11, 14
- �����ƿ�����ϳɣ���1�����������������ǿ��ӻ�˳��
������ - "11" -> "11", 1���ӣ����Ժ���
- "11122233" -> "111"+"222"+"33", 2���ӣ�1���ӣ�����
- "11223344567" -> "11"+"234"+"234"+"567", 1���ӣ�3˳�ӣ�����
-> "123"+"123"+"44"+"567", ��һ����ϣ�Ҳ����

��������:
�Ϸ�C�ַ�����ֻ����'1'-'9'�����Ѿ�����С����˳���źã��ַ������Ȳ�����15��ͬһ������������4�Σ���ʵ�������

�������:
C�ַ�����"yes"����"no"
*/

int test_��һɫ()
{
	string str;
	while (cin >> str)
	{
		//����������
		if (str.size()!=2 && str.size() != 5 && str.size() != 8
			&& str.size() != 11 && str.size() != 14)
		{
			cout << "no" << endl;
			continue;
		}
		//��������
		if (str.size()==2)
		{
			if (str[0]==str[1])
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
			continue;
		}

		bool flag = false;
		for (size_t i = 0; i < str.size() - 1; i++)
		{
			if (str[i]==str[i+1])
			{
				flag = false;
				//�ж��ӣ�����������ȱ���������
				//δ�������ַ�
				string tmp = str.substr(0, i) + str.substr(i + 2);
				//����ȫ����
				//next_permutation() ������һ�����е������У��������п��ܵ��ֵ����е���һ������
				do
				{
					int kezi = 0, shunzi = 0;
					flag = false;
					for (size_t j = 0; j < tmp.size()-2;)
					{
						if (tmp[j]==tmp[j+1]&&tmp[j+1]==tmp[j+2])
						{
							kezi++;
							j += 3;
						}
						else if(tmp[j]+1==tmp[j+1]&&tmp[j+1]+1==tmp[j+2])
						{
							shunzi++;
							j += 3;
						}
						else
						{
							j++;
						}
					}
					//����kezi��˳��
					if (kezi*3+shunzi*3== tmp.size())
					{
						flag = true;
						break;
					}
				} while (next_permutation(tmp.begin(), tmp.end()));
				if (flag)
				{
					break;
				}
			}
		}
		if (flag)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}