#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int get_one_q(queue<int> q) {
  return q.front();
}

int get_ten_q(queue<int> q) {
  for (int i = 0; i < 9; i++) {
    q.pop();
  }
  return q.front();
}

int get_one_s(stack<int> s) {
    for (int i = 0; i < 9; i++) {
      s.pop();
    }
    return s.top();
}

int get_ten_s(stack<int> s) {
  return s.top();
}

int main() {
  queue<int> q;
  stack<int> s;
  for(int i = 1; i <= 10; i++) {
    q.push(i);
    s.push(i);
  }

  // Retrive 1 on q
  cout << "Retrive 1 on q: " << get_one_q(q) << endl;

  // Retrive 1 on s
  cout << "Retrive 1 on s: " << get_one_s(s) << endl;

  // Retrive 10 on q
  cout << "Retrive 10 on q: " << get_ten_q(q) << endl;

  // Retrive 10 on s
  cout << "Retrive 10 on s: " << get_ten_s(s) << endl;
}
