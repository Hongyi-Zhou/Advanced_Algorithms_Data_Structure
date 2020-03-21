//jaro_distance

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

double jaroDistance(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();

	if (l1==0) return l2 == 0 ? 1.0 : 0.0;

	int match_distance = max(l1,l2)/2-1;

	bool s1_matches[l1];
	bool s2_matches[l2];

	fill(s1_matches, s1_matches + l1, false);
	fill(s2_matches, s2_matches + l2, false);

	int match = 0;
	for (int i = 0; i < l1; i ++)
	{
		int end = min(i + match_distance + 1, l2);
		for (int k = max(0, i - match_distance); k < end; k ++)
		{
			if(!s2_matches[k] && s1[i] == s2[k])
			{
				s1_matches[i] = true;
				s2_matches[k] = true;
				match ++;
				break;
			}
		}
	}
	cout<<match<<endl;

	if (match == 0) return 0.0;
	double t = 0.0;
	int k = 0;
	for (int i = 0; i< l1; i++)
	{
		if (s1_matches[i])
		{
			while (!s2_matches[k]) k++;
			if (s1[i] != s2[k]) t+= 0.5;
			k++;
		}
	}

	double m = match;
	return (m/l1 + m/l2 + (m-t)/m)/3.0;
}

int main() {
    using namespace std;
    cout << jaroDistance("mes", "messi") << endl;
    cout << jaroDistance("semabc", "messiabc") << endl;
    cout << jaroDistance("crate", "atcr") << endl;
    return 0;
}