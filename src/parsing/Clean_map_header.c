/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Clean_map_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 01:47:52 by macoulib          #+#    #+#             */
/*   Updated: 2025/12/30 02:08:52 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


char *trim_start_spaces(char *str)
{
    int i = 0;

    while (str[i] && ft_isspace((unsigned char)str[i]))
        i++;

    return (ft_strdup(str + i));
}

int clean_map_file_content(t_data *data)
{
    int     i;
    char    *cleaned;

    i = 0;
    while (data->map_file_content[i])
    {
        cleaned = trim_start_spaces(data->map_file_content[i]);
        if (!cleaned)
            return (0);

        free(data->map_file_content[i]);
        data->map_file_content[i] = cleaned;
        i++;
    }
    return (1);
}


int reorder_map_header(t_data *data)
{
    char    *new_header[8]; 
    int     i;
    int     j;

    j = 0;

    i = 0;
    while (data->map_header[i])
    {
        if (!ft_strncmp(data->map_header[i], "NO ", 3)
            || !ft_strncmp(data->map_header[i], "SO ", 3)
            || !ft_strncmp(data->map_header[i], "WE ", 3)
            || !ft_strncmp(data->map_header[i], "EA ", 3))
        {
            new_header[j++] = data->map_header[i];
        }
        i++;
    }

    i = 0;
    while (data->map_header[i])
    {
        if (!ft_strncmp(data->map_header[i], "F ", 2)
            || !ft_strncmp(data->map_header[i], "C ", 2))
        {
            new_header[j++] = data->map_header[i];
        }
        i++;
    }

    new_header[j] = NULL;

    i = 0;
    while (new_header[i])
    {
        data->map_header[i] = new_header[i];
        i++;
    }
    data->map_header[i] = NULL;

    return (1);
}

