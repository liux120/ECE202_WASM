(module
  (type
  (func (param f64  i32) (result f64))    ;; local 0 (multiplier) and  local 1 (power)    
  )
  (func (type 0) (local f64 i32)    ;; 2 extra local variables : local 2 (result) and local 3 (loop counter)
  get_local 0    ;; push the value to be multiplied by itself upon the stack
  set_local 2    ;; save variable upon the stack into the 3rd local (1st extra local)
          ;; important : default value for an extra local is 0
  block        ;; code blocks return no value (value popped after the last end)
                  loop            ;; br 0 from the loop leads us here
                      get_local 3    ;; get the loop counter (initial value: 0)
                      i32.const 1    ;; increment by one
                      i32.add        ;; the loop counter
  
                      tee_local 3    ;; and save it while keeping it upon the stack
                      get_local 1    ;; get the power
                      i32.ge_u        ;; loop exit if loop counter = power
                      br_if    1    ;; in this case branching to the outer block
  ;; ...otherwise new iteration 
                      get_local 0    ;; .. push the multiplier upon the stack
                      get_local 2    ;; ...push the temporary result upon the stack
  f64.mul        ;; multiply anew
  set_local 2    ;;save the value upon the stack into the temporary result
  
  br 0        ;; keep looping : branching to the start of the loop
                  end            ;; nothing ever ends here for a loop block !
              end                ;; the loop br 1 leads us here
              get_local 2            ;; put the result upon the stack as the returned value
  )
  (export "loop" (func 0))
)