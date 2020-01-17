#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
void popLast(queue<T> &q) {
  //YOUR CODE HERE
  size_t s = q.size();
  for (size_t i = 0; i < s - 1; i++){
    T temp = q.front();
    q.pop();
    q.push(temp);
  }
  q.pop();
}

template <typename T>
void reverseQ(queue<T> &q) {
  stack<T> s;
  //YOUR CODE HERE
  while (!q.empty()) {
    s.push(q.front());
    q.pop();
  }
  while(!s.empty()) {
    q.push(s.top());
    s.pop();
  }
}

queue<int> makeRangeQueue(int n) {
  queue<int> ret;
  for(int i = 0; i < n; i++) {
    ret.push(i);
  }
  return ret;
}

template <typename T>
void printRangeQueue(queue<T> q) {
  size_t count = 0;
  while (count++ < q.size()) {
    T elem = q.front();
    q.pop();
    q.push(elem);
    cout << elem << ' ';
  }
  cout << endl;
}

int main() {
  queue<int> q = makeRangeQueue(5);
  cout << "Original Queue: ";
  printRangeQueue(q);
  popLast(q);
  cout << "After popLast: ";
  printRangeQueue(q);
  reverseQ(q);
  cout << "After reverseQ: ";
  printRangeQueue(q);
  return 0;
}
