/*----- FILE PUSHPOP.C -----------------------------------------------*/
/*                                                                    */
/* A push and pop function for a stack of integers                    */
/*--------------------------------------------------------------------*/
#include <stdlib.h>
#include "CALC.h" //INCLUDED THE CORRECT FILE
/*--------------------------------------------------------------------*/
/* input:  stk - stack of integers                                    */
/*         num - value to push on the stack                           */
/* action: get a link to hold the pushed value, push link on stack    */
extern void push(IntStack *stk, int num)
{
  IntLink *ptr;
  ptr = (struct int_link *)malloc(sizeof(IntLink)); /*  PUSHPOP1   */ //CHANGED ALLOCATION TO struct int_link
  ptr->i = num;                                     /*  PUSHPOP2  statement */
  ptr->next = stk->top;
  stk->top = ptr;
}
/*--------------------------------------------------------------------*/
/* return: int value popped from stack                                */
/* action: pops top element from stack and gets return value from it  */
/*--------------------------------------------------------------------*/
extern int pop(IntStack *stk)
{
  IntLink *ptr;
  int num;
  ptr = stk->top;
  num = ptr->i;
  stk->top = ptr->next;
  free(ptr);
  return num;
}