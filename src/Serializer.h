#ifndef SERIALIZER_H_
#define SERIALIZER_H_

class Serializer{
	public:
		static unsigned char *serialize_char(unsigned char *buffer, char val);
		static unsigned char *deserialize_char(unsigned char *buffer, char *val);
		static unsigned char *serialize_char_array(unsigned char *buffer, char *val, int size);
		static unsigned char *deserialize_char_array(unsigned char *buffer, char *val, int size);
		static unsigned char *serialize_int(unsigned char *buffer, int val);
		static unsigned char *deserialize_int(unsigned char *buffer, int *val);
		static unsigned char *serialize_ulong(unsigned char *buffer, unsigned long val);
		static unsigned char *deserialize_ulong(unsigned char *buffer, unsigned long *val);
};

#endif
