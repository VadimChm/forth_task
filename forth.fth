'a' 'b' '(' 'j' '(' 'd' 'd' ')' ')' '(' '(' ')' ')'

: PRINT 
    dup 
    emit ."  " ;
    
: LAST_TO_THE_HEAD
    depth 1 -
    roll ;
    
: PULL_LAST_SYMBOL
    0 ;
    
: LOOP_BODY
    LAST_TO_THE_HEAD
    dup 0 <> if
        PRINT
        dup ')' = if
            drop
            dup '(' = if
                drop 
            else 
                ')'
            endif
        else 
            dup '(' <> if
                drop
            endif
        endif
    endif ;
    
: DO_LOOP
    depth 1 > if
        depth 1 - 
        0 
        do
            LOOP_BODY
            dup ')' = if
                leave then
        loop 
    endif ;
    
: PRINT_RESULT 
    depth 1 = if
        ."  -> true" cr
    else
        ."  <- false" cr
    endif ;
    

PULL_LAST_SYMBOL
DO_LOOP
PRINT_RESULT
            
