/*************************************************
// Copyright (C), 2016-2020, CS&S. Co., Ltd.
// File name: 	base64.h
// Author:		 Metoor
// Version: 	1.0 
// Date: 		2017/05/21
// Contact: 	caiufen@qq.com
// Description: 	create by vs2015pro
*************************************************/

#ifndef BASE64_H_  
#define BASE64_H_  
  
int base64_encode(char *output, char *input);

int base64_decode(char * output, const char * input);

#endif // BASE64_H_ 
