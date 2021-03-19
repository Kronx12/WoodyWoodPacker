/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:16:33 by gbaud             #+#    #+#             */
/*   Updated: 2021/03/17 21:06:18 by gbaud            ###   ########lyon.fr   */
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

int file_is_elf64(char *file)
{
    int fd;
    
    fd = open(file, O_RDONLY);
    
    return (EXIT_SUCCESS);
}