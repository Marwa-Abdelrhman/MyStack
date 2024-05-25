
 /**
 * @file stack_st.c
 * @author Marwa Abdelrhman
 * @brief contains function definition of stack
 * @version 1.0
 * @date 2024-05-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "stack_st.h"

/**
  *@brief initialize the stack
  *@param my_stack pointer to the stack
  *@return stack initialization return status
  */

return_status_t stack_init(stack_t *my_stack)
{
    return_status_t ret=R_NOK;
    //check if pointer is null
    if(my_stack==NULL)
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG_MODE
        printf("ERROR: stack_init has a null pointer");
        #endif // STACK_DEBUG_MODE
    }
    else
    {
        ret=R_OK;

        my_stack->stack_top=-1;
    }
    return ret;
}

/**
  *@brief check if stack is empty
  *@param my_stack pointer to the stack
  *@return stack check is empty return status
  */
static stack_return_status stack_is_empty(stack_t *my_stack)
{
    stack_return_status st_ret;



        if(my_stack->stack_top == -1)
        {
            st_ret=STACK_EMPTY;
        }
        else
        {
            st_ret=STACK_NOT_FULL;
        }


    return st_ret;

}

/**
  *@brief check if stack is full
  *@param my_stack pointer to the stack
  *@return stack check is full return status
  */
static stack_return_status stack_is_full(stack_t *my_stack)
{
   stack_return_status st_ret;



        if(my_stack->stack_top == STACK_MAX_SIZE-1)
        {
            st_ret=STACK_FULL;
        }
        else
        {
            st_ret=STACK_NOT_FULL;
        }


    return st_ret;
}
/**
  *@brief  pop the last element added at the stack
  *@param  my_stack pointer to the stack
  *@param  value to be popped at stack
  *@return status of pop process
  */
return_status_t stack_pop(stack_t *my_stack,uint32_t *value)
{
    return_status_t ret=R_NOK;
    //check if pointer is null
    if( (my_stack==NULL) || (value==NULL) || (stack_is_empty(my_stack)==STACK_EMPTY))
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG_MODE
        printf("ERROR: stack_pop has a null pointer or stack is empty.\n");
        #endif // STACK_DEBUG_MODE
    }
    else
    {

        *value=my_stack->data[my_stack->stack_top];
        (my_stack->stack_top)--;
        #ifdef STACK_DEBUG_MODE
        printf("value (%i) is popped from the stack.\n",*value);
        #endif // STACK_DEBUG_MODE


        ret=R_OK;
    }
   return ret;
}
/**
  *@brief  push element at the top of the stack
  *@param  my_stack pointer to the stack
  *@param  value to be pushed at stack
  *@return status of push process
  */

return_status_t stack_push(stack_t *my_stack,uint32_t value)
{
    return_status_t ret=R_NOK;
    //check if pointer is null
    if( (my_stack==NULL) || (stack_is_full(my_stack)==STACK_FULL))
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG_MODE
        printf("ERROR: stack_push has a null pointer or stack is full.\n");
        #endif // STACK_DEBUG_MODE
    }
    else
    {

        (my_stack->stack_top)++;
        my_stack->data[my_stack->stack_top]=value;

        #ifdef STACK_DEBUG_MODE
        printf("value (%i) is pushed at the stack.\n",value);
        #endif // STACK_DEBUG_MODE


        ret=R_OK;
    }
   return ret;
}
/**
  *@brief  know how many elements added at the stack
  *@param  my_stack pointer to the stack
  *@param  stack_size size of stack
  *@return status of stack count process
  */

return_status_t stack_elements_count(stack_t *my_stack,uint32_t *stack_size)
{
    return_status_t ret=R_NOK;

    //check if pointer is null
    if((my_stack==NULL) || (stack_size==NULL) )
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG_MODE
        printf("ERROR: stack_elements_count has a null pointer or stack is empty.\n");
        #endif // STACK_DEBUG_MODE
    }
    else
    {
        *stack_size = (my_stack->stack_top) +1;
        #ifdef STACK_DEBUG_MODE
        printf("stack size is [%i].\n",*stack_size);
        #endif // STACK_DEBUG_MODE
        ret=R_OK;
    }
   return ret;
}
/**
  *@brief  display all elements in the stack
  *@param  my_stack pointer to the stack
  *@return status of stack display process
  */

return_status_t stack_display(stack_t *my_stack)
{

    return_status_t ret=R_NOK;
    uint32_t st_C;
    //check if pointer is null
    if((my_stack==NULL)|| (stack_is_empty(&my_stack)==STACK_EMPTY))
    {
        ret=R_NOK;

        #ifdef STACK_DEBUG_MODE
        printf("ERROR: stack_display has a null pointer");
        #endif // STACK_DEBUG_MODE
    }
    else
    {
        printf("the stack elements are:\n");
        for( st_C=0; st_C <= my_stack->stack_top; st_C++)
        {
            printf("[%i]\t",my_stack->data[st_C]);
        }
        printf("\n");
        ret=R_OK;
    }
   return ret;
}
/**
  *@brief  display  last element added in the stack
  *@param  my_stack pointer to the stack
  *@param  value at the top of the stack
  *@return status of stack last value process
  */
return_status_t stack_last_value(stack_t *my_stack,uint32_t *value)
{
    return_status_t ret=R_NOK;
    //check if pointer is null
    if( (my_stack==NULL) || (value==NULL) || (stack_is_empty(my_stack)==STACK_EMPTY))
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG_MODE
        printf("ERROR: stack_last_value has a null pointer or stack is empty.\n");
        #endif // STACK_DEBUG_MODE
    }
    else
    {

        *value=my_stack->data[my_stack->stack_top];

        #ifdef STACK_DEBUG_MODE
        printf("value (%i) is top of the stack.\n",*value);
        #endif // STACK_DEBUG_MODE


        ret=R_OK;
    }
   return ret;


}
