#include "parser.h"

static void	trim_tab_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
}

void	set_list(char *filepath, t_list **value_list)
{
	int		fd;
	char	*line;

	fd = x_open(filepath);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || *line == '\n')
		{
			if (value_list == NULL)
				put_message_exit("invalit file data.");
			else
				break ;
		}
		trim_tab_line(line);
		if (line[ft_strlen(line) - 1] == '\n')
			line = free_path(line, ft_substr(line, 0, ft_strlen(line) - 1));
		ft_lstadd_back(value_list, ft_lstnew(line));
	}
	close(fd);
}
