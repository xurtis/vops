/* Encapsulated vtable for integer binary operators. */

#include <stddef.h>

typedef int (*op_t)(int, int);

typedef struct {
	op_t operation;
	char const * symbol;
} op_info_t;

/* The array of all operations and its length. */
extern op_info_t vops[];
extern size_t vops_len;

#define each_vop(op) ( \
	op_info_t *op = vops; \
	op < &vops[vops_len]; \
	op += 1 \
)
