#include "parser.h"

char	*read_loop(int read_co, char *chdata, int fd, char *buffer)
{
	char	*tmp;
	dprintf(2, "start read loop!!!\n");
	while (read_co > 0)
	{
		tmp = chdata;
		read_co = read(fd, buffer, BUFFER_SIZE);
		buffer[read_co] = '\0';
		chdata = ft_strjoin(tmp, buffer);
		if (!chdata)
			return (puterror(": Fatal"), free(buffer), free(tmp), NULL);
		// new check will read until the non printable char are occur and '\0'
		// deprecate from
		// vvvvvvvv
		// if ((buffer[0] < 32 || buffer[0] > 126) \
		// 	&& buffer[0] != '\n' && read_co > 0)
		// 	read_co = 0;
		if (false == ft_isprint_mk2(buffer[0]))
			read_co = 0;
		free(tmp);
	}
	free(buffer);
	dprintf(2, "read is \n################\n%s\n##############\nreturn\n", chdata);
	if (read_co < -1)
		perror("FILE READER : ");
	
	return (chdata);
}
