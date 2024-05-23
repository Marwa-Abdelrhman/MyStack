#include <stdio.h>
#include <stdlib.h>
#include "stack_st.h"

//#define STACK_DEBUG_MODE


int main()
{
    stack_t my_s;
    return_status_t ret=R_NOK;
    uint32_t val,val_pop;
    ret=stack_init(&my_s);



    if(ret==R_NOK)
    {

        printf("ERRORRRRRR !!!!!!!!!!!\n");
    }
    else
    {

    ret=stack_push(&my_s,55);
    ret=stack_push(&my_s,44);
    ret=stack_push(&my_s,33);
    ret=stack_push(&my_s,22);
    ret=stack_push(&my_s,11);
    ret=stack_display(&my_s);

    ret=stack_elements_count(&my_s,&val);
    ret=stack_pop(&my_s,&val_pop);
    ret=stack_last_value(&my_s,&val);
    }
    return 0;
}
