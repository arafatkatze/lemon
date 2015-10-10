#include "lemon.h"

VALUE rb_mLemon;

void
Init_lemon(void)
{
  rb_mLemon = rb_define_module("Lemon");
}
