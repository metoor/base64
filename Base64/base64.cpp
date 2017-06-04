/*************************************************
// Copyright (C), 2016-2017, CS&S. Co., Ltd.
// File name: 	base64.cpp
// Author:		 Metoor
// Version: 	1.0 
// Date: 		2017/05/21
// Contact: 	caiufen@qq.com
// Description: 	create by vs2015pro
*************************************************/

#include "base64.h"
#include <cstring>

const char base64_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";



inline void a3_to_a4(unsigned char * a4, unsigned char * a3) {
	a4[0] = (a3[0] & 0xfc) >> 2;
	a4[1] = ((a3[0] & 0x03) << 4) + ((a3[1] & 0xf0) >> 4);
	a4[2] = ((a3[1] & 0x0f) << 2) + ((a3[2] & 0xc0) >> 6);
	a4[3] = (a3[2] & 0x3f);
}

inline void a4_to_a3(unsigned char * a3, unsigned char * a4) {
	a3[0] = (a4[0] << 2) + ((a4[1] & 0x30) >> 4);
	a3[1] = ((a4[1] & 0xf) << 4) + ((a4[2] & 0x3c) >> 2);
	a3[2] = ((a4[2] & 0x3) << 6) + a4[3];
}

inline unsigned char base64_char_index(char c) {
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	if (c >= 'a' && c <= 'z')
		return c - 71;
	if (c >= '0' && c <= '9')
		return c + 4;
	if (c == '+')
		return 62;
	if (c == '/')
		return 63;
	return -1;
}

int base64_encode(char * output, char * input)
{
	unsigned encodeLen = 0;
	unsigned i3 = 0;
	unsigned inputLen = strlen(input);
	unsigned len = inputLen;
	unsigned char a4[4];
	unsigned char a3[3];

	while (len--)
	{
		a3[i3++] = input[inputLen-len-1];
		if (i3 == 3)
		{
			a3_to_a4(a4, a3);
			for (int i = 0; i < 4;++i)
			{
				output[encodeLen++] = base64_alphabet[a4[i]];
			}
			i3 = 0;
		}
	}

	if (i3)
	{
		for (int i = i3; i < 3; i++) {
			a3[i] = '\0';
		}
		a3_to_a4(a4, a3);
		for (unsigned int i = 0; i < i3 + 1; i++) {
			output[encodeLen++] = base64_alphabet[a4[i]];
		}
		while (i3++ < 3)
		{
			output[encodeLen++] = '=';
		}
		output[encodeLen] = '\0';
	}

	return 0;
}

int base64_decode(char * output, char * input)
{
	return 0;
}