#include "lib/libout.h"
#include "input.h"
#include "terminal.h"

int osmain()
{
	terminal_main();

	idt_init();
	kb_init();

	while(1);
}

/*
## About ##
- Name : DEVbash
- Version : 0.3.1
- Creators : Diary (Tyler)
- Description: DEVbash is an open source OS (Operating System) That is currently in its BETA stages. It is currently not done yet.
#############
*/
