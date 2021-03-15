#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector <vector <int>> inefficientVersion(vector <vector <int>> &mat, int k)
{
	int default_value = 0;
	int M = mat.size();
	int N = mat[0].size();
	vector <vector <int>> sum(M);
	for (int i = 0; i < M; i++)
	{
		sum[i] = vector <int>(N, 0);
	}
	for (int i = 0; i < mat.size(); ++i)
	{
		for (int j = 0; j < mat[0].size(); ++j)
		{
			int current_sum = 0;
			for (int m = -k; m <= k; ++m)
			{
				for (int n = -k; n <= k; ++n)
				{
					if ((i + m >= 0 && j + n >= 0) && (i + m < mat.size() && j + n < mat[0].size()))
					{
						current_sum += mat[i + m][j + n];
					}
				}
			}
			sum[i][j] = current_sum;
		}
	}
	return sum;
}

void print_vector(const vector <vector <int>> &res)
{
	for (auto &a : res)
	{
		for (auto &b: a)
		{
			cout << b << " ";
		}
		cout << endl;
	}
	cout << endl;
}

vector <vector <int>> sumUp(vector <vector <int>> &mat)
{
	int default_value = 0;
	int M = mat.size();
	int N = mat[0].size();
	vector <vector <int>> sum(M);
	for (int i = 0; i < M; i++)
	{
		sum[i] = vector <int>(N, 0);
	}
	for (int i = 0; i < mat.size(); ++i)
	{
		int current_sum = 0;
		for (int j = 0; j < mat[0].size(); ++j)
		{
			current_sum += mat[i][j];
			if (i - 1 >= 0)
			{
				sum[i][j] = sum[i - 1][j] + current_sum;
			}
			else
			{
				sum[i][j] = current_sum;
			}
		}
	}
	return sum;
}

vector <vector <int>> getResult(vector <vector <int>> sums, int K)
{
	int M = sums.size();
	int N = sums[0].size();
	vector <vector <int>> res(M);
	for (int i = 0; i < M; i++)
	{
		res[i] = vector <int>(N, 0);
	}
	for (int i = 0; i < sums.size(); ++i)
	{
		for (int j = 0; j < sums[0].size(); ++j)
		{
			int mini = min(i + K, M - 1);
			int minj = min(j + K, N - 1);
			int complete_res = sums[mini][minj];
			if (i - K - 1 >= 0 && j - K - 1 >= 0)
			{
				int maxj = min(N-1, j+K);
				int maxi = min(M-1, i+K);
				complete_res += sums[i - K - 1][j - K - 1];
				complete_res -= sums[i - K - 1][maxj];
				complete_res -= sums[maxi][j - K - 1];
			}
			else if (i - K - 1 >= 0)
			{
				complete_res -= sums[i - K - 1][minj];
			}
			else if (j - K - 1 >= 0)
			{
				complete_res -= sums[mini][j - K - 1];
			}
			res[i][j] = complete_res;
		}
	}
	return res;
}

int main()
{
	vector <vector <int>> v = {{1,2,3,4,5,6,7,8,9,10},{7,9,8,7,6,5,4,34,32,5},{7,9,8,7,6,5,4,34,32,
												  5},{1,2,3,4,5,6,7,8,9,10}};
	print_vector(v);
	// auto res = inefficientVersion(v, 1);
	auto sums = sumUp(v);
	print_vector(sums);
	v = getResult(sums, 2);
	print_vector(v);
}



