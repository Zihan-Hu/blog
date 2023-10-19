#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

const char ch[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char tr(string s) {
  if (s == "0000") return '0';
  if (s == "0001") return '1';
  if (s == "0010") return '2';
  if (s == "0011") return '3';
  if (s == "0100") return '4';
  if (s == "0101") return '5';
  if (s == "0110") return '6';
  if (s == "0111") return '7';
  if (s == "1000") return '8';
  if (s == "1001") return '9';
  if (s == "1010") return 'A';
  if (s == "1011") return 'B';
  if (s == "1100") return 'C';
  if (s == "1101") return 'D';
  if (s == "1110") return 'E';
  if (s == "1111") return 'F';
  return '0';
}
/** 2 进制转 16 进制。 */
string transform(const string& s) {
  string ans;
  int i;
  for (i = s.length() - 4; i >= 0; i -= 4) {
    stringstream ss;
    ss << s[i] << s[i + 1] << s[i + 2] << s[i + 3];
    ans += tr(ss.str());
  }
  if (i != -4) {
    stringstream ss;
    for (int j = 0; j < 4; ++j) {
      if (i + j < 0) ss << '0';
      else ss << s[i + j];
    }
    ans += tr(ss.str());
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  int t;
  string s;
  s.reserve(10005);
  cin >> t;
  while (t--) {
    cin >> s;
    cout << transform(s) << '\n';
  }
  return 0;
}
