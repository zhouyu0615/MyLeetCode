#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {	
	vector<int> m_iarray;
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();

		m_iarray.insert(m_iarray.end(),nums1.begin(),nums1.end());
		m_iarray.insert(m_iarray.end(), nums2.begin(), nums2.end());

		sort(m_iarray.begin(),m_iarray.end());
		double medNum;
		if ((len1+len2)%2==0)
		{
			medNum = (double)(m_iarray[(len1 + len2) /2 - 1] + m_iarray[(len1 + len2) /2])/2;
		}
		else
		{
			medNum = m_iarray[(len1 + len2) / 2];
		}
		return medNum;
	}
};

class Solution1 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		vector<int>::iterator pIt, pIt1, pIt2;

		pIt1 = nums1.begin();
		pIt2 = nums2.begin();

		size_t len1 = nums1.size();
		size_t len2 = nums2.size();

		size_t medPos = (len1 + len2) / 2;

		double preNum = 0;
		double medNum = 0;

		if (len1==0)
		{
			pIt = pIt2;
			preNum = (medPos==0?nums2[0]:nums2[medPos-1]);
			medNum = nums2[medPos];
			if ((len1+len2)%2==0)
			{
				medNum = (double)(preNum + medNum) / 2;
				return medNum;
			}
			return medNum;
		}
		if (len2==0)
		{
			pIt = pIt1;
			preNum = (medPos == 0 ? nums1[0] : nums1[medPos - 1]);
			medNum = nums1[medPos];
			if ((len1 + len2) % 2 == 0)
			{
				medNum = (double)(preNum + medNum) / 2;
				return medNum;
			}
			return medNum;

		}

		int count = 0;
		int nextNum = 0;
		while (count <= medPos)
		{
			preNum = medNum;
			if (pIt1 == nums1.end())  //nums1已经到终点//
			{
				pIt = pIt2;
				break;
			}
			if (pIt2 == nums2.end())  //nums2已经到终点//
			{
				pIt = pIt1;
				break;
			}	
			if (*pIt1 <= *pIt2)
			{
				medNum = *pIt1;
				++pIt1;
			}
			else
			{
				medNum = *pIt2;
				++pIt2;
			}
			count++;
		}

		if (count <= medPos)
		{
			pIt = pIt + (medPos - count);
			medNum = *pIt;
			if (medPos-count>=1)
			{
				preNum = *(--pIt);
			}
		}

		if ((len1 + len2) % 2 == 0)
		{
			medNum = double(preNum + medNum) / 2;
			return medNum;
		}
		return medNum;

	}
};




class Solution2 {
	vector < int >::iterator pIt, pIt1, pIt2,pIt1End, pIt2End;
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double preNum=0, medNum=0;
		pIt1 = nums1.begin();
		pIt2 = nums2.begin();
		pIt1End = nums1.end();
		pIt2End = nums2.end();

		int len1 = nums1.size();
		int len2 = nums2.size();
		int medPos = (len1 + len2) / 2;

		if (medPos==0)
		{
			return getNextNum();
		}
		int i = 0;
		while (i<=medPos)
		{
			preNum = medNum;
			medNum = getNextNum();
			i++;
		}

		if ((len1+len2)%2==0)
		{
			medNum = (double)(preNum + medNum) / 2;
		}
		return medNum;
	}

	int getNextNum()
	{
		int flag = 0;
		if (pIt1 == pIt1End)
		{
			pIt = pIt2;
			++pIt2;
			flag = 1;
		}
		if ((flag!=1)&&(pIt2 == pIt2End))
		{
			pIt = pIt1;
			++pIt1;		
			flag = 2;
		}
		if (flag==0)
		{
			if (*pIt1 <= *pIt2)
			{
				pIt = pIt1;
				++pIt1;
			}
			else
			{
				pIt = pIt2;
				++pIt2;
			}
		}
		return *pIt;
	}
};


int main()
{
	Solution2 testCase;
	vector<int> nums1 = {};
	vector<int> nums2 = {1};

	cout<<testCase.findMedianSortedArrays(nums1, nums2)<<endl;


	getchar();
	return 0;
}