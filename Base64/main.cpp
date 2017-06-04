#include <cstdio>
#include "base64.h"

int main()
{
	char src[] = "caiufen@qq.com";
	char bufferEn[255] = {0};
	char bufferDe[255] = {0};

	base64_encode(bufferEn, src);
	base64_decode(bufferDe,bufferEn);

	printf("encode:%s\n", bufferEn);
	printf("decode:%s\n", bufferDe);

	return 0;
}