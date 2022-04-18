#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol533;

/*
Input:
[['W', 'B', 'W', 'B', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'B', 'W'],
 ['W', 'W', 'B', 'W', 'B', 'W']]

N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index
0    [['W', 'B', 'W', 'B', 'B', 'W'],
1     ['W', 'B', 'W', 'B', 'B', 'W'],
2     ['W', 'B', 'W', 'B', 'B', 'W'],
3     ['W', 'W', 'B', 'W', 'B', 'W']]
row index

Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels.
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2.
They are exactly the same as row R = 0.

*/

tuple<vector<vector<char>>, int, int> testFixture1()
{
  auto input = vector<vector<char>>{
      {'W', 'B', 'W', 'B', 'B', 'W'},
      {'W', 'B', 'W', 'B', 'B', 'W'},
      {'W', 'B', 'W', 'B', 'B', 'W'},
      {'W', 'W', 'B', 'W', 'B', 'W'}};

  return make_tuple(input, 3, 6);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Test 1 - expect to see " << to_string(get<2>(f)) << endl;

  cout << "Result: " << sol.find(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  return 0;
}