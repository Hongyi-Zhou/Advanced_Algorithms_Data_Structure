// Jaccard Index
#include <bits/stdc++.h>
using namespace std;

set<int> intersection(set<int> s1, set<int> s2)
{
	set<int> intersect;
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(intersect, intersect.begin()));
	return intersect;
}

double jaccard_index(set<int> s1, set<int> s2)
{
	double size_s1 = s1.size();
	double size_s2 = s2.size();

	set<int> intersect = intersection(s1, s2);

	double size_in = intersect.size();

	double jaccard_in = size_in/(size_s1+ size_s2 - size_in);

	return jaccard_in;
}

double jaccard_distance(double jaccardIndex)
{
	double jaccard_dist = 1 - jaccardIndex;
	return jaccard_dist;
}

int main() 
{ 
    // Elements of the 1st set 
    set<int> s1; 
    s1.insert(1); 
    s1.insert(2); 
    s1.insert(3); 
    s1.insert(4); 
    s1.insert(5); 
  
    // Elements of the 2nd set 
    set<int> s2; 
    s2.insert(4); 
    s2.insert(5); 
    s2.insert(6); 
    s2.insert(7); 
    s2.insert(8); 
    s2.insert(9); 
    s2.insert(10); 
  
    double jaccardIndex = jaccard_index(s1, s2); 
  
    // Print the Jaccard index and Jaccard distance 
    cout << "Jaccard index = "
         << jaccardIndex << endl; 
    cout << "Jaccard distance = "
         << jaccard_distance(jaccardIndex); 
  
    return 0; 
} 