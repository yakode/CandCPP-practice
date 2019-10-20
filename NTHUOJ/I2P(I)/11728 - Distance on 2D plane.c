#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    int x;
    int y;
} Point;

Point * ones_vec_1(int length)
{
   /// Please implement
   /// 1. Malloc memory for point array
	Point* sth;
	sth = (Point*)malloc(sizeof(Point)*length);
   /// 2. Read values into point array
	for(int i = 0; i < length; i++)
		scanf("%d%d", &sth[i].x, &sth[i].y);
   /// 3. Return the address of the first element in the array
	return sth;
}

float compute_distance(Point* a, int first_id, int second_id)
{
    float ans;
    Point first_p, second_p;
	int dx = a[first_id].x - a[second_id].x;
	dx = pow(dx, 2);
	int dy = a[first_id].y - a[second_id].y;
	dy = pow(dy, 2);
    /// Please implement
    /// 1. Get two point from function argument
    /// 2. Compute 2D distance and return ans
	ans = sqrt((float)dx+(float)dy);
    return ans;
}

int main(void)
{
   Point *point_array;
   int i, length, N;
   float ans;

   scanf("%d", &length);
   // give point_array memory and get first element address
   point_array = ones_vec_1(length);

   scanf("%d", &N);
   for (i = 0; i < N; i++){
      int first, second;
      scanf("%d %d", &first, &second);
      // compute distance of two points
      ans = compute_distance(point_array, first, second);
      printf("%.3f\n", ans);
   }

   return 0;
}
