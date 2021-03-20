#include <iostream>
#include <vector>
#include <string>
// #include <unordered_map>
// #include <algorithm>
// #include <map>
//
//
//
using namespace std;
//
// vector <vector <int>> inefficientVersion(vector <vector <int>> &mat, int k)
// {
// 	int default_value = 0;
// 	int M = mat.size();
// 	int N = mat[0].size();
// 	vector <vector <int>> sum(M);
// 	for (int i = 0; i < M; i++)
// 	{
// 		sum[i] = vector <int>(N, 0);
// 	}
// 	for (int i = 0; i < mat.size(); ++i)
// 	{
// 		for (int j = 0; j < mat[0].size(); ++j)
// 		{
// 			int current_sum = 0;
// 			for (int m = -k; m <= k; ++m)
// 			{
// 				for (int n = -k; n <= k; ++n)
// 				{
// 					if ((i + m >= 0 && j + n >= 0) && (i + m < mat.size() && j + n < mat[0].size()))
// 					{
// 						current_sum += mat[i + m][j + n];
// 					}
// 				}
// 			}
// 			sum[i][j] = current_sum;
// 		}
// 	}
// 	return sum;
// }
//
// void print_vector(const vector <vector <int>> &res)
// {
// 	for (auto &a : res)
// 	{
// 		for (auto &b: a)
// 		{
// 			cout << b << " ";
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;
// }
//
// vector <vector <int>> sumUp(vector <vector <int>> &mat)
// {
// 	int default_value = 0;
// 	int M = mat.size();
// 	int N = mat[0].size();
// 	vector <vector <int>> sum(M);
// 	for (int i = 0; i < M; i++)
// 	{
// 		sum[i] = vector <int>(N, 0);
// 	}
// 	for (int i = 0; i < mat.size(); ++i)
// 	{
// 		int current_sum = 0;
// 		for (int j = 0; j < mat[0].size(); ++j)
// 		{
// 			current_sum += mat[i][j];
// 			if (i - 1 >= 0)
// 			{
// 				sum[i][j] = sum[i - 1][j] + current_sum;
// 			}
// 			else
// 			{
// 				sum[i][j] = current_sum;
// 			}
// 		}
// 	}
// 	return sum;
// }
//
// vector <vector <int>> getResult(vector <vector <int>> sums, int K)
// {
// 	int M = sums.size();
// 	int N = sums[0].size();
// 	vector <vector <int>> res(M);
// 	for (int i = 0; i < M; i++)
// 	{
// 		res[i] = vector <int>(N, 0);
// 	}
// 	for (int i = 0; i < sums.size(); ++i)
// 	{
// 		for (int j = 0; j < sums[0].size(); ++j)
// 		{
// 			int mini = min(i + K, M - 1);
// 			int minj = min(j + K, N - 1);
// 			int complete_res = sums[mini][minj];
// 			if (i - K - 1 >= 0 && j - K - 1 >= 0)
// 			{
// 				int maxj = min(N - 1, j + K);
// 				int maxi = min(M - 1, i + K);
// 				complete_res += sums[i - K - 1][j - K - 1];
// 				complete_res -= sums[i - K - 1][maxj];
// 				complete_res -= sums[maxi][j - K - 1];
// 			}
// 			else if (i - K - 1 >= 0)
// 			{
// 				complete_res -= sums[i - K - 1][minj];
// 			}
// 			else if (j - K - 1 >= 0)
// 			{
// 				complete_res -= sums[mini][j - K - 1];
// 			}
// 			res[i][j] = complete_res;
// 		}
// 	}
// 	return res;
// }
//
//
// using namespace std;
//
// int maxScoreSightseeingPair(std::vector <int> &values)
// {
// 	int largest = 0;
// 	int largest_idx = 0;
// 	int second_largest = 0;
// 	int second_largest_idx = 0;
// 	int best_score = 0;
// 	for (int i = 0; i < values.size(); ++i)
// 	{
//
// 		if (values[i] >= largest)
// 		{
// 			second_largest_idx = largest_idx;
// 			second_largest = largest;
// 			largest_idx = i;
// 			largest = values[i];
//
// 		}
// 		else if (values[i] >= second_largest)
// 		{
// 			second_largest = values[i];
// 			second_largest_idx = i;
// 		}
// 		// int max = (largest_idx > second_largest_idx) ? largest_idx : second_largest_idx;
// 		// int min = (largest_idx > second_largest_idx) ? second_largest_idx : largest_idx;
// 		if (best_score < largest + second_largest)
// 		{
// 			best_score = largest + second_largest;
// 		}
// 		--largest;
// 		--second_largest;
// 	}
// 	return best_score;
// }
//
//
// void numIslandsHelper(vector <vector <char>> &grid, int i, int j)
// {
// 	if (j < grid[0].size() && i < grid.size() && i >= 0 && j >= 0)
// 	{
// 		if (grid[i][j] == '0')
// 		{
// 			return;
// 		}
// 		grid[i][j] = '0';
// 		numIslandsHelper(grid, i, j + 1);
// 		numIslandsHelper(grid, i + 1, j);
// 		numIslandsHelper(grid, i - 1, j);
// 		numIslandsHelper(grid, i, j - 1);
// 	}
// }
//
//
// int numIslands(vector <vector <char>> &grid)
// {
// 	int result = 0;
// 	for (int i = 0; i < grid.size(); ++i)
// 	{
// 		for (int j = 0; j < grid[0].size(); ++j)
// 		{
// 			if (grid[i][j] != '0')
// 			{
// 				numIslandsHelper(grid, i, j);
// 				++result;
// 			}
// 		}
// 	}
// 	return result;
// }
//
// int
// findTargetHelper(vector <int> &nums, int idx, const int &S, int &sum, map <pair <int, int>, int> &
// dp);
//
// int findTargetSumWays(vector <int> &nums, int S)
// {
// 	int sum = 0;
// 	map <pair <int, int>, int> dp;
// 	return findTargetHelper(nums, 0, S, sum, dp);
// }
//
// int numSquaresHelper(const int &n, vector <int> &v, int curSum, int curSize, int idx, int &best, map<pair<int,int>, int>& mp)
// {
// 	if (curSum == n)
// 	{
// 		best = (best > curSize) ? curSize : best;
// 		return curSize;
// 	}
// 	else if (curSum > n || idx >= v.size())
// 	{
// 		return n;
// 	}
// 	else
// 	{
// 		int best_res = n;
// 		for (int i = 0; v[idx] * i <= n; ++i)
// 		{
// 			curSum += v[idx] * i;
// 			if (mp.find({idx+1, curSum})==mp.end()){
// 				int res = numSquaresHelper(n, v, curSum, curSize + i, idx + 1, best, mp);
// 				best_res = (res < best_res) ? res : best_res;
// 			}
// 			else{
// 				int res =  (mp.find({idx+1, curSum}))->second;
// 				best_res = (res < best_res) ? res : best_res;
// 			}
// 			curSum -= v[idx] * i;
// 		}
// 		mp.insert({{idx, curSum}, best_res});
// 		return best_res;
// 	}
// }
//
// int numSquares(int n)
// {
// 	int smallest_root = sqrt(n);
// 	vector <int> v;
// 	map<pair<int,int>, int> mp;
// 	for (int i = 1; i <= smallest_root; ++i)
// 	{
// 		v.push_back(i * i);
// 	}
// 	int curSum = 0;
// 	int curSize = 0;
// 	int best = n;
// 	return numSquaresHelper(n, v, curSum, curSize, 0, best, mp);
//
// }
//
// void testIntegralImage()
// {
// 	vector <vector <int>> v = {{1, 2, 3, 4, 5, 6, 7, 8,  9,  10},
// 							   {7, 9, 8, 7, 6, 5, 4, 34, 32, 5},
// 							   {7, 9, 8, 7, 6, 5, 4, 34, 32,
// 															 5},
// 							   {1, 2, 3, 4, 5, 6, 7, 8,  9,  10}};
// 	print_vector(v);
// 	// auto res = inefficientVersion(v, 1);
// 	auto sums = sumUp(v);
// 	print_vector(sums);
// 	v = getResult(sums, 2);
// 	print_vector(v);
// }
//
// void testNumIslands()
// {
// 	vector <char> c1 = {'1', '1', '1'};
// 	vector <char> c2 = {'0', '1', '0'};
// 	vector <char> c3 = {'1', '1', '1'};
// 	vector <vector <char>> c;
// 	c.push_back(c1);
// 	c.push_back(c2);
// 	c.push_back(c3);
// 	cout << numIslands(c);
// }
//
// void testSightSeeing()
// {
// 	vector <int> v2 = {8, 1, 5, 2, 6};
// 	cout << maxScoreSightseeingPair(v2);
// }
//
//
//
//




