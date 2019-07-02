#include <stdlib.h>
#include <stdio.h>

#include "vops.h"

int main(void) {
	for each_vop(op) {
		op_t f = op->operation;
		char const * const s = op->symbol;

		if (f != NULL) {
			printf("11 %s 5 = %d\n", s, f(11, 5));
		} else {
			printf("Missing operation 11 %s 5\n", s);
		}
	}
};
