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




#define	CLASS	Class_c
#define	ivType	Class_iv_t

#include "generics.h"

object	Class_c;


#line 34 "Class.d"
objrtn Class_initialize(void) 
{ 
	static int done = 0; 




	if (done) 
		return Class_c; 

	done = 1; 



	return Class_c; 
} 

#if 0 

cmeth objrtn Class_cm_gFindClass(object self, char *name){} 
cmeth objrtn Class_cm_gNewStdClass(object self, char *name, int ivsize, object mc, int nipib, object superclasses, va_list _rest_){} 

#line 71 "Class.c"

static	objrtn	Class_cfm_gNewStdClass(object self, char *name, int ivsize, object mc, int nipib, object superclasses, ...)
{
	va_list	_rest_;
	va_start(_rest_, superclasses);
	return Class_cm_gNewStdClass(self, name, ivsize, mc, nipib, superclasses, _rest_);
}



#line 55 "Class.d"
cmeth objrtn Class_cm_gNewClass(object self, char *name, int ivsize, int cvsize, object superclasses, va_list _rest_){} 

#line 85 "Class.c"

static	objrtn	Class_cfm_gNewClass(object self, char *name, int ivsize, int cvsize, object superclasses, ...)
{
	va_list	_rest_;
	va_start(_rest_, superclasses);
	return Class_cm_gNewClass(self, name, ivsize, cvsize, superclasses, _rest_);
}



#line 56 "Class.d"
cmeth objrtn Class_cm_gGetAll(object self){} 

#endif 

