#include <stdio.h>

int main(){
	char density[] = " .,:ilwW";
	FILE * out;
	out = fopen("nerd-emoji-40x40.ppm", "r");
	int counter = 0;
	
	char data;
	
	for (int i=0; i<14; i++){
		data = fgetc(out);
		counter = i;
	}

	/* while (data != EOF){ */
	/* 	data = fgetc(out); */
	/* 	printf("%c", data); */
	/* 	counter += 1; */
	/* } */

	for (int i=0; i<40; i++){
		for (int j=0; j<40; j++){
			int r = fgetc(out);
			int g = fgetc(out);
			int b = fgetc(out);
			/* printf("(%d, %d, %d)\n", r, g, b); */
			int avg = (r+g+b)/3;
			int index = (avg * 8)/255;
			if (index >= 0){
				printf("%c%c", density[index], density[index]);
			}
		}
		printf("\n");
	}
	fclose(out);
	return 0;
}
