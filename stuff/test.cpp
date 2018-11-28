#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

bool isLeftBracket(char s) {
  if (s == '{' || s == '[' || s == '(')
    return true;
  return false;
}

bool isRightBracket(char s) {
  if (s == '}' || s == ']' || s == ')')
    return true;
  return false;
}

bool isMatchedPair(char s1, char s2) {
  if (s1 == '(' && s2 == ')')
    return true;
  else if (s1 == '{' && s2 == '}')
    return true;
  else if (s1 == '[' && s2 == ']')
    return true;

  return false;
}

void clearStack(stack<char> stk) {
  for (unsigned int i = 0; i < stk.size(); i++)
    stk.pop();
}

int main() {
  int t;
  stack<char> stk;
  bool isBalanced = true;

  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    isBalanced = true;
    string expression;
    try {
      getline(cin, expression);
    } catch (exception e) {
      throw e;
    }

    if (isBalanced) {
      for (unsigned int i = 0; i < expression.length(); i++) {
        if (isLeftBracket(expression[i])) {
          stk.push(expression[i]);
        } else if (isRightBracket(expression[i]) && !stk.empty() &&
                   isMatchedPair(stk.top(), expression[i])) {
          stk.pop();
        } else if (isRightBracket(expression[i]) && stk.empty() ||
                   !isMatchedPair(stk.top(), expression[i])) {
          isBalanced = false;
        }
      }
    }
    if (isBalanced == true) {
      cout << "YES" << endl;
      clearStack(stk);
    } else if (isBalanced == false) {
      cout << "NO" << endl;
      clearStack(stk);
    }

    cin.clear();
  }

  return 0;
}
