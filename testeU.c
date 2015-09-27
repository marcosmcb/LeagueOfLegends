#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(){

	uint8_t teste;

	scanf ("%" SCNu8, &teste);

	printf("%" PRIu8 "\n",teste);

	return 0;
}
