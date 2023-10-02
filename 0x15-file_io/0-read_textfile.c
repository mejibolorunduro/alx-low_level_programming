#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads a text file and prints it
 * to the POSIX standard output.
 * @filename: the text file being read
 * @letters: the number of letters to be read
 * Return: returns the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t e;
	ssize_t y;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	buf = malloc(sizeof(char) * letters);
	y = read(fd, buf, letters);
	e = write(STDOUT_FILENO, buf, y);

	free(buf);
	close(fd);
	return (e);
}
