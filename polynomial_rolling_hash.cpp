//polynomial rolling hash
#include <bits/stdc++.h>
using namespace std;

//djb2 5281 31
/*
long long compute_hash(string const&s)
{
	const int m = 1e9 + 9;

	long long hash_value = 5281;

	for (char c:s)
	{
		hash_value = ((hash_value<<5) + hash_value + (c - 'a' + 1) ) % m; // hash * 33 + c 
	}
	return hash_value;
}
*/

//sdbm 
/*
long long compute_hash(string const&s)
{
	const int m = 1e9 + 9;

	long long hash_value = 0;

	for (char c:s)
	{
		hash_value = ((hash_value<<6) + (hash_value<<16) - hash_value + (c - 'a' + 1) ) % m; // hash(i) = hash(i - 1) * 65599 + str[i]
	}
	return hash_value;
}
*/



long long compute_hash(string const&s)
{
	const int p = 31;//53
	const int m = 1e9 + 9;

	long long hash_value = 0;
	long long p_pow = 1;

	for (char c:s)
	{
		hash_value = (hash_value + (c - 'a' + 1) *p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}

//example tasks: search for duplicate strings
vector<vector<int>> group_identical_strings(vector<string> const&s)
{
	int n = s.size();
	vector<pair<long long, int>> hashes(n);

	for (int i = 0; i < n; i++)
		hashes[i] = {compute_hash(s[i]),i};

	sort(hashes.begin(), hashes.end());
	// cout << "hash"<<endl;
	// for (auto a: hashes)
	// 	cout << a.first << " ";

	vector<vector<int>> groups;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || hashes[i].first != hashes[i-1].first)
			groups.emplace_back();
		groups.back().push_back(hashes[i].second);
	}
	return groups;
}

int count_unique_substrings(string const &s)
{
	int n = s.size();

	const int p = 31;
	const int m = 1e9 + 9;
	vector< long long> p_pow(n);
	p_pow[0] = 1;
	for (int i = 1; i < n; i++)
		p_pow[i] = (p_pow[i-1] * p) % m;
	vector<long long> h(n+1, 0);
	for (int i = 0; i < n; i++)
		h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) %m;

	int cnt = 0;
	for (int l = 1; l <= n; l++)
	{
		set<long long> hs;
		for (int i = 0; i <= n-l; i++)
		{
			long long cur_h = (h[i+l] + m - h[i]) %m;
			cur_h = (cur_h * p_pow[n-i-1]) % m;
			hs.insert(cur_h);
		}
		cnt += hs.size();
	}
	return cnt;
}

int main()
{
	cout << "Task1: group identical"<< endl;
	vector<string> input = {"hello", "o", "Iam", "hello"};
	vector<vector<int>> output = group_identical_strings(input);
	for (int i = 0; i < output.size(); i++)
	{
		cout<< i <<endl;
		for (auto a: output[i])
		{
			cout << input[a] << " ";
		}
		cout << endl;
		cout << endl;
	}

	cout << "Task2: count substrings" << endl;
	string s = "abc";
	int a = count_unique_substrings(s);
	cout << a << endl;

	return 0;
}