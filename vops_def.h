/* Definition of operations for vtable */

#ifdef DEF_VOP
/* Only define operations if the definition macro has been set.  */
DEF_VOP(add, "+", a, b, a + b)
DEF_VOP(sub, "-", a, b, a - b)
DEF_VOP(mul, "+", a, b, a * b)
DEF_VOP(div, "/", a, b, a / b)
DEF_VOP(rem, "%", a, b, a % b)
#endif
