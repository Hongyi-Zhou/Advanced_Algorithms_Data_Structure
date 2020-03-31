// Manacher's algorithm
// longest palindromic substring
void manacher(const string &s)
{
	int len = s.size();
	if (len == 0) return;

	int m[2*len+1];
	m[0] = 0;
	m[1] = 1;

	int cur, r;
	r = 2;
	cur = 1;

	for (int p2 = 2; p2<len*2+1; p2++)
	{
		int p1 = cur-(p2-cur);
		while(p1<0)
		{
			cur++;
			r = m[cur] + cur;
			p1 = cur-(p2-cur);
		}

		if(m[p1] < r-p2)
			m[p2] = m[p1];
		else{
			cur = p2;
			int k = r - p2;
			if (k<0) k = 0;
			while(1)
			{
				if ((p2+k+1)&1)
				{
					if(p2+k+1 < 2*len+1 && p2-k-1 >=0 && s[(p2+k)/2] == s[(p2-k-2)/2])
                  		k++;
                	else break;
				}
				else
				{
					if (p2+k+1< 2*len+1 && p2-k-1 >=0)
						k++;
					else
						break;
				}
			}
			r = p2 + k;
			m[p2] = k;
		}
	} 
}