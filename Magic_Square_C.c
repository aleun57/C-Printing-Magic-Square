#include <stdio.h>

int main(void) {
int input = -1;
while(input < 1 || input > 13 || input % 2 == 0){
        printf("Please input a positive odd number:");
        scanf("%d", &input);
}

int a[13][13] = {{0}};
int sqfiller = 1, col = (input/2) ,row = 0,prevR,prevC;
*((*(a + row))+col) = sqfiller;  
sqfiller++;
// Fill out the empty array with the appropriate values
for(;sqfiller <= (input * input);++sqfiller) {
        if ((row-1) == -1) {
                row = input-1;		
        }
        else {
                row -= 1;
        }
        if ((col+1) == input) {
                col = 0;
        }
        else {
                col += 1;
        }
        
	if (*((*(a+row))+col) >= 1) {
		row = prevR + 1;
		col = prevC;
		if (row == input) {
			row = 0;
		}	

	}
	*((*(a + row))+col) = sqfiller;
	prevR = row;
	prevC = col;	
}

for(int outer = 0; outer < input; ++outer) {
        printf("\n");       
        
        //Print the numbers in one row
        for(int inner = 0; inner < input; ++inner) {
                printf("%d ", *((*(a + outer))+inner));
        }
}
}
