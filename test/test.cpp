#include <gtest/gtest.h>
#include <iostream>

#include "Serializer.h"

TEST(SerializerTest, SerializesChar){

	char c;
	unsigned char buffer[100];
	unsigned char *end;	

	end = buffer;

	c = 'a';
	end = Serializer::serialize_char(end, c);
	c = 'b';
	end = Serializer::serialize_char(end, c);
	c = 'c';
	end = Serializer::serialize_char(end, c);

	ASSERT_EQ(end - buffer, 3);
	ASSERT_EQ(buffer[0], 'a');
	ASSERT_EQ(buffer[1], 'b');
	ASSERT_EQ(buffer[2], 'c');

}

TEST(SerializerTest, DeserializesChar){

	char c;
	unsigned char buffer[] = {'a', 'b', 'c'};
	unsigned char *end;	

	end = buffer;

	end = Serializer::deserialize_char(end, &c);
	ASSERT_EQ(c, 'a');
	end = Serializer::deserialize_char(end, &c);
	ASSERT_EQ(c, 'b');
	end = Serializer::deserialize_char(end, &c);
	ASSERT_EQ(c, 'c');
	ASSERT_EQ(end - buffer, 3);

}

TEST(SerializerTest, SerializesCharArray){

	char c[] = {"abc"};
	int size = 3;
	unsigned char buffer[100];
	unsigned char *end;	

	end = buffer;

	end = Serializer::serialize_char_array(end, c, size);

	ASSERT_EQ(end - buffer, size);
	ASSERT_EQ(buffer[0], 'a');
	ASSERT_EQ(buffer[1], 'b');
	ASSERT_EQ(buffer[2], 'c');

}

TEST(SerializerTest, DeserializesCharArray){

	char c[100];
	int size = 3;
	unsigned char buffer[] = {"abc"};
	unsigned char *end;	

	end = buffer;

	end = Serializer::deserialize_char_array(end, c, size);
	ASSERT_EQ(end - buffer, size);
	ASSERT_EQ(c[0], 'a');
	ASSERT_EQ(c[1], 'b');
	ASSERT_EQ(c[2], 'c');

}

TEST(SerializerTest, SerializesInt){

	int val;
	unsigned char buffer[100];
	unsigned char *end;

	end = buffer;

	val = 0b11010111010010100110100100111100;
	end = Serializer::serialize_int(end, val);

	ASSERT_EQ(end - buffer, sizeof(int));
	ASSERT_EQ(buffer[sizeof(int) - 1], 0b00111100);
	ASSERT_EQ(buffer[sizeof(int) - 2], 0b01101001);
	ASSERT_EQ(buffer[sizeof(int) - 3], 0b01001010);
	ASSERT_EQ(buffer[sizeof(int) - 4], 0b11010111);

}

TEST(SerializerTest, DeserializesInt){

	int val;
	unsigned char buffer[] = {0b01010111, 0b01001010, 0b01101001, 0b00111100};
	unsigned char *end;

	end = buffer;

	end = Serializer::deserialize_int(end, &val);
	ASSERT_EQ(end - buffer, sizeof(int));
	ASSERT_EQ(val, 0b01010111010010100110100100111100);

}

TEST(SerializerTest, SerializesULong){

	unsigned long val;
	unsigned char buffer[100];
	unsigned char *end;

	end = buffer;

	val = 0b11010111010010100110100100111100;
	end = Serializer::serialize_ulong(end, val);

	ASSERT_EQ(end - buffer, sizeof(unsigned long));
	ASSERT_EQ(buffer[sizeof(unsigned long) - 1], 0b00111100);
	ASSERT_EQ(buffer[sizeof(unsigned long) - 2], 0b01101001);
	ASSERT_EQ(buffer[sizeof(unsigned long) - 3], 0b01001010);
	ASSERT_EQ(buffer[sizeof(unsigned long) - 4], 0b11010111);

}

TEST(SerializerTest, DeserializesULong){

	unsigned long val;
	unsigned char buffer[] = {0b01010111, 0b01001010, 0b01101001, 0b00111100, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
	unsigned char *end;

	end = buffer;

	end = Serializer::deserialize_ulong(end, &val);
	ASSERT_EQ(end - buffer, sizeof(unsigned long));
	ASSERT_EQ(val, 0b0101011101001010011010010011110000000000000000000000000000000000);

}

int main(int argc, char *argv[]){

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
