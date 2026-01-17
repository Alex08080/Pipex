/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:32:13 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 16:53:15 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <unistd.h>

int main(void)
{
    write(1, "=== Test ft_putchar_fd ===\n\n", 29);

    ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);
    ft_putchar_fd('Z', 1);
    ft_putchar_fd('\n', 1);

    return 0;
}
*/
