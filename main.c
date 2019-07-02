#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "vops.h"

int main(void) {
	assert(vops[VOP_add].impl(1, 2) == 3);

	for each_vop(op) {
		op_t f = op->impl;
		char const * const n = op->name;
		char const * const s = op->symbol;

		if (f != NULL) {
			printf("%s: 11 %s 5 = %d\n", n, s, f(11, 5));
		} else {
			printf("Missing operation: %s\n", n);
		}
	}
};
