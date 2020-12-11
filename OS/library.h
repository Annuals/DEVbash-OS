char* thing = (char*) 0xB8000;
unsigned short pointerx = 0;
unsigned short pointery = 0;



void writechar(int x, int y, char c, int color) {
    int start = 2 * x + 160 * y;
    thing[start] = c;
    thing[start + 1] = color;
}

void clear() {
    for (int x = 0; x < 80; x++) {
        for (int y = 0; y < 25; y++) {
            writechar(x, y, ' ', 0x0);
        }
    }
}


void showtext(char* thestr) {
	int thelen = -1;
	int color = 0x0F;
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