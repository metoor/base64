#include <cstdio>
#include "base64.h"

int main()
{
	char src[] = "caiufen@qq.com";
	char buffer[255];
	base64_encode(buffer, src);

	printf("%s\n", buffer);

	return 0;
}