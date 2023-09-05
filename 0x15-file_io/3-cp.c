#include "main.h"


/**
 * error_exit - error message and exit with the specified code.
 * @exit_code: exit code.
 * @format: format string for the error message.
 * @...: additional arguments for the format string.
 */
void error_exit(int exit_code, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    dprintf(STDERR_FILENO, format, args);
    va_end(args);
    exit(exit_code);
}

/**
 * main - cp the content of one file to another.
 * @argc: number of command-line arguments.
 * @argv: array of command-line arguments.
 *
 * Return: 0 on success, 97, 98, 99, or 100 on failure as described in the prompt.
 */
int main(int argc, char *argv[])
{
    int from_f_des, to_f_des;
    ssize_t bytes_read, bytes_written;
    char buffer[1024];
    mode_t file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    if (argc != 3)
    {
        error_exit(97, "Usage: %s file_from file_to\n", argv[0]);
    }

    from_f_des = open(argv[1], O_RDONLY);
    if (from_f_des == -1)
    {
        error_exit(98, "Error: Can't read from file %s\n", argv[1]);
    }

    to_f_des = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_mode);
    if (to_f_des == -1)
    {
        error_exit(99, "Error: Can't write to file %s\n", argv[2]);
    }

    while ((bytes_read = read(from_f_des, buffer, sizeof(buffer))) > 0)
    {
        bytes_written = write(to_f_des, buffer, bytes_read);
        if (bytes_written == -1)
	{
            error_exit(99, "Error: Can't write to file %s\n", argv[2]);
        }
    }

    if (bytes_read == -1)
    {
        error_exit(98, "Error: Can't read from file %s\n", argv[1]);
    }

    if (close(from_f_des) == -1)
    {
        error_exit(100, "Error: Can't close f_des %d\n", from_f_des);
    }

    if (close(to_f_des) == -1)
    {
        error_exit(100, "Error: Can't close f_des %d\n", to_f_des);
    }

    return 0;
}
