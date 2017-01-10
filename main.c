#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

FILE * open_serial_port( void )
{
	int fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NONBLOCK);
	if ( fd < 0 )
	{
		printf("unable to open /dev/ttyAMA0 (do you have the correct rights)");
		exit(1);
	}
	return fdopen(fd, "rw");
}

void send_hello( FILE * f )
{
	fprintf( f, "hello from client" );
}

void listen_and_respond( FILE * f, int mode )
{
	static counter;
	char buffer[256];
	int n = fscanf( f, "%255s", buffer );
	printf( "recv(%d):%s;;\n", n, buffer);
	if ( mode )
	{
		sleep(1);
		fprintf( f, "hello %d again", counter++ );
	}
	else
	{
		counter += n;
		fprintf( f, "recv(%d)", counter );
	}
}

int main( int argc, char * argv[] )
{
	FILE * f = open_serial_port();
	printf("serial port handle = %d;;\n", (int)f);

	if ( !f ) exit( 1 );

	if (argc > 1)
	{
		send_hello( f );
	}
	listen_and_respond( f, (argc > 1) );

	return 0;
}