bool repeatedSubstringPattern(string s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (s.size() % (i + 1) == 0)
		{
			int k = 0;
			for (int j = i + 1; j < s.size();)
			{
				if (s[k] == s[j])
				{
					++k;
					++j;
				}
				else
				{
					break;
				}
				if (j == s.size())
				{
					return true;
				}
			}
		}
	}
	return false;
}


int minFallingPathHelper(vector <vector <int>> &arr, int forbidden, int row)
{
	int minimum = INT_MAX - 1;
	int min_idx = 0;
	int second_min = INT_MAX;
	int smin_idx = 0;
	for (int i = 0; i < arr[row].size(); ++i)
	{
		if (i == forbidden)
		{continue;}
		if (arr[row][i] < minimum)
		{
			second_min = minimum;
			minimum = arr[row][i];
			smin_idx = min_idx;
			min_idx = i;
		}
		else if (arr[row][i] < second_min)
		{
			second_min = arr[row][i];
			smin_idx = i;
		}
	}
	if (row == arr.size() - 1)
	{
		return (min_idx == forbidden) ? second_min : minimum;
	}
	int to_put = (min_idx == forbidden) ? smin_idx : min_idx;
	int s1 = minimum + minFallingPathHelper(arr, to_put, row + 1);
	return s1;
}

