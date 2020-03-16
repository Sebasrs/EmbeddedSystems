APP=libMathOwn

SRCS=$(APP).c
OBJS=$(APP).o

CC=gcc

CFLAGS=-c -Wall
LFLAGS=-Wall

clean: $(APP).a $(APP).so
		rm $(APP).o

# Static library creation
$(APP).a : $(OBJS)
		ar rv $(APP).a $(OBJS)
		ranlib $(APP).a

# Dynamic library creation
$(APP).so : $(OBJS)
		ld -o $(APP).so $(APP).o -shared

.c.o:
		$(CC) $(CFLAGS) $<