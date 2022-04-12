/****************************************************
 *					Problem 1646B					*
 * https://codeforces.com/problemset/problem/1646/B *
 ****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	unsigned int nCases;
	std::cin >> nCases;
	while (nCases--)
	{
		unsigned int size;
		unsigned long long int redCache, blueCache;
		bool isSolved = false;
		std::vector<unsigned long int> vec;
		std::cin >> size;
		vec.resize(size);
		for (auto& e : vec) std::cin >> e;
		std::sort(vec.begin(), vec.end(), [](unsigned long int lhs, unsigned long int rhs) 
										{return lhs > rhs; });
		redCache = 0;
		blueCache = vec[size - 1];
		for (unsigned int r = 0; r < (size % 2 ? size / 2 : size / 2 - 1); ++r)
		{
			redCache += vec[r];
			blueCache += vec[size - (r + 2)];
			if (redCache > blueCache)
			{
				isSolved = true;
				break;
			}
		}
		std::cout << (isSolved ? "YES\n" : "NO\n");
	}
	return 0;
}