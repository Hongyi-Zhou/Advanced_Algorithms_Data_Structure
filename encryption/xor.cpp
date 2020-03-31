//xor encrytion
#include <bits/stdc++.h>

void encryptDecrypt(char inpString[])
{
	char xorKey = 'P';

	int len = strlen(inpString);

	for (int i = 0; i < len; i++)
	{
		inpString[i] = inpString[i] ^ xorKey;
		printf("%c", inpString[i]);
	}
}

int main() 
{ 
    char sampleString[] = "GeeksforGeeks"; 
  
    // Encrypt the string 
    printf("Encrypted String: "); 
    encryptDecrypt(sampleString); 
    printf("\n"); 
  
    // Decrypt the string 
    printf("Decrypted String: "); 
    encryptDecrypt(sampleString); 
  
    return 0; 
} 