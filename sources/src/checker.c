/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:16:33 by gbaud             #+#    #+#             */
/*   Updated: 2021/03/30 01:45:48 by gbaud            ###   ########lyon.fr   */
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

int file_is_not_file(char *file)
{
    struct stat path_stat;

    stat(file, &path_stat);
    return (!S_ISREG(path_stat.st_mode));
}

int file_has_correct_extension(char *file)
{
    int len;
    char **splitted_path;

    splitted_path = ft_split(file, '.');
    if (splitted_path == NULL)
        return (1);
    if (ft_strs_tab_len(splitted_path) == 1)
        return (0);
    len = ft_strs_tab_len(splitted_path) - 1;
    if (!ft_strncmp(splitted_path[len], "", 1)      ||
        !ft_strncmp(splitted_path[len], "o", 2)     ||
        !ft_strncmp(splitted_path[len], "so", 3)    ||
        !ft_strncmp(splitted_path[len], "axf", 4)   ||
        !ft_strncmp(splitted_path[len], "bin", 4)   ||
        !ft_strncmp(splitted_path[len], "elf", 4)   ||
        !ft_strncmp(splitted_path[len], "prx", 4)   ||
        !ft_strncmp(splitted_path[len], "exe", 4))
        return (0);
        
#ifdef DEBUG
    printf("incorrect_extension=[%s]\n", splitted_path[len]);
#endif

    return (1);
}

int file_is_not_elf64(char *file)
{
    int fd;
    int ret;
    char buff[4];
    char version;
    char ref[] = {0x7F, 0x45, 0x4C, 0x46};
    
    fd = open(file, O_RDONLY);
    read(fd, buff, 4);
    read(fd, &version, 1);
    close(fd);
    
#ifdef DEBUG
    printf("signature=[%X %X %X %X (%d)]\n", buff[0], buff[1], buff[2], buff[3], version);
#endif



    return (memcmp(ref, buff, 4));
}