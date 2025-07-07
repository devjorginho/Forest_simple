/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:20:33 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/07 13:28:36 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static char **map_add_line(char **map, int lines, char *new_line)
{
    char **new_map = malloc(sizeof(char *) * (lines + 2));
    int i = 0;

    if (!new_map)
        return NULL;
    
    while (i < lines)
    {
        new_map[i] = map[i];
        i++;
    }
    new_map[i] = new_line;
    new_map[i + 1] = NULL;
    free(map);
    return new_map;
}
int read_map(t_game *game, const char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *line;
    int line_count = 0;
    char **map = NULL;

    if (fd < 0)
        return (-1);

    while ((line = get_next_line(fd)))
    {
        map = realloc_map(map, line_count, line);
        if (!map)
            return (-1);
        line_count++;
    }
    close(fd);

    game->map = map;
    game->map_height = line_count;
    if (line_count > 0)
        game->map_width = (int)ft_strlen(game->map[0]);
    return (0);
}