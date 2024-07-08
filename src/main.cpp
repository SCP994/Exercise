#include <cstdio>

#include "pat.h"

int main()
{
	// pat_a_1010();

	char s1[] = "hello";
	char s2[] = "hel";

	char* p1 = s1;
	char* p2 = s2;

	std::cout << strlen(p1) << " " << strlen(p2) << std::endl;

	std::swap(p1, p2);

	std::cout << strlen(p1) << " " << strlen(p2) << std::endl;


	return 0;
}
