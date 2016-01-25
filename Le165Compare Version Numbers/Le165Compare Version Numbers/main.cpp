#include <iostream>
#include <string>

using namespace  std;


class Solution {
public:
	int compareVersion(string version1, string version2) {
		int s1 = 0, s2 = 0, n1 = version1.size(), n2 = version2.size();
		while (s1 < n1 || s2 < n2){
			int nums1 = 0, nums2 = 0, len1 = 0, len2 = 0;
			while (s1 < n1 && version1[s1] != '.') len1++, s1++;
			while (s2 < n2 && version2[s2] != '.') len2++, s2++;
			if (s1 <= n1) nums1 = stoi(version1.substr(s1 - len1, len1));
			if (s2 <= n2) nums2 = stoi(version2.substr(s2 - len2, len2));
			if (nums1 > nums2) return 1;
			if (nums1 < nums2) return -1;
			s1++, s2++;
		}
		return 0;
	}
};

int main()
{

	Solution testCase;

	string ver1 = "1.2", ver2 = "1.10";

	cout << testCase.compareVersion(ver1, ver2) << endl;

	getchar();
	return 0;
}