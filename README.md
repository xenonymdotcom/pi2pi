# pi2pi
simple Raspberry Pi to Raspberry PI comms software

This project (once written) will allow 2 Raspberry pis to communicate 
back to back using `/dev/ttyAMA0` serial coms

make sure you are in the tty group 
use `sudo usermod -a -G tty <yourname>`

and may sure that `/dev/ttyAMA0` is readable by the tty group
use `sudu chmod g+r /dev/ttyAMA0` if it is only writeable
by the tty group as mine was.
