/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:25:31 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/17 19:51:13 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	if (n == 0)
		return (s);
	p = (unsigned char *)s;
	while (n--)
	{
		p[n] = c;
	}
	return (s);
}
