#include <stdio.h>
#include "function.h"
void array_exchanger(int* array_a, int* array_b, int length) {
     // your code
	for(int i = 0; i < length; i++){
		array_a[i] += array_b[i];
		array_b[i] = array_a[i] - array_b[i];
		array_a[i] -= array_b[i];
	}
}



