#include <stdio.h>
#include <inttypes.h>
void printBits(int *reg) {
    for (int i = 0; i < 8; i++) {
		printf("%d", *reg & 0x01);
		*reg = *reg >> 1;
	}
	puts("");
}:w
void setBit(int bit, int *reg) {
	int mask = 1;
	mask = mask << bit;
	*reg |= mask;
}
void clearBit(int bit, int *reg) {
	int mask = 1;
	mask = mask << bit;
	mask = ~mask;
	*reg &= mask;
}
void invertBit(int bit, int *reg) {
	int mask = 1;
	mask = mask << bit;
	*reg ^= mask;
}
void setBitArray(int bit, uint8_t array[]) {
	int i = bit / 8; // index - array[i]
	int position = bit % 8;	  // bit position
	int mask = 1;
	mask = mask << position;
	array[i] |= mask;
}

void clearBitArray(int bit, uint8_t array[]) {
	int i = bit / 8;
	int position = bit % 8;
	int mask = 1;
	mask = mask << position;
	mask = ~mask;
	array[i] &= mask;
}
void invertBitArray(int bit, uint8_t array[]) {
	int i = bit / 8;
	int pos = bit % 8, mask = 1;
	mask = mask << pos;
	array[i] ^= mask;
}

int main() {
	//uint8_t array[]={1,10,5,6,200};
	int a = 5;
    int *p = &a;
	invertBit(2, p);
    
	printBits(p);
}