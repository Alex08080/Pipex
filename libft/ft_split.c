/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:03:40 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/11 16:46:44 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	size_t	i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			cpt++;
		else
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			if (s[i] != c && s[i - 1] == c && s[i] != '\0')
				cpt++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (cpt);
}

char	*ft_word(char const *s, int *i, char c)
{
	char	*str;
	int		j;
	int		a;

	a = 0;
	while (s[*i] == c && s[*i] != '\0')
		*i = *i + 1;
	j = *i;
	while (s[*i] != c && s[*i] != '\0')
		*i = *i + 1;
	str = malloc(sizeof(char) * (*i - j + 1));
	if (!str)
		return (NULL);
	while (j + a != *i)
	{
		str[a] = s[j + a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		cpt;
	int		i;

	cpt = -1;
	i = 0;
	if (!s)
		return (NULL);
	split = malloc (sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	while (++cpt < ft_count_words(s, c))
	{
		split[cpt] = ft_word(s, &i, c);
		if (!split[cpt])
		{
			while (--cpt >= 0)
				free(split[cpt]);
			free(split);
			return (NULL);
		}
	}
	split[cpt] = (NULL);
	return (split);
}
/*
#include <stdio.h>

int main(void)
{
    printf("=== Test ft_split ===\n\n");

    char **tab = ft_split("Hello World 42 Network", ' ');
    for (int i = 0; tab[i]; i++)
    {
        printf("[%d] = \"%s\"\n", i, tab[i]);
        free(tab[i]);
    }
    free(tab);

    printf("\nTest avec séparateur 'x' sur \"xxxx42xxxParisx\":\n");
    tab = ft_split("xxxx42xxxParisx", 'x');
    for (int i = 0; tab[i]; i++)
    {
        printf("[%d] = \"%s\"\n", i, tab[i]);
        free(tab[i]);
    }
    free(tab);

    return 0;
}
*/
