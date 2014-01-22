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




#define	CLASS	SeriousCondition_c
#define	ivType	SeriousCondition_iv_t

#include "generics.h"

object	SeriousCondition_c;



#line 34 "SeriousCondition.d"
imeth objrtn SeriousCondition_im_gDefaultRestart(object self)
{ 
	return vNew(Abort, self); 
} 


#line 56 "SeriousCondition.c"

objrtn	SeriousCondition_initialize(void)
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

	if (SeriousCondition_c) {
		LEAVECRITICALSECTION(cs);
		return SeriousCondition_c;
	}
	INHIBIT_THREADER;
	Condition_initialize();
	if (SeriousCondition_c)  {
		ENABLE_THREADER;
		LEAVECRITICALSECTION(cs);
		return SeriousCondition_c;
	}
	SeriousCondition_c = gNewClass(Class, "SeriousCondition", 0, 0, Condition, END);
	iMethodFor(SeriousCondition, gDefaultRestart, SeriousCondition_im_gDefaultRestart);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return SeriousCondition_c;
}



