#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: pointer to the name of the file.
 * @text_content: string to add to the end of the file.
 *
 * Return: 1 if the file exists and -1 if the file does not exist or
 * if you do not have the required permissions to write the file
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int p, e, length = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	p = open(filename, O_WRONLY | O_APPEND);
	e = write(p, text_content, length);

	if (p == -1 || e == -1)
	{
		return (-1);
	}

	close(p);
	return (1);
}
