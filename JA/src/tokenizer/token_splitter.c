
#include <minishell.h>

static char		*ft_pipestrdupli(const char *s1, char cut);
static int		ft_pipecntwrds(char const *s, char c);
static char		**ft_pipesplipri(char **split, char const *s, char c);
static char		**check_pipesplitter(char **split);

char	**ft_pipesplit(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = ft_calloc((ft_pipecntwrds(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	if (ft_pipecntwrds(s, c) != 0)
	{
		if (ft_pipesplipri(split, s, c) == NULL)
			return (NULL);
	}
	else
		split[0] = NULL;
	split = check_pipesplitter(split);
	return (split);
}

static char	**ft_pipesplipri(char **split, char const *s, char c)
{
	int		i;
	int		j;
	int		words;

	words = 1;
	i = -1;
	j = 0;
	while (i++ < (int)ft_strlen(s) - 1)
	{
		if (s[i] == (unsigned char)c)
			words = 1;
		else if ((words == 1 && s[i] != (unsigned char)c) || ft_isapipe(s[i]))
		{
			split[j] = ft_pipestrdupli(&s[i], c);
			if (split[j] == NULL)
				return (ft_freesp(split));
			words = 0;
			if (ft_isapipe(s[i]))
				words = 1;
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

static int    ft_pipecntwrds(char const *s, char c)
{
    int    i;
    int    contl;
    int    contw;

    i = 0;
    contw = 0;
    contl = 0;
    while (s[i] != 0)
    {
        if (s[i] != c && (!ft_isapipe(s[i]))) 
            contl++;
        if ((s[i] == c || ft_isapipe(s[i])) && contl > 0)
        {
            contw++;
            contl = 0;
        }
        if (ft_isapipe(s[i]) && contl == 0)
          contw++;
        i++;
    }
    if (contl > 0)
        contw++;
	return (contw);
}

static    char    *ft_pipestrdupli(const char *s1, char cut)
{
    int            i;
    int            j;
    const char    *str;
    char        *dupstr;

    str = s1;
    j = 0;
    i = 0;
    if (ft_isapipe(str[i]))
		i++;
    else
    {
      while (str[i] != cut && str[i] != 0 && (!ft_isapipe(str[i])))
        i++;
    }
    dupstr = malloc(i * sizeof(char) + 1);
    if (!dupstr)
        return (NULL);
    while (j < i)
    {
        dupstr[j] = str[j];
        j++;
    }
    dupstr[j] = 0;
    return (dupstr);
}

static char		**check_pipesplitter(char **split)
{
	int i;
	int j;
	int quote;
	//int last;

	i = 0;
	quote = 0;
	while (split[i])
	{
		if ((ft_strchr(split[i], 39) || ft_strchr(split[i], 34)) && ft_strlen(split[i]) == 1) 
		{
			quote = (int)split[i][0];
			j = i + 1;
			while (split[j] && (!ft_strchr(split[j], quote)))
			{
				split[i] = ft_strjoin_doublefree(split[i], split[j]);
			j++;	
			}
			if (ft_strchr(split[j], quote))
				split[i] = ft_strjoin_free(split[i], split[j]);
			i = j;
		}
	i++;
	}
	return (split);
}

int ft_isapipe(char c)
{
	if (c == 124 || c == 60 || c == 62 || c == 34 || c == 39)
		return (1);
	else
		return (0);
}
