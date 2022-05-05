#include <cstring>

#include "Serializer.h"

unsigned char *Serializer::serialize_char(unsigned char * buffer, char val){

	buffer[0] = val;

	return buffer + 1;

}

unsigned char *Serializer::deserialize_char(unsigned char * buffer, char *val){

	*val = buffer[0];

	return buffer + 1;

}

unsigned char *Serializer::serialize_char_array(unsigned char *buffer, char *val, int size){

	memcpy((void *)buffer, (void *)val, size);

	return buffer + size;

}

unsigned char *Serializer::deserialize_char_array(unsigned char *buffer, char *val, int size){

	memcpy((void *)val, (void *)buffer, size);

	return buffer + size;

}

unsigned char *Serializer::serialize_int(unsigned char *buffer, int val){

	int i;
	int shift_width;
	int size;

	size = sizeof(int);

	for(i = 0, shift_width = (size - 1) * 8; i < size; ++i, shift_width -= 8){
		buffer[i] = (val >> shift_width) & 0xFF;
	}

	return buffer + size;

}

unsigned char *Serializer::deserialize_int(unsigned char *buffer, int *val){

	int i;
	int shift_width;
	int size;
	int temp;

	size = sizeof(int);

	*val = 0;
	temp = 0;
	for(i = 0, shift_width = (size - 1) * 8; i < size; ++i, shift_width -= 8){
		temp = buffer[i];
		temp <<= shift_width;
		*val = *val | temp;
		temp = 0;
	}

	return buffer + size;

}

unsigned char *Serializer::serialize_ulong(unsigned char *buffer, unsigned long val){

	int i;
	int shift_width;
	int size;

	size = sizeof(unsigned long);

	for(i = 0, shift_width = (size - 1) * 8; i < size; ++i, shift_width -= 8){
		buffer[i] = val >> shift_width;
	}

	return buffer + size;

}

unsigned char *Serializer::deserialize_ulong(unsigned char *buffer, unsigned long *val){

	int i;
	int shift_width;
	int size;
	unsigned long temp;

	size = sizeof(unsigned long);

	*val = 0;
	temp = 0;
	for(i = 0, shift_width = (size - 1) * 8; i < size; ++i, shift_width -= 8){
		temp = buffer[i];
		temp <<= shift_width;
		*val = *val | temp;
		temp = 0;
	}

	return buffer + size;

}
