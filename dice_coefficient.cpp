//Sorensen-Dice coefficient

#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

/*
double DiceMatch(string str1, string str2)
{
	if (str1.empty() || str2.empty()) return 0;
	if (str1 == str2) return 1;

	size_t strlen1 = str1.size();
	size_t strlen2 = str2.size();

	if (strlen1<2 || strlen1 < 2)
		return 0;

	size_t length1 = strlen1 - 1;
	size_t length2 = strlen2 - 1;

	double matches = 0;
	int i = 0;
	int j = 0;

	while ( i < length1 && j < length2)
	{
		string a = str1.substr(i,2);
		string b = str2.substr(j,2);

		int cmp = a.compare(b);
		if (cmp == 0)
			matches += 2;
		++i;
		++j;
	}
	return matches/(length1+length2);
}
*/

double DiceMatch(string str1, string str2)
{
	set<string> str1_bigrams;
	set<string> str2_bigrams;

	if (str1.length() == 0 || str2.length() == 0)
		return 0;

	for (int i = 0; i < (str1.length()-1); i++)
		str1_bigrams.insert(str1.substr(i,2));

	for (int i = 0; i < (str2.length()-1); i++)
		str2_bigrams.insert(str2.substr(i,2));

	int intersection = 0;

	for (set<string>::iterator IT = str2_bigrams.begin(); IT!= str2_bigrams.end(); IT++)
	{
		intersection += str1_bigrams.count((*IT));
	}

	int total = str1_bigrams.size() + str2_bigrams.size();
	double dice =  (double)(intersection*2)/(double)total;

	return dice;

}

int main() 
{ 
	double result = DiceMatch("algorithms are fun", "logarithms are not");
	cout << "result:" << result << endl;
	return 0;
}