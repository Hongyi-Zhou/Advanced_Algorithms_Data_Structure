// Hamming distance

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int hammingDist(char *str1, char *str2)
{
	int i = 0; 
	int cnt = 0;
	while(str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			cnt++;
		i++;
	}
	return cnt;
}

int main() 
{ 
    char str1[] = "geekspractice"; 
    char str2[] = "nerdspractise"; 
  
    // function call 
    cout << hammingDist (str1, str2); 
  
    return 0; 
}  