/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:49:19 by macoulib          #+#    #+#             */
/*   Updated: 2025/12/28 20:39:06 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	echecouverturedufichier(t_data *data)
{
	printf("❌ echec d'ouverture du fichier \n");
	free(data);
	exit(0);
}

char	*freestats(char *staticbuffer, char *buffer)
{
	char	*temp;

	if (!buffer)
		return (staticbuffer);
	temp = ft_strjoin(staticbuffer, buffer);
	free(staticbuffer);
	return (temp);
}

void	get_map(t_data *data, char *av)
{
	int		fd;
	char	*linestock;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		echecouverturedufichier(data);
	linestock = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		linestock = freestats(linestock, line);
		if (!linestock)
		{
			free(line);
			break ;
		}
		free(line);
	}
	close(fd);
	data->map_file_content = ft_split(linestock, '\n');
	free(linestock);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !*line)
		return (0);
	while (line[i])
	{
		if (!ft_strchr("01NSEW ", line[i]))
			return (0);
		i++;
	}
	return (1);
}
int	find_map_start(t_data *data)
{
	int i;
	char *chartrim;

	if (!data->map_file_content)
		return (0);
	i = 0;
	while (data->map_file_content[i])
	{
		chartrim = ft_strtrim(data->map_file_content[i], " \t\n");
		if (!chartrim)
			return (0);

		if (*chartrim && is_map_line(chartrim))
		{
			free(chartrim);
			data->map_start = i;
			return (1);
		}
		free(chartrim);
		i++;
	}
	return (0);
}
