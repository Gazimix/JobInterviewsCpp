#include <iostream>
#include <vector>

#include <algorithm>


void testSightSeeing();

void testNumIslands();

void testIntegralImage();

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






using namespace std;

int maxScoreSightseeingPair(std::vector<int>& values) {
	int largest = 0;
	int largest_idx = 0;
	int second_largest = 0;
	int second_largest_idx= 0;
	int best_score = 0;
	for (int i = 0; i < values.size(); ++i){

		if (values[i] >= largest){
			second_largest_idx = largest_idx;
			second_largest = largest;
			largest_idx = i;
			largest = values[i];

		}
		else if (values[i] >= second_largest){
			second_largest = values[i];
			second_largest_idx = i;
		}
		// int max = (largest_idx > second_largest_idx) ? largest_idx : second_largest_idx;
		// int min = (largest_idx > second_largest_idx) ? second_largest_idx : largest_idx;
		if (best_score < largest + second_largest){
			best_score = largest + second_largest;
		}
		--largest;
		--second_largest;
	}
	return best_score;
}



void numIslandsHelper(vector<vector<char>>& grid, int i, int j){
	if (j < grid[0].size() && i < grid.size() && i >= 0 && j >= 0)
	{
		if (grid[i][j] == '0')
		{
			return;
		}
		grid[i][j] = '0';
		numIslandsHelper(grid, i, j + 1);
		numIslandsHelper(grid, i + 1, j);
		numIslandsHelper(grid, i - 1, j);
		numIslandsHelper(grid, i, j - 1);
	}
}


int numIslands(vector<vector<char>>& grid) {
	int result = 0;
	for (int i = 0; i < grid.size(); ++i){
		for (int j = 0; j < grid[0].size(); ++j){
			if (grid[i][j] != '0'){
				numIslandsHelper(grid, i,j);
				++result;
			}
		}
	}
	return result;
}




int main()
{
	// testIntegralImage();
	// testSightSeeing();
	// testNumIslands();
}

void testIntegralImage()
{
	vector <vector <int>> v = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {7, 9, 8, 7, 6, 5, 4, 34, 32, 5}, {7, 9, 8, 7, 6, 5, 4, 34, 32,
														   5},{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
	print_vector(v);
	// auto res = inefficientVersion(v, 1);
	auto sums = sumUp(v);
	print_vector(sums);
	v = getResult(sums, 2);
	print_vector(v);
}

void testNumIslands()
{
	vector<char> c1 = {'1', '1', '1'};
	vector<char> c2 = {'0','1','0'};
	vector<char> c3 = {'1','1','1'};
	vector<vector<char>>c;
	c.push_back(c1);
	c.push_back(c2);
	c.push_back(c3);
	cout << numIslands(c);
}

void testSightSeeing()
{
	vector <int> v2 = {8, 1, 5, 2, 6};
	cout << maxScoreSightseeingPair(v2);
}



