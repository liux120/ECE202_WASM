(module
    (type                    ;; type  with index 0 in type list
(func (param f64) (result i32))    ;; f64 argument for default JS numeric value
)
(func (type 0)        ;; function with index 0 in function list and signature with index 0 in type list
    get_local 0
    i32.trunc_s/f64    ;; unary operator to cast f64 float (from get_local) to signed i32
    if (result i32)    
        i32.const 1
    else
        i32.const 0
    end
)
(export "testIf" (func 0))
)