int minFallingPathSum(vector <vector <int>> &arr)
{
	int minimum = INT_MAX - 1;
	int min_idx = 0;
	int second_min = INT_MAX;
	int smin_idx = 0;
	for (int i = 0; i < arr[0].size(); ++i)
	{
		if (arr[0][i] < minimum)
		{
			second_min = minimum;
			minimum = arr[0][i];
			smin_idx = min_idx;
			min_idx = i;
		}
		else if (arr[0][i] < second_min)
		{
			second_min = arr[0][i];
			smin_idx = i;
		}
	}
	int m1 = minFallingPathHelper(arr, min_idx, 1) + minimum;
	int m2 = minFallingPathHelper(arr, smin_idx, 1) + second_min;
	return (m1 < m2) ? m1 : m2;
}

void test_min_falling_path()
{
	vector <vector <int>> v;
	v.push_back(vector <int>({1, 5, 7}));
	v.push_back(vector <int>({1, 8, 8}));
	v.push_back(vector <int>({1, 5, 8}));
	cout << v.size() << endl;
	cout << v[0].size() << endl;
	cout << minFallingPathSum(v);
}

void repeatedSubstringPattern()
{
	string tmp =
			"ababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab";
	cout << tmp.size() << endl;
	cout << repeatedSubstringPattern(tmp);
	cout << '[';
	for (int i = 0; i < 10 * 10 * 10 * 10 - 1; ++i)
	{
		cout << i << ',' << i << ',' << i << ',';
	}
	cout << ']';
}

int jump(vector <int> &arr)
{
	int jumps = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		int current_jump = arr[i];
		int mx = 0;
		int mx_idx = i;
		for (int j = i + 1; j <= i + current_jump; ++j)
		{
			if (j == arr.size() - 1)
			{
				return ++jumps;
			}
			if (mx <= arr[j])
			{
				mx = arr[j];
				mx_idx = j;
			}
			--mx;
		}
		i = mx_idx - 1;
		++jumps;
	}
	return jumps;
}


bool canJump(vector<int>& arr){
	if (arr.size() == 1)
		return 0;
	int jumps = 0;
	for (int i = 0; i < arr.size(); ++i){
		int current_jump = arr[i];
		int mx = 0;
		int mx_idx = i;
		int dist = 1;
		for (int j = i + 1; j <= i + current_jump; ++j){
			if (j >= arr.size() - 1)
			{
				return true;
			}
			if (mx <= arr[j]){
				mx = arr[j];
				mx_idx = j;
				++dist;
			}
			--mx;
		}
		if (i == mx_idx-1) return false;
		++jumps;
	}
	return false;
}

void testJumpGames()
{
	vector <int> v = {2, 5, 0, 0};
	cout << jump(v);
	cout << canJump(v);
}

// void doTests()
// {
// 	testIntegralImage();
// 	testSightSeeing();
// 	testNumIslands();
// 	vector <int> v = {1,1,1,1,1};
// 	cout << findTargetSumWays(v, 3);
// 	cout << numSquares(10);
// 	repeatedSubstringPattern();
// 	test_min_falling_path();
// 	testJumpGames();
// }

int main()
{
	// doTests();
}
//
