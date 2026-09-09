#include "platforms.hpp"

#include <stdio.h>
#include <unistd.h>
#include <iostream>

int main(void)
{
    platform_init();
	
	while(1) {
		platform_frame();
	}

	return 0;
}