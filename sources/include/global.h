/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:32:18 by gbaud             #+#    #+#             */
/*   Updated: 2021/03/17 21:05:45 by gbaud            ###   ########lyon.fr   */
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
#define FILETYPE_ERROR "\e[1;31mWoody_Woodpacker: file is a directory\n\e[0m"

#define put_err(err) ({ printf("\e[1;31m%s (%s)\n\e[0m", err, strerror(errno)); })

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
int file_is_file(char *file);

/**
 * @brief Check if file is elf64
 * 
 * @param file 
 * @return int 
 */
int file_is_elf64(char *file);

#endif