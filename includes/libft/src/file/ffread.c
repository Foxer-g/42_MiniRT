/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:24:15 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_file.h"

// @doc ft_ffread
// @kind func
// @desc Small wrapper around read, relic of when I tried to implement fread.
// @param file: [[t_ffile]], The file to read from.
// @param buf: void *, The buffer to read into.
// @param nbyte: intmax_t, Number of bytes to read.
// @returns intmax_t
intmax_t	ft_ffread(t_ffile file, void *buf, intmax_t nbyte)
{
	intmax_t	result;

	if (nbyte < 0)
		return (-1);
	result = read(file, buf, nbyte);
	return (result);
}

// @doc ft_ffreadall
// @kind func
// @desc Reads an entire file.
// @param file: [[t_ffile]], The file to read.
// @param buf: void **, A pointer to a char *, the char * will be set.
// @returns intmax_t, Number of bytes read.
intmax_t	ft_ffreadall(t_ffile file, void **buf)
{
	char	*lines;
	char	*line;

	lines = NULL;
	line = get_next_line(file);
	while (line)
	{
		lines = ft_extend(lines, line);
		line = get_next_line(file);
	}
	*buf = lines;
	return (ft_strlen(lines));
}
