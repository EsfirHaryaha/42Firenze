/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:20:49 by lgreco            #+#    #+#             */
/*   Updated: 2025/11/02 19:07:22 by lgreco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char *read_dict_file(char *buffer, int size)
{
    char *filename = "numbers.dict";
    int fd = open(filename, O_RDONLY);
    
    if (fd == -1) {
        write(1, "Error opening file\n", 19);
        return NULL;
    }

    ssize_t bytes_read = read(fd, buffer, size - 1);
    if (bytes_read == -1) {
        write(1, "Error reading file\n", 19);
        close(fd);
        return NULL;
    }

    buffer[bytes_read] = '\0';
    close(fd);
    return buffer;
}   
/*char	*read_dict_file(char *buffer)
{
	char	*filename;
	int	fd;

	filename = "numbers.dict";
	fd = open(filename, O_RDONLY);
	read(fd, buffer, sizeof(buffer));
	return (buffer);
}*/

/*int    *lenght_dict_file(char *file)
{       
        int     fd;
        int     buffer[1024];
        int     bytesRead;

        fd = open(file, O_RDONLY);
        bytesRead = read(fd, buffer, sizeof(buffer));
        return (bytesRead);
}*/


/*typedef struct{
	char key[];
	char value[];
} Dict;*/




