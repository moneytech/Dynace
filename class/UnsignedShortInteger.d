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




#include <math.h>

defclass  UnsignedShortInteger : Number  {
	unsigned short	int	iVal;
};

cmeth	gNewWithUnsigned, <vNew> (unsigned val)
{
	object	obj = gNew(super);
	ivType	*iv = ivPtr(obj);
	iVal = (unsigned short int) val;
	return(obj);
}

imeth	int	gHash()
{
	double	t;

	t = .6125423371	* iVal;
	t = t < 0.0 ? -t : t;
	return (int) (BIG_INT * (t - floor(t)));
}

imeth	int	gCompare(obj)
{
	unsigned short	sv, ov;

	ChkArg(obj, 2);
	if (ClassOf(obj) != CLASS)
		return gCompare(super, obj);
	if ((sv=iVal) < (ov=ivPtr(obj)->iVal))
		return -1;
	else if (sv == ov)
		return 0;
	else
		return 1;
}

imeth	gStringRepValue()
{
	return vSprintf(String, "%hu", iVal);
}

imeth	char	gCharValue()
{
	return (char) iVal;
}

imeth	short	gShortValue()
{
	return (short) iVal;
}

imeth	unsigned short	gUnsignedShortValue()
{
	return (unsigned short) iVal;
}

imeth	long	gLongValue()
{
	return (long) iVal;
}

imeth	double	gDoubleValue()
{
	return (double) iVal;
}

imeth	void	*gPointerValue()
{
	return (void *) &iVal;
}

imeth	gChangeValue(val)
{
	ChkArg(val, 2);
	iVal = gUnsignedShortValue(val);
	return self;
}

imeth	gChangeCharValue(int val)
{
	iVal = (unsigned short) val;
	return self;
}

imeth	gChangeShortValue(int val)
{
	iVal = (unsigned short) val;
	return self;
}

imeth	gChangeUShortValue(unsigned val)
{
	iVal = (unsigned short) val;
	return self;
}

imeth	gChangeLongValue(long val)
{
	iVal = (unsigned short) val;
	return self;
}

imeth	gChangeDoubleValue(double val)
{
	iVal = (unsigned short) val;
	return self;
}



