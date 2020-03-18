// weighted edit distance

#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
	return min(min(x,y),x);
}
int del_cost = 2;
int ins_cost = 3;
int subs_cost = 4;

int weightedEditDistDP(string str1, string str2)
{

	int m = str1.length();
	int n = str2.length();

	int dp[m+1][n+1];

	dp[0][0] = 0;
	for (int i = 1; i<=m; i++)
		dp[i][0] = dp[i-1][0] + del_cost;
	for (int i = 1; i<=n; i++)
		dp[0][i] = dp[0][i-1] + ins_cost;


	for (int i = 1; i<=m; i++)
	{
		for (int j = 1; j<=n; j++)
		{
			dp[i][j] = min(dp[i][j-1] + ins_cost, dp[i-1][j] + del_cost, dp[i-1][j-1] + subs_cost);
		}
	}
	cout << dp[m][n]<<endl;
	return dp[m][n];
}


int main() 
{ 
    string str1 = "food"; 
    string str2 = "money"; 
    weightedEditDistDP(str1, str2); 
    return 0; 
} 
