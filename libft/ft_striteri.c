/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:25:38 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 16:52:29 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &(s[i]));
		i++;
	}
}
/*
#include <stdio.h>

void to_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

int main(void)
{
    printf("=== Test ft_striteri ===\n\n");

    char s[] = "hello world";
    ft_striteri(s, to_upper);
    printf("Résultat : %s\n", s);

    return 0;
}
*/
