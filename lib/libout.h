char* thing = (char*) 0xB8000;
unsigned short pointerx = 0;
unsigned short pointery = 0;

char keybuffer[500];
short size = 0;

void writechar(int x, int y, char c, int color) {
    int start = 2 * x + 160 * y;
    thing[start] = c;
    thing[start + 1] = color;
}

void print2(char* str) {
	unsigned short* VideoMemory = (unsigned short*)0xb8000;

	for(int i = 0; str[i] != '\0'; ++i) {
		VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
	}
}

void clear() {
    for (int x = 0; x < 80; x++) {
        for (int y = 0; y < 25; y++) {
            writechar(x, y, ' ', 0x0);
        }
    }
}

void fill(unsigned short color) {
    for (int x = 0; x < 80; x++) {
        for (int y = 0; y < 25; y++) {
            writechar(x, y, ' ', color);
        }
    }
}

void fillRect(unsigned short color, int x, int y, int w, int h){
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            writechar(x + i, y + j, ' ', color);
        }
    }
}

void drawCircle(unsigned short color, int x, int y, int r){
    int dx = r;
    int dy = 0;
    int err = 1-r;
    while(dx >= dy){
        writechar(x+dx,y+dy,' ',color);
        writechar(x-dx,y+dy,' ',color);
        writechar(x+dx,y-dy,' ',color);
        writechar(x-dx,y-dy,' ',color);
        writechar(x+dy,y+dx,' ',color);
        writechar(x-dy,y+dx,' ',color);
        writechar(x+dy,y-dx,' ',color);
        writechar(x-dy,y-dx,' ',color);
        dy += 1;
        if(err < 0){
            err += 2 * dy + 1;
        }else{
            dx = dx - 1;
            err = err + 2 * (dy - dx) + 1;
        }
    }
}

void print1(char* thestr, int thelen, int color) {
    if (thelen < 0) {
        int i = 0;

        while (thestr[i] != '\0') {
            if (thestr[i] == '\n') {
                pointerx = 0;
                pointery++;
                i++;
                continue;
            }

            writechar(pointerx, pointery, thestr[i], color);
            pointerx++;
            i++;
        }

        return;
    }

    for (int i = 0; i < thelen; i++) {
        if (thestr[i] == '\n') {
            pointerx = 0;
            pointery++;
            i++;
            continue;
        }

        writechar(pointerx, pointery, thestr[i], color);
        pointerx++;
    }
}
