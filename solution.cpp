#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
using namespace sol533;
using namespace std;

/*takeaways
  - same as question 531 we record the count of Black
    pixels for each row and count
  - to enforce the Rule 2 it's more convenient we
    scan the picture by col first then by row
*/

int Solution::find(vector<vector<char>> &picture, int N)
{
  const int m = picture.size();
  const int n = picture[0].size();
  /* how many black pixels are there in a row */
  auto row_count = vector<int>(m);
  /* how many black pixels are there in a col */
  auto col_count = vector<int>(n);

  /* count the black pixels */
  for (auto i = 0; i < m; i++)
    for (auto j = 0; j < n; j++)
      if (picture[i][j] == 'B')
        row_count[i]++, col_count[j]++;

  auto count = 0;

  for (auto j = 0; j < n; j++)
    /* only if this col has exactly N Black pixels
       we will then look into it
    */
    if (col_count[j] == N)
    {
      auto pass = true;
      /* we are checking if the Rule 2 is followed
       */
      for (auto i = 0; i < m; i++)
        if (picture[i][j] == 'B' && row_count[i] != N)
        {
          pass = false;
          break;
        }
      /* every Black pixel in this col, it's
         corresponding row also has N black
         pixels
      */
      if (pass)
        /* every black pixel qualifies
           - there are N of them in total
        */
        count += N;
    }

  return count;
}