#include "../../includes/cub3d.h"

int  is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

int  skip_spaces(char *s, int i)
{
    while (s[i] && is_space(s[i]))
        i++;
    return (i);
}

int  parse_int_0_255(char *s, int *i, int *out)
{
    int val;

    *i = skip_spaces(s, *i);
    if (!s[*i] || !ft_isdigit(s[*i]))
        return (0);
    val = 0;
    while (s[*i] && ft_isdigit(s[*i]))
    {
        val = val * 10 + (s[*i] - '0');
        (*i)++;
        if (val > 255)
            return (0);
    }
    *out = val;
    return (1);
}

int  parse_color_values(char *s, int *color)
{
    int i;
    int r;
    int g;
    int b;

    i = 0;
    if (!parse_int_0_255(s, &i, &r))
        return (0);
    i = skip_spaces(s, i);
    if (s[i] != ',')
        return (0);
    i++;
    if (!parse_int_0_255(s, &i, &g))
        return (0);
    i = skip_spaces(s, i);
    if (s[i] != ',')
        return (0);
    i++;
    if (!parse_int_0_255(s, &i, &b))
        return (0);
    i = skip_spaces(s, i);
    if (s[i] && s[i] != '\n')
        return (0);
    *color = (r << 16) | (g << 8) | b;
    return (1);
}

int  parse_color_line(char *line, int *dst)
{
    int i;

    if (!line || !line[0] || !line[1])
        return (0);
    if (line[0] != 'F' && line[0] != 'C')
        return (0);
    if (line[1] != ' ' && line[1] != '\t')
        return (0);
    i = 2;
    i = skip_spaces(line, i);
    return (parse_color_values(&line[i], dst));
}

int color_ceiling_floor(t_data *data)
{
    int i;

    i = 0;
    while (data->map_header[i])
    {
        if (data->map_header[i][0] == 'F')
        {
            if (!parse_color_line(data->map_header[i], &data->color_floor))
                return (0);
        }
        else if (data->map_header[i][0] == 'C')
        {
            if (!parse_color_line(data->map_header[i], &data->color_cielling))
                return (0);
        }
        i++;
    }
    if (data->color_floor == -1 || data->color_cielling == -1)
        return (0);
    return (1);
}
