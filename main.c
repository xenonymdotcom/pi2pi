#include <stdio.h>

int open_serial_port()
{
	int fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NONBLOCK);
	if ( fd < 0 )
	{
		printf("unable to open /dev/ttyAMA0 (do you have the correct rights)");
		exit(1);
	}
}


int main( int argc, char * argv[] )
{
	int sp = open_serial_port();
	printf("serial port handle = %d;;", sp);
	return 0;
}
