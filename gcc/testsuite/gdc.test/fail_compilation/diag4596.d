/*
TEST_OUTPUT:
---
fail_compilation/diag4596.d(18): Error: `super` is not an lvalue and cannot be modified
fail_compilation/diag4596.d(19): Error: conditional expression `1 ? super : super` is not a modifiable lvalue
---
*/



class NoGo4596
{
    void fun()
    {
        this = new NoGo4596;
        (1?this:this) = new NoGo4596;

        super = new Object;
        (1?super:super) = new Object;
    }
}
