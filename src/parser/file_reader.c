#include "parser.h"

char	**file_reader(int fd)
{
	char	*chdata;
	char	**map;
	char	*buffer;
	int		read_count;

	dprintf(2, "start file reader !!!\n");
	read_count = 1;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (puterror(": Fatal"), NULL);
	buffer[BUFFER_SIZE] = '\0';
	chdata = ft_calloc(sizeof(char), 1);
	if (!chdata)
		return (free(buffer), puterror(": Fatal"), NULL);
	chdata = read_loop(read_count, chdata, fd, buffer);
	// if (scanner(chdata) == 0 || !ft_strlen(chdata))
	// 	return (free(chdata), NULL);
	map = ft_split(chdata, '\n');
	free(chdata);
	return (map);
}
