#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl "\n"
#define FLP(i,a,b) for (int i = a; i < b; i++)
typedef vector<int> vi;
typedef pair<int, int> pi;

int isUnique(int left, int right, string s) {
  int characters[256] = {0};
  for (int i = left; i <= right; i++) {
    if (characters[int(s[i])] != 0) {
      return characters[int(s[i])];
    } else {
      characters[int(s[i])] = i + 1;
    }
  }
  return -1;
}

int lengthOfLongestSubstring(string s) {
  if (s == "") {
    return 0;
  }
  int left = 0;
  int right = 0;
  int max = 0;
  while (right < s.length() && left <= right) {
    cout << "left: " << left << endl;
    cout << "right: " << right << endl;
    if (isUnique(left, right, s) == -1) {
      right += 1;
    } else {
      if (right - left > max) {
        max = right - left;
      }
      left = isUnique(left, right, s);
    }
  }
  if (right - left > max) {
    max = right - left;
  }
  return max;
}

int main() {
  string s;
  cin >> s;
  cout << lengthOfLongestSubstring(s) << endl;
}