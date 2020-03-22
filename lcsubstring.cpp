//longest common substring
#include <iostream>
#include <string.h>
using namespace std;

int lcs(char *x, char *y, int m, int n)
{
	int LCS[m+1][n+1];
	int result = 0;

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i==0|| j == 0)
				LCS[i][j] = 0;
			else if (x[i-1] == y[j-1])
			{
				LCS[i][j] = LCS[i-1][j-1] + 1;
				result = max(result, LCS[i][j]);
			}
			else LCS[i][j] = 0;
		}
	}
	return result;
}

int main() 
{ 
    char X[] = "OldSite:GeeksforGeeks.org"; 
    char Y[] = "NewSite:GeeksQuiz.com"; 
  
    int m = strlen(X); 
    int n = strlen(Y); 
  
    cout << "Length of Longest Common Substring is " 
         << lcs(X, Y, m, n); 
    return 0; 
} 