/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:31:41 by gbaud             #+#    #+#             */
/*   Updated: 2021/03/17 20:15:14 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int file_exist(char *file)
{
    int fd;
    
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (EXIT_FAILURE);
    close(fd);
    return (EXIT_SUCCESS);
}

int file_is_file(char *file)
{
    struct stat path_stat;

    stat(file, &path_stat);
    return (!S_ISREG(path_stat.st_mode));
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("%s", USAGE_ERROR);
        return (EXIT_FAILURE);
    }
    else
    {
        if (file_exist(av[1]))
        {
            put_err("File open error");
            return (EXIT_FAILURE);
        }
        else if (file_is_file(av[1]))
        {
            printf("%s", FILETYPE_ERROR);
            return (EXIT_FAILURE);
        }
        
        // Check file elf64
        // Exec
    }
    return (EXIT_SUCCESS);
}