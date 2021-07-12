#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl "\n"
#define FLP(i,a,b) for (int i = a; i < b; i++)
typedef vector<int> vi;
typedef pair<int, int> pi;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	if (m == 0) {
		if (n == 0) {
			return 0;
		} else {
			if (n % 2 == 0) {
				return (double(nums2.at(n / 2 - 1)) + double(nums2.at(n / 2))) / 2;
			}
			return double(nums2.at(n / 2));
		}
	}
	if (n == 0) {
		if (m == 0) {
			return 0;
		} else {
			if (m % 2 == 0) {
				return (double(nums1.at(n / 2 - 1)) + double(nums1.at(n / 2))) / 2;
			}
			return double(nums1.at(n / 2));
		}
	}
	if (m > n) {
		findMedianSortedArrays(nums2, nums1);
	}
	int l = 0;
	int r = m;
	while (l <= r) {
		i = (l + r) / 2;
		j = (m + n + 1) / 2 - i;
		if (i > 0 && nums1.at(i - 1) > nums2.at(j)) {
			r = i - 1;
		}
		else if (i < m && nums1.at(i) < nums2.at(j - 1)) {
			l = i + 1;
		}
		else {
			int max_left = max()
		}

	}
}

int main() {
	//solution here
}