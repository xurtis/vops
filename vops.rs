macro_rules! vops {
    {$($name:ident($symbol:tt): $expr:expr),*$(),*} => {
        mod vop_impl {$(
            pub(super) fn $name(a: u64, b: u64) -> u64 {
                ($expr)(a, b)
            }
        )*}

        const VOPS: &[Vop] = &[$(
            Vop {
                name: stringify!($name),
                symbol: stringify!($symbol),
                implementation: vop_impl::$name,
            }
        ),*];
    }
}

vops!{
    Add(+): |a, b| a + b,
    Sub(-): |a, b| a - b,
    Mul(*): |a, b| a * b,
    Div(/): |a, b| a / b,
    Rem(%): |a, b| a % b,
}

struct Vop {
    /// The name of the operator.
    pub name: &'static str,
    /// The symbol for the operator.
    pub symbol: &'static str,
    /// The implementation of the operator.
    pub implementation: fn(a: u64, b: u64) -> u64,
}
