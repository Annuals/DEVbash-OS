#ifndef TERMINAL_H
#define TERMINAL_H

void reset_terminal(){
    pointerx = 0;
    pointery = 0;
}

void terminal_main(){
    clear();
	char first = 1;
	fill(0x1F);
	print1("DEVbash [Version 0.2]\n",-1, 0x1F);
	print1("<c> Copyright 2020 DEVbash. All rights reserved.\n\n",-1, 0x1F);

	for(int i = 0; i < 3; i++){
	    kprint_newline();
	}

	kprint("C:/Users/System> ");
}

#endif
