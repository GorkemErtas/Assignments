#include <iostream>
using namespace std;
 
int main()
{
  int n, m, i, j, k;
  n = 6;
  m = 3;
  int alloc[n][m] = {{ 0, 1, 0, 0, 0 },
                     { 2, 0, 0, 1, 1 },
                     { 3, 0, 2, 1, 0 },
                     { 2, 1, 1, 1, 0 },
                     { 0, 0, 2, 2, 1 },
					 { 0, 0, 3, 0, 0 }};
 
  int max[n][m] = {{ 7, 5, 3, 3, 6 },
                   { 3, 2, 2, 2, 3 },
                   { 9, 0, 2, 2, 2 },
                   { 2, 2, 2, 2, 3 },
                   { 4, 3, 3, 3, 4 },
				   { 5, 3, 3, 3, 5 }};
 
  int f[n], ans[n], ind = 0;
  for (k = 0; k < n; k++) {
    f[k] = 0;
  }
  int need[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      need[i][j] = max[i][j] - alloc[i][j];
  }
}
