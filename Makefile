.PHONY: all

CURRENT_WORKING_DIR = $(shell pwd)
OUTPUT_FILES =
OUTPUT_FILES += a.out
CFLAGS += -g -O0
CFLAGS += -I$(CURRENT_WORKING_DIR)/include
LIBCRYPTO = $(CURRENT_WORKING_DIR)/libcrypto.so

all: $(OUTPUT_FILES)

a.out: main.o
	$(LINK.o) -o $@ $< $(LIBCRYPTO)

%.o: %.c %.h
	$(COMPILE.c) $< -o $@
main.o: main.c
	$(COMPILE.c) $< -o $@
