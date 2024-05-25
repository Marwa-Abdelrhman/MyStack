/**
 * @file stack_st.h
 * @author Marwa Abdelrhman
 * @brief contains declarations of stack
 * @version 1.0
 * @date 2024-05-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _STACK_ST_H_
#define _STACK_ST_H_

#include"std_def.h"
#include <stdlib.h>

#define STACK_MAX_SIZE 5
#define STACK_DEBUG_MODE

typedef struct
{
    sint32_t stack_top;
    uint32_t data[STACK_MAX_SIZE];

}stack_t;


typedef enum
{
  STACK_EMPTY=0,
  STACK_FULL,
  STACK_NOT_FULL

}stack_return_status;

/**
  *@brief  initialize the stack
  *@param  my_stack pointer to the stack
  *@return stack initialization return status
  */

return_status_t stack_init(stack_t *my_stack);

/**
  *@brief  check if stack is empty
  *@param  my_stack pointer to the stack
  *@return stack check is empty return status
  */
static stack_return_status stack_is_empty(stack_t *my_stack);

/**
  *@brief  check if stack is full
  *@param  my_stack pointer to the stack
  *@return stack check is full return status
  */
static stack_return_status stack_is_full(stack_t *my_stack);
/**
  *@brief  pop the last element added at the stack
  *@param  my_stack pointer to the stack
  *@param  value to be popped at stack
  *@return status of pop process
  */
return_status_t stack_pop(stack_t *my_stack,uint32_t *value);
/**
  *@brief  push element at the top of the stack
  *@param  my_stack pointer to the stack
  *@param  value to be pushed at stack
  *@return status of push process
  */


return_status_t stack_push(stack_t *my_stack,uint32_t value);
/**
  *@brief  know how many elements added at the stack
  *@param  my_stack pointer to the stack
  *@param  stack_size size of stack
  *@return status of stack count process
  */

return_status_t stack_elements_count(stack_t *my_stack,uint32_t *stack_size);
/**
  *@brief  display all elements in the stack
  *@param  my_stack pointer to the stack
  *@return status of stack display process
  */

return_status_t stack_display(stack_t *my_stack);

/**
  *@brief  display  last element added in the stack
  *@param  my_stack pointer to the stack
  *@param  value at the top of the stack
  *@return status of stack last value process
  */
return_status_t stack_last_value(stack_t *my_stack,uint32_t *value);




#endif // _STACK_ST_H_
