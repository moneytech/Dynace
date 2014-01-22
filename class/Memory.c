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




#define	CLASS	Memory_c
#define	ivType	Memory_iv_t

#include "generics.h"

object	Memory_c;


#line 48 "Memory.c"
typedef struct  _Memory_iv_t  {
	unsigned iSize;
	void * iPtr;
}	Memory_iv_t;


#line 37 "Memory.d"
#include <string.h> 

cmeth objrtn Memory_cm_gNewWithInt(object self, int size)
{ 
	object obj = oSuper(Memory_c, gNew, self)(self); 
	accessIVsOf(obj); 
	iv->iSize = (unsigned) size; 
	iv->iPtr = calloc(iv->iSize ? iv->iSize : 1, sizeof(char)); 
	if (!iv->iPtr) 
		gError(Dynace, "Dynace: out of memory."); 
	return obj; 
} 

imeth objrtn Memory_im_gDispose(object self)
{ Memory_iv_t *iv = GetIVs(Memory, self);
	if (iv->iPtr) 
		free(iv->iPtr); 
	return oSuper(Memory_c, gDispose, self)(self); 
} 

imeth void * Memory_im_gPointerValue(object self)
{ Memory_iv_t *iv = GetIVs(Memory, self);
	return iv->iPtr; 
} 

imeth int Memory_im_gSize(object self)
{ Memory_iv_t *iv = GetIVs(Memory, self);
	return iv->iSize; 
} 

imeth objrtn Memory_im_gResize(object self, int size)
{ Memory_iv_t *iv = GetIVs(Memory, self);
	iv->iSize = (unsigned) size; 
	iv->iPtr = realloc(iv->iPtr, iv->iSize ? iv->iSize : 1); 
	if (!iv->iPtr) 
		gError(Dynace, "Dynace: out of memory."); 
	return self; 
} 

imeth objrtn Memory_im_gDeepCopy(object self)
{ Memory_iv_t *iv = GetIVs(Memory, self);
	object cpy = gNewWithInt(CLASS, (int) iv->iSize); 
	ivType *iv2 = ivPtr(cpy); 
	memcpy(iv2->iPtr, iv->iPtr, iv->iSize); 
	return cpy; 
} 


#line 104 "Memory.c"

objrtn	Memory_initialize(void)
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

	if (Memory_c) {
		LEAVECRITICALSECTION(cs);
		return Memory_c;
	}
	INHIBIT_THREADER;
	Memory_c = gNewClass(Class, "Memory", sizeof(Memory_iv_t), 0, END);
	cMethodFor(Memory, gNewWithInt, Memory_cm_gNewWithInt);
	iMethodFor(Memory, gPointerValue, Memory_im_gPointerValue);
	iMethodFor(Memory, gSize, Memory_im_gSize);
	iMethodFor(Memory, gDispose, Memory_im_gDispose);
	iMethodFor(Memory, gGCDispose, Memory_im_gDispose);
	iMethodFor(Memory, gCopy, Memory_im_gDeepCopy);
	iMethodFor(Memory, gDeepDispose, Memory_im_gDispose);
	iMethodFor(Memory, gResize, Memory_im_gResize);
	iMethodFor(Memory, gDeepCopy, Memory_im_gDeepCopy);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return Memory_c;
}



