class Solution {
public:
	long long comb(long long l) {
		return ((l + 1) * l) / 2;
	}
	int numSub(string s) {
		long long a = 0;
		long long l = 0;
		long long CONST = pow(10, 9) + 7;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				a += comb(l) % (CONST);
				l = 0;
			}
			else {
				l += 1;
			}
		}
		a += comb(l) % (CONST);
		return a;
	}
};