CC=gcc

CFLAGS =-g -Wall -fPIC
TEST_CFLAGS =-g

LDFLAGS =
TEST_LDFLAGS =

OBJECT_FILES = caesar_cipher.o
OBJECT_TEST_FILES = cesar_cipher_test.o
HEADER_FILES = -I./

CFLAGS +=$(HEADER_FILES)
CFLAGS += `pkg-config --cflags --libs glib-2.0`

TEST_CFLAGS +=$(HEADER_FILES)
TEST_CFLAGS += `pkg-config --cflags glib-2.0 cmocka`
TEST_LDFLAGS =`pkg-config --libs glib-2.0 cmocka`

all: test

test: object
	$(CC) $(TEST_CFLAGS) cesar_cipher_test.c -o $@ $(OBJECT_FILES) $(TEST_LDFLAGS)

object: $(OBJECT_FILES)

%.o:.c
	$(CC) $(CFLAGS) $@

.PHONY: clean

clean:
	rm *.o
	rm test
