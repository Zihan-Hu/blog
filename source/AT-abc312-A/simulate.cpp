#include <iostream>
#include <string>
using namespace std;

const string LIST[] = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  for (auto& item : LIST) {
    if (s == item) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
