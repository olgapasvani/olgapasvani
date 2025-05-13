CC = g++
CFLAGS = -Wall -g

TARGET = main

all:$(TARGET)

$(TARGET): main.o course.o person.o professor.o student.o secretary.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o course.o person.o professor.o student.o secretary.o

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)