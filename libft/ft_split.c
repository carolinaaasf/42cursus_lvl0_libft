/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:51:28 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/08 20:09:21 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_words(char const *s, char c)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
			n++;
		else if (s[i] == c && i != ft_strlen(s) - (size_t)1)
		{
			if (s[i + 1] != c)
				n++;
		}
		i++;
	}
	return (n);
}

static void	ft_str_word_create(const char *s, char **str, char c)
{
	size_t	i;
	size_t	len;
	size_t	j;

	i = 0;
	len = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		else
		{
			if (len != 0)
			{
				str[j] = (char *)malloc(sizeof(char) * len + (size_t)1);
				len = 0;
				j++;
			}
		}
		if (len != 0)
			str[j] = (char *)malloc(sizeof(char) * len + (size_t)1);
		i++;
	}
}

static void	ft_str_word_fill(const char *s, char **str, char c, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (n > 0 && s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c)
		{
			str[j][k] = s[i];
			i++;
			k++;
		}
		str[j][k] = '\0';
		k = 0;
		j++;
		n--;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**str;

	if (!s)
		return (0);
	n = ft_n_words(s, c);
	str = (char **)malloc(n * sizeof(char *) + 1);
	if (str == NULL)
		return (NULL);
	ft_str_word_create(s, str, c);
	ft_str_word_fill(s, str, c, n);
	str[n] = 0;
	return (str);
}

/*int	main(void)
{
	char	str[] = "      split       this for   me  !       "; 
	//"\0aa\0bbb"; //"123//ab:cd/ef/4g 6/H%$";
	char	**matrix;
	int		i = 0;

	matrix = ft_split(str, ' ');
	while (matrix[i] != 0)
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	return (0);
}*/
