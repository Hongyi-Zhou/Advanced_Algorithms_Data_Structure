//KMP Algorithm fro pattern searching
#include <bits/stdc++.h>

void computeLSPArray(char* pat, int M, int* lps);

void KMPSearch(char *pat, char*txt)
{
	int m = strlen(pat);
	int n = strlen(txt);

	int lps[m];

	computeLSPArray(pat, m, lps);

	int i = 0;
	int j = 0;

	while (i < n){
		if (pat[j] == txt[i]){
			j++;
			i++;
		}

		if ( j == m)
		{
			printf("Found pattern at index %d", i-j);
			j = lps[j-1];
		}
		else if (i < n && pat[j] != txt[i]){
			if (j != 0)
				j = lps[j-1];
			else
				i = i + 1;
		}
	}
}

void computeLSPArray(char* pat, int M, int* lps)
{
	int len = 0;
	lps[0] = 0;

	int i = 1;
	while(i<M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
				len = lps[len-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main() 
{ 
    char txt[] = "ABABDABACDABABCABAB"; 
    char pat[] = "ABABCABAB"; 
    KMPSearch(pat, txt); 
    return 0; 
} 