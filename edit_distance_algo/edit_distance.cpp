// edit distance

#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
	return min(min(x,y),x);
}
/*
int editDistDP(string str1, string str2, int m, int n)
{
	int dp[m+1][n+1];

	for (int i = 0; i<=m; i++)
	{
		for (int j = 0; j<=n; j++)
		{
			if (i==0) dp[i][j] = j;
			else if (j==0) dp[i][j] = i;
			else if (str1[i-1] == str2[i-1])
				dp[i][j] = dp[i-1][j-1];
			else 
				dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
		}
	}
	return dp[m][n];
}
*/

void EditDistDP(string str1, string str2 )
{
	int len1 = str1.length();
	int len2 = str2.length();

	int DP[2][len1+1];

	memset(DP, 0, sizeof DP);

	for (int i = 0; i<= len1; i++)
		DP[0][i] = i;

	for (int i = 1; i <= len2; i++)
	{
		for (int j = 0; j <= len1; j++)
		{
			if (j==0) DP[i%2][j] = i;
			else if (str1[j-1] == str2[i-1])
				DP[i%2][j] = DP[(i-1)%2][j-1];
			else
				DP[i%2][j] = 1 + min(DP[(i-1)%2][j],
					min(DP[i%2][j-1], DP[(i-1)%2][j-1]));
		}
	}

	cout << DP[len2%2][len1]<<endl;
}

int main() 
{ 
    string str1 = "food"; 
    string str2 = "money"; 
    EditDistDP(str1, str2); 
    return 0; 
} 
