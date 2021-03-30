/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:32:18 by gbaud             #+#    #+#             */
/*   Updated: 2021/03/30 01:40:09 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
#define GLOBAL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>

#define USAGE_ERROR "\e[1;31mUsage : ./woody_woodpacker {file}\n\e[0m"
#define FILETYPE_ERROR "\e[1;31mWoody_Woodpacker: path is a directory\n\e[0m"
#define FILEEXT_ERROR "\e[1;31mWoody_Woodpacker: the file does not have the ELF64 extension\n\e[0m"
#define FILEFORMAT_ERROR "\e[1;31mWoody_Woodpacker: file is not a ELF64 file\n\e[0m"
#define put_err(err) ({ printf("\e[1;31m%s (%s)\n\e[0m", err, strerror(errno)); })

#define DEBUG



/*
** +====================================================
** |                                        CHECKER.C
** +====================================================
*/

/**
 * @brief Check if file exist
 * 
 * @param file
 * @return int 
 */
int file_exist(char *file);

/**
 * @brief Check if file is directory
 * 
 * @param file
 * @return int 
 */
int file_is_not_file(char *file);

/**
 * @brief Check if file has an elf extensionß
 * 
 * @param file 
 * @return int 
 */
int file_has_correct_extension(char *file);

/**
 * @brief Check if file is elf64
 * 
 * @param file 
 * @return int 
 */
int file_is_not_elf64(char *file);



/*
** +====================================================
** |                                        UTILS.C
** +====================================================
*/

/**
 * @brief return string length
 * 
 * @param str 
 * @return int 
 */
int		ft_strlen(char *str);

/**
 * @brief compare two memory blocks
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief free allocated string array
 * 
 * @param tab 
 */
void	ft_free_strs_tab(char **tab);

/**
 * @brief return the len of the tab
 * 
 * @param tab 
 * @return int 
 */
int		ft_strs_tab_len(char **tab);

/**
 * @brief compare two strings
 * 
 * @param fi 
 * @param se 
 * @param len 
 * @return int 
 */
int	ft_strncmp(const char *fi, const char *se, size_t len);



/*
** +====================================================
** |                                        FT_SPLIT.C
** +====================================================
*/

/**
 * @brief split string by charset
 * 
 * @param str 
 * @param charset 
 * @return char** 
 */
char    **ft_split(char const *str, char charset);

#endif