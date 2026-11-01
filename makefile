CC = gcc
CFLAGS = -Wall -Wextra

TARGET = student

SOURCES = main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
