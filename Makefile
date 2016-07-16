# main.mk

OBJS = main.o edge.o node.o
CC = g++
CFLGS = -std=c++14 -c
LFLGS =

# $@ - the target of this rule
# $^ - all prerequisites of this rule
main : $(OBJS)
	$(CC) $(LFLGS) $^ -o $@

edge.o : edge.cpp edge.h
	$(CC) $(CFLGS) edge.cpp

node.o : node.cpp node.h
	$(CC) $(CFLGS) node.cpp

main.o : main.cpp graph.h edge.h node.h
	$(CC) $(CFLGS) main.cpp

clean :
	\rm *.o
