/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:31:41 by gbaud             #+#    #+#             */
/*   Updated: 2021/03/30 01:37:13 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

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
        else if (file_is_not_file(av[1]))
        {
            printf("%s", FILETYPE_ERROR);
            return (EXIT_FAILURE);
        }
        else if (file_has_correct_extension(av[1]))
        {
            printf("%s", FILEEXT_ERROR);
            return (EXIT_FAILURE);
        }
        else if (file_is_not_elf64(av[1]))
        {
            printf("%s", FILEFORMAT_ERROR);
            return (EXIT_FAILURE);
        }
        // Exec
        printf("File is ok !\n");
    }
    return (EXIT_SUCCESS);
}