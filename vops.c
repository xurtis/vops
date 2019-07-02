#include "vops.h"

typedef int (*op_t)(int, int);

/* Operation implementations */

#define DEF_VOP(name, sym, a, b, expr) \
	static int op_impl_##name(int a, int b) { \
		return expr; \
	}

#include "vops_def.h"

#undef DEF_VOP

/* The lookup table of operations */

#define DEF_VOP(op, sym, a, b, expr) \
	[VOP_##op] = { \
		.impl = op_impl_##op, \
		.name = #op, \
		.symbol = sym, \
	},

op_info_t vops[] = {
#include "vops_def.h"
};

#undef DEF_VOP

#define array_length(a) (sizeof(a) / sizeof(*a))
size_t vops_len = array_length(vops);
