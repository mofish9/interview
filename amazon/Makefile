#---------------------------------------------
# Makefile for Search method and tests
# 
# Author : huww06@gmail.com
# Date   : 2013-01-12
# 
# Version: 1.0
#---------------------------------------------

# target name
TARGET=search
CC=gcc
CFLAGS=-Wall -I.

SOURCES:=*.c
INCLUDES:=*.h
OBJECTS:=$(SOURCES:.c=*.o)

# link the objs
$(TARGET):obj
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJECTS)

# compile the source files
obj:$(SOURCES) $(INCLUDES)
	$(CC) -c $(CFLAGS) $(SOURCES)

# clean
clean:
	rm -f $(TARGET) $(OBJECTS)
