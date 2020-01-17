#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

   Node * head1 = new Node();
   Node * head2 = new Node();
   Node * head3 = new Node();
   head1->data_=5;
   head1->next_=head2;
   head2->data_=6;
   head2->next_=head3;
   head3->data_=7;
   head3->next_=NULL;

   cout << stringList(head1) << endl;

  return 0;
}
