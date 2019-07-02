/* Encapsulated vtable for integer binary operators. */

#include <stddef.h>

typedef int (*op_t)(int, int);

typedef struct {
	op_t impl;
	char const *name;
	char const *symbol;
} op_info_t;

/* The array of all operations and its length. */
extern op_info_t vops[];
extern size_t vops_len;

/* Operation identifiers */

#define DEF_VOP(name, sym, a, b, expr) \
	VOP_##name,

typedef enum {
#include "vops_def.h"
} op_id;

#undef DEF_VOP

#define each_vop(op) ( \
	op_info_t *op = vops; \
	op < &vops[vops_len]; \
	op += 1 \
)
