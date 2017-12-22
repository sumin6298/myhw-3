#include <sys/types.h>
#include <limits.h>

#include "run.h"
#include "util.h"
#include <stdio.h>


void *base = 0;


p_meta find_meta(p_meta *last, size_t size) {
  p_meta index = base;
  p_meta result = base;

  switch(fit_flag){
    case FIRST_FIT:
    {
      //FIRST FIT CODE
      while(index){
        if(index -> free ==1 && index ->size >= size){
            result = index;
            break;
        }
        index = index -> next;
      }
        result = index;
    }
    break;

    case BEST_FIT:
    {
      //BEST_FIT CODE
    }
    break;

    case WORST_FIT:
    {
      //WORST_FIT CODE
    }
    break;

  }
  return result;
}

void *m_malloc(size_t size) {
  p_meta index = base;
  p_meta result = base;
  p_meta current = sbrk(0);
  if(result == current){
     result = index + sbrk(size);
  }
  

}

void m_free(void *ptr) {

}

void*
m_realloc(void* ptr, size_t size)
{

}
