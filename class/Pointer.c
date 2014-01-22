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



#line 32 "Pointer.d"
#include <math.h> 

#define	CLASS	Pointer_c
#define	ivType	Pointer_iv_t

#include "generics.h"

object	Pointer_c;


#line 50 "Pointer.c"
typedef struct  _Pointer_iv_t  {
	void * iVal;
}	Pointer_iv_t;



#line 38 "Pointer.d"
cmeth objrtn Pointer_cm_gNewWithPtr(object self, void *val)
{ 
	object obj = oSuper(Pointer_c, gNew, self)(self); 
	ivType *iv = ivPtr(obj); 
	iv->iVal = val; 
	return(obj); 
} 

imeth objrtn Pointer_im_gDeepDispose(object self)
{ Pointer_iv_t *iv = GetIVs(Pointer, self);
	if (iv->iVal && IsObj(iv->iVal)) 
		gDeepDispose(iv->iVal); 
	return oSuper(Pointer_c, gDeepDispose, self)(self); 
} 

imeth void * Pointer_im_gPointerValue(object self)
{ Pointer_iv_t *iv = GetIVs(Pointer, self);
	return iv->iVal; 
} 

imeth objrtn Pointer_im_gChangeValue(object self, object val)
{ Pointer_iv_t *iv = GetIVs(Pointer, self);
	iv->iVal = (void *) val; 
	return self; 
} 

imeth int Pointer_im_gHash(object self)
{ Pointer_iv_t *iv = GetIVs(Pointer, self);
	double t; 

	t = .6125423371 * (double) (unsigned long) iv->iVal; 
	t = t < 0.0 ? -t : t; 
	return (int) (BIG_INT * (t - floor(t))); 
} 

imeth int Pointer_im_gCompare(object self, object obj)
{ Pointer_iv_t *iv = GetIVs(Pointer, self);
	void *sv, *ov; 

	ChkArg(obj, 2); 
	if (ClassOf(obj) != CLASS) 
		return oSuper(Pointer_c, gCompare, self)(self, obj); 
	if ((sv=iv->iVal) < (ov=ivPtr(obj)->iVal)) 
		return -1; 
	else if (sv == ov) 
		return 0; 
	else 
		return 1; 
} 

imeth objrtn Pointer_im_gStringRepValue(object self)
{ Pointer_iv_t *iv = GetIVs(Pointer, self);
	return vSprintf(String, "%lp", iv->iVal); 
} 


#line 114 "Pointer.c"

objrtn	Pointer_initialize(void)
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

	if (Pointer_c) {
		LEAVECRITICALSECTION(cs);
		return Pointer_c;
	}
	INHIBIT_THREADER;
	Pointer_c = gNewClass(Class, "Pointer", sizeof(Pointer_iv_t), 0, END);
	cMethodFor(Pointer, gNewWithPtr, Pointer_cm_gNewWithPtr);
	iMethodFor(Pointer, gCompare, Pointer_im_gCompare);
	iMethodFor(Pointer, gPointerValue, Pointer_im_gPointerValue);
	iMethodFor(Pointer, gStringRepValue, Pointer_im_gStringRepValue);
	iMethodFor(Pointer, gHash, Pointer_im_gHash);
	iMethodFor(Pointer, gChangeValue, Pointer_im_gChangeValue);
	iMethodFor(Pointer, gDeepDispose, Pointer_im_gDeepDispose);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return Pointer_c;
}



