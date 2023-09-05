#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename: name of the file
 * @text_content: The NULL-terminated string to write to the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int j, k, length = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	j = open(filename, O_WRONLY | O_APPEND);
	k = write(j, text_content, length);

	if (j == -1 || k == -1)
	{
		return (-1);
	}
	
	close(j);
	return (1);
}
