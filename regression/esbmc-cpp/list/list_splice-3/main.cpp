// splicing lists
#include <iostream>
#include <list>
#include <cassert>
using namespace std;

int main ()
{
  list<int> mylist1, mylist2;
  list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=4; i++)
     mylist1.push_back(i);      // mylist1: 1 2 3 4

  for (int i=1; i<=3; i++)
     mylist2.push_back(i*10);   // mylist2: 10 20 30

  it = mylist1.begin();
  ++it;                         // points to 2

  mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)
  assert(mylist1.size() == 7);
  assert(mylist2.empty());
  assert(*it == 2);
  it--;
  assert(*it == 30);
  it++;
                                          
  mylist2.splice (mylist2.begin(),mylist1, it);
                                // mylist1: 1 10 20 30 3 4
                                // mylist2: 2
                                // "it" is now invalid.
  assert(mylist1.size() == 6);                                
  assert(mylist2.size() == 1);
  
  it = mylist1.begin();
  advance(it,3);                // "it" points now to 30

  mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
                                // mylist1: 30 3 4 1 10 20
  assert(mylist1.size() == 6);
  it = mylist1.begin();
  assert(*it == 30);   it++;
  assert(*it == 3);  it++;
  assert(*it == 4); it++;
  assert(*it == 1); it++;
  assert(*it == 10); it++;
  assert(*it == 20);

  return 0;
}
