(module
    (type                ;; type  with index 0 in type list
(func (param i32) (result i32))    ;; argument is offset, result is 
)                    ;;  unsigned byte value at this offset (casted to i32)
(memory 1 1)        ;; 64 kB (1 page) memory, also limited to 1 page (cannot be grown).
(data        
(i32.const 0)    ;; starting offset for memory initialization
"\03\00\00\00"    ;; first 4 bytes will correspond to the byte length (i32) of the div string
"div"        ;; following bytes are filled by these 3 UTF-8 characters
)
(func (type 0)        ;; function with index 0 in function list and signature with index 0 in type list
    get_local 0    ;; push the argument (offset) upon the stack
    i32.load8_u    ;; load memory value at offset 0 as unsigned byte casted to an i32
)
(export "testData" (func 0))
)
