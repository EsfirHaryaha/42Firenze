/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:16:01 by eharyaha          #+#    #+#             */
/*   Updated: 2025/11/02 22:16:08 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int		is_valid_number(char *str);
char	*read_dict_file(char *filename);
void	convert_number(char *str, char *dict, int *first);
char	*ft_strtrim(char *str);
int		insert_nbr(char *str);
int		is_valid_number(char *str);
char	*ft_strtrim(char *str);
char	**slice_str(char *str, char	*str_sliced[]);
char	*read_dict_file(char *filename);
char	*find_value(char *dict, char *key);
void	convert_number(char *num, char *dict, int *first);

int	open_dict_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	read_dict_content(int fd, char *buffer, int size)
{
	int	ret;

	ret = read(fd, buffer, size - 1);
	if (ret < 0)
		return (-1);
	buffer[ret] = '\0';
	return (ret);
}

char	*copy_dict_content(char *buffer, int len)
{
	char	*dict;
	int		i;

	dict = malloc(len + 1);
	if (!dict)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dict[i] = buffer[i];
		i++;
	}
	dict[i] = '\0';
	return (dict);
}

char	*read_dict_file(char *filename)
{
	int		fd;
	char	buffer[4096];
	int		len;
	char	*dict;

	fd = open_dict_file(filename);
	if (fd < 0)
		return (NULL);
	len = read_dict_content(fd, buffer, 4096);
	if (len < 0)
	{
		close(fd);
		return (NULL);
	}
	dict = copy_dict_content(buffer, len);
	close(fd);
	return (dict);
}
