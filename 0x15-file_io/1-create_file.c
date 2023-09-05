#include "main.h"

/**
 * create_file - function that creates a file.
 * @filename: name of the file to create.
 * @text_content: The NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int f_des, j, length = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	f_des = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	j = write(f_des, text_content, length);

	if (f_des == -1 || j == -1)
	{
		return (-1);
	}
	close(f_des);
	return (1);
}
