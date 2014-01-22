/*
  Copyright (c) 1996 Blake McBride
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:

  1. Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/



/*  This file automatically generated by dpp - do not edit  */

#define	DPP_STRATEGY	2
#define	DPP_FASTWIDE	0



#line 33 "BitArray.d"
#include "array1.h" 

#define	CLASS	BitArray_c
#define	ivType	BitArray_iv_t

#include "generics.h"

object	BitArray_c;



#line 39 "BitArray.d"
cvmeth objrtn BitArray_cvm_vNew(object self, va_list _rest_)
{ 
	unsigned rank = va_arg(_rest_, unsigned);

#line 41 "BitArray.d"
	static gNewArray_t cnew = NULL; 
	MAKE_REST(rank); 

	if (!cnew) 
		cnew = cmcPointer(Array, gNewArray); 
	return cnew(self, AT_BIT, rank, _rest_); 
} 

#line 65 "BitArray.c"

static	objrtn	BitArray_cfm_vNew(object self, ...)
{
	va_list	_rest_;
	va_start(_rest_, self);
	return BitArray_cvm_vNew(self, _rest_);
}



#line 76 "BitArray.c"

objrtn	BitArray_initialize(void)
{
	static  CRITICALSECTION  cs;
	static  int volatile once = 0;

	ENTERCRITICALSECTION(_CI_CS_);
	if (!once) {
		INITIALIZECRITICALSECTION(cs);
		once = 1;
	}
	LEAVECRITICALSECTION(_CI_CS_);

	ENTERCRITICALSECTION(cs);

	if (BitArray_c) {
		LEAVECRITICALSECTION(cs);
		return BitArray_c;
	}
	INHIBIT_THREADER;
	Array_initialize();
	if (BitArray_c)  {
		ENABLE_THREADER;
		LEAVECRITICALSECTION(cs);
		return BitArray_c;
	}
	BitArray_c = gNewClass(Class, "BitArray", 0, 0, Array, END);
	cvMethodFor(BitArray, vNew, BitArray_cvm_vNew, BitArray_cfm_vNew);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return BitArray_c;
}



