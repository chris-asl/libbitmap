CC = gcc
FLAGS = -c
OBJS = demo.o Bitmap.o
EXECUTABLE_NAME = bitmap-demo

# Compile
all: $(OBJS)
	$(CC) $(OBJS) -o $(EXECUTABLE_NAME)
	rm -f $(OBJS)

demo.o: demo.c
	$(CC) $(FLAGS) demo.c

Bitmap.o: Bitmap.c
	$(CC) $(FLAGS) Bitmap.c

run:
	./$(EXECUTABLE_NAME)

# Clean-up
clean:
	rm -f $(EXECUTABLE_NAME)
