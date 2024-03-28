#include "monty.h"

/**
 * stream_failed - handles when reading a file fails
 * @filename: file that failed to open
 *
 */

void stream_failed(char *filename)
{
	dprintf(2, "Error: Can't open file %s\n", filename);
	free_args();
	exit(EXIT_FAILURE);
}


/**
 * get_stream - gets stream for reading from a file
 * @filename: file to be opened
 *
 */

void get_stream(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		stream_failed(filename);

	arguments->stream = fdopen(fd, "r");
	if (arguments->stream == NULL)
	{
		close(fd);
		stream_failed(filename);
	}

}

/**
 * close_stream - close the file stream
 *
 */

void close_stream(void)
{
	if (arguments->stream == NULL)
		return;

	fclose(arguments->stream);
	arguments->stream = NULL;
}
