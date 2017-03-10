CC = gcc
CC_OPTIONS =   -O2 -Wall 
EXEC = euler.x
LIBS = -lm 

OBJS = struct.o main.o
INCL = Makefile struct.h

.c.o:
	$(CC) $(CC_OPTIONS) -c $<

all: $(EXEC)

$(EXEC):$(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(EXEC)
clean:
	rm -f $(OBJS) *~ core* ${EXEC}
