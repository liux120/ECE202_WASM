(module
(global            ;; global section with index 0 in the global section list
(mut i32)        ;; mut = mutable; replace (mut i32) by i32 if constant
(i32.const 16)    ;; initial value of the global variable, passed with a i32.const operator
)
(type
(func (param i32 i32) (result    i32))
)
(func (type 0)    
            get_local 0
            get_local 1
            i32.div_s        ;; result of the division is pushed upon the stack
            get_global 0    ;; global referenced by its index
            i32.add        ;; pop both the division result and the global, and add them
)            
        (export "divideAndAdd" (func 0))
)
