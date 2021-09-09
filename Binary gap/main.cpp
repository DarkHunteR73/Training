#include <iostream>
#include <bitset>

int maxGap(int N)
{
	std::bitset<32> arr(N);
	int res = 0, arrSize = arr.size();

	for (int pLeft = 0, pRight = 0; pLeft < arrSize && pRight < arrSize;)
	{
		if (!arr[pLeft])
		{
			++pLeft;
			continue;
		}

		pRight = pLeft + 1;
		while (pRight < arrSize)
		{
			if (!arr[pRight]) ++pRight;
			else
			{
				res = std::max(res, (pRight - pLeft - 1));
				pLeft = pRight;
				break;
			}
		}
	}
	return res;
}

int main()
{
	std::cout << maxGap(1041) << std::endl;			// 00000000000000000000010000010001		5
	std::cout << maxGap(12345) << std::endl;		// 00000000000000000011000000111001		6
	std::cout << maxGap(INT32_MAX) << std::endl;	// 01111111111111111111111111111111		0
	std::cout << maxGap(INT32_MIN) << std::endl;	// 10000000000000000000000000000000		0
	std::cout << maxGap(512) << std::endl;			// 00000000000000000000001000000000		0
	std::cout << maxGap(2320) << std::endl;			// 00000000000000000000100100010000		3
	std::cout << maxGap(16529) << std::endl;		// 00000000000000000100000010010001		6
}

//	A binary gap within a positive integer N is any maximal sequence of consecutive zeros 
// that is surrounded by ones at both ends in the binary representation of N.
//	
//	For example, number 9 has binary representation 1001 and contains a binary gap of length 2. 
// The number 529 has binary representation 1000010001 and contains two binary gaps : 
// one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains
// one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.
// The number 32 has binary representation 100000 and has no binary gaps.
//	
//	Write a function :
//	
//	int solution(int N);
//	
//	that, given a positive integer N, returns the length of its longest binary gap.
// The function should return 0 if N doesn't contain a binary gap.
//	
//	For example, given N = 1041 the function should return 5, because N has binary 
// representation 10000010001 and so its longest binary gap is of length 5. 
// Given N = 32 the function should return 0, because N has binary representation '100000' 
// and thus no binary gaps.
//	
//	Write an efficient algorithm for the following assumptions :
//	
//	N is an integer within the range[1..2, 147, 483, 647].