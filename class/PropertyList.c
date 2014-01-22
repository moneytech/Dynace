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




#define	CLASS	PropertyList_c
#define	ivType	PropertyList_iv_t

#include "generics.h"

object	PropertyList_c;


#line 48 "PropertyList.c"
typedef struct  _PropertyList_iv_t  {
	object iPropertyList;
}	PropertyList_iv_t;



#line 37 "PropertyList.d"
imeth objrtn PropertyList_im_gPropertyPut(object self, char *prop, int autoDispose, object val)
{ PropertyList_iv_t *iv = GetIVs(PropertyList, self);
	object intAssoc; 

	if (!iv->iPropertyList) 
		iv->iPropertyList = gNew(StringDictionary); 
	if (!gAddStr(iv->iPropertyList, prop, intAssoc=gNewWithIntObj(IntegerAssociation, autoDispose, val))) { 
		object old = gChangeValueWithStr(iv->iPropertyList, prop, intAssoc); 
		if (gIntKey(old)) 
			gDeepDispose(old); 
		else 
			gDispose(old); 
	} 
	return val; 
} 

imeth objrtn PropertyList_im_gPropertyGet(object self, char *prop)
{ PropertyList_iv_t *iv = GetIVs(PropertyList, self);
	object v = NULL; 

	if (iv->iPropertyList) { 
		v = gFindValueStr(iv->iPropertyList, prop); 
		if (v) 
			v = gValue(v); 
	} 
	return v; 
} 

imeth objrtn PropertyList_im_gPropertySetAutoDispose(object self, char *prop, int autoDispose)
{ PropertyList_iv_t *iv = GetIVs(PropertyList, self);
	object v = NULL; 

	if (iv->iPropertyList) { 
		v = gFindValueStr(iv->iPropertyList, prop); 
		if (v) 
			gChangeIntKey(v, autoDispose); 
	} 
	return v; 
} 

imeth objrtn PropertyList_im_gPropertyRemove(object self, char *prop)
{ PropertyList_iv_t *iv = GetIVs(PropertyList, self);
	object strAssoc, intAssoc; 

	if (!iv->iPropertyList) 
		return NULL; 
	strAssoc = gFindStr(iv->iPropertyList, prop); 
	if (!strAssoc) 
		return NULL; 
	intAssoc = gValue(strAssoc); 
	if (gIntKey(intAssoc)) 
		gDeepDisposeStr(iv->iPropertyList, gStringKey(strAssoc)); 
	else { 
		gRemoveStr(iv->iPropertyList, gStringKey(strAssoc)); 
		gDispose(intAssoc); 
	} 
	return self; 
} 

imeth objrtn PropertyList_im_gDisposePropertyList(object self)
{ PropertyList_iv_t *iv = GetIVs(PropertyList, self);
	object strAssoc, intAssoc; 

	if (!iv->iPropertyList) 
		return NULL; 
	while (strAssoc = gFirst(iv->iPropertyList)) { 
		intAssoc = gValue(strAssoc); 
		if (gIntKey(intAssoc)) 
			gDeepDisposeStr(iv->iPropertyList, gStringKey(strAssoc)); 
		else { 
			gRemoveStr(iv->iPropertyList, gStringKey(strAssoc)); 
			gDispose(intAssoc); 
		} 
	} 
	iv->iPropertyList = gDeepDispose(iv->iPropertyList); 
	return self; 
} 

imeth objrtn PropertyList_im_gDispose(object self)
{ 
	gDisposePropertyList(self); 
	return oSuper(PropertyList_c, gDispose, self)(self); 
} 

imeth objrtn PropertyList_im_gSetPropertyList(object self, object pl)
{ PropertyList_iv_t *iv = GetIVs(PropertyList, self);
	object old = iv->iPropertyList; 
	iv->iPropertyList = pl; 
	return old; 
} 

imeth objrtn PropertyList_im_gCopy(object self)
{ PropertyList_iv_t *iv = GetIVs(PropertyList, self);
	object copy = oSuper(PropertyList_c, gCopy, self)(self); 
	if (iv->iPropertyList) 
		gSetPropertyList(copy, gDeepCopy(iv->iPropertyList)); 
	return copy; 
} 


#line 156 "PropertyList.c"

objrtn	PropertyList_initialize(void)
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

	if (PropertyList_c) {
		LEAVECRITICALSECTION(cs);
		return PropertyList_c;
	}
	INHIBIT_THREADER;
	PropertyList_c = gNewClass(Class, "PropertyList", sizeof(PropertyList_iv_t), 0, END);
	iMethodFor(PropertyList, gPropertyRemove, PropertyList_im_gPropertyRemove);
	iMethodFor(PropertyList, gPropertyPut, PropertyList_im_gPropertyPut);
	iMethodFor(PropertyList, gDispose, PropertyList_im_gDispose);
	iMethodFor(PropertyList, gSetPropertyList, PropertyList_im_gSetPropertyList);
	iMethodFor(PropertyList, gDisposePropertyList, PropertyList_im_gDisposePropertyList);
	iMethodFor(PropertyList, gPropertyGet, PropertyList_im_gPropertyGet);
	iMethodFor(PropertyList, gCopy, PropertyList_im_gCopy);
	iMethodFor(PropertyList, gDeepDispose, PropertyList_im_gDispose);
	iMethodFor(PropertyList, gPropertySetAutoDispose, PropertyList_im_gPropertySetAutoDispose);
	iMethodFor(PropertyList, gDeepCopy, PropertyList_im_gCopy);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return PropertyList_c;
}



