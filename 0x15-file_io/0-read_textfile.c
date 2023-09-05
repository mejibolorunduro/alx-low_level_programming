#include "main.h"

/**
 *  read_textfile - function that reads a text file and
 *  prints it to the POSIX standard output
 *  @letters: number of letters it should read and print
 *  @filename: name of the file
 *  Returns:  the actual number of letters it could read and print
 *  0 if filename is NULL return
 *  0 if write fails or does not write the expected amount of bytes, return
 *  0 if the file can not be opened or read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fread;
	ssize_t j;
	ssize_t k;

	fread = open(filename, O_RDONLY);
	if (fread == -1)
	{
		return (0);
	}
	buffer = malloc(sizeof(char) * letters);
	k = read(fread, buffer, letters);
	j = write(STDOUT_FILENO, buffer, k);

	free(buffer);
	close(fread);
	return (j);
}
