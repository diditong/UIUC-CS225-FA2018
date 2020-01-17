#include <iostream>

using namespace std;

int activation;

int recursiveFib(int n) {
  activation += 1; // This line used to count activation
  // Base case
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return recursiveFib(n - 1) + recursiveFib(n - 2);
}

int iterativeFib(int n) {
  int n1 = 1, n2 = 1, res = 1;
  for (int i = 2; i < n; i++) {
    res = n1 + n2;
    n2 = n1;
    n1 = res;
  }
  return res;
}

void compareFib(int n) {
  int iter = iterativeFib(n), recur = recursiveFib(n);
  cout << "Iterative Result for n = " << n << ": " << iter << endl;
  cout << "Recursive Result for n = " << n << ": " << recur << endl;
}

int countActivation(int n) {
  activation = 0;
  recursiveFib(n);
  return activation;
}

void searchForGoldenRatio(int limit) {
  if (limit <= 3) {
    cout << "MISSION IMPOSSIBLE or DIVISION BY ZERO" << endl;
    return;
  }

  int curr = 2, prev_count = 1, prev_prev_count = 1;
  while (true) {
    int curr_count = countActivation(curr);
    int curr_total = prev_count + curr_count, prev_total = prev_count + prev_prev_count;
    if (prev_total <= limit && curr_total > limit) {
      int fib1 = recursiveFib(curr - 1), fib2 = recursiveFib(curr - 2);
      cout << "The best approximation of Golden Ratio with activation limit of " << limit << " is: " << (1.0 * fib1 / fib2) << endl;
      cout << "With Fib(" << curr - 1<< ") = " << fib1 << " with " << prev_count << " activations"
            << " and Fib(" << curr - 2 << ") = " << fib2 << " with " << prev_prev_count << " activations" << endl;
      return;
    }
    else {
      prev_prev_count = prev_count;
      prev_count = curr_count;
      curr++;
    }
  }
}

int main() {
  compareFib(5);
  searchForGoldenRatio(14);
}
