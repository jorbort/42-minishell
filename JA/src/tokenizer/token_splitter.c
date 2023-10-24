
#include <minishell.h>

static char		*ft_pipestrdupli(char *s, int reset);
static int		ft_pipecntwrds(char const *s);
static char		**ft_pipesplipri(char **split, char *s);
//static char		**check_pipesplitter(char **split);
static	int		cntallwrds(int contl, int contw, char *s);

char	**ft_pipesplit(char const *s)
{
	char	**split;
	int		nwords;

	if (!s)
		return (NULL);
	nwords = ft_pipecntwrds(s);
	split = ft_calloc((nwords + 1), sizeof(char *));
	if (!split)
		return (NULL);
	if (nwords != 0)
	{
		if (ft_pipesplipri(split, (char *)s) == NULL)
			return (NULL);
	}
	else
		split[0] = NULL;
//	split = check_pipesplitter(split);

	printf("%i \n", nwords);
	return (split);
}

static int	ft_pipecntwrds(char const *s)
{
	int	contl;
	int	contw;

	contw = 0;
	contl = 0;
	return (cntallwrds(contl, contw, (char *)s));
}

static	int	cntallwrds(int contl, int contw, char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i] != 0)
	{
		if (ft_isaquote(s[i]) && flag == 1)
			flag = 0;
		if (!ft_isspace(s[i]) && !ft_isapipe(s[i])) 
			contl++;
		if (((ft_isspace(s[i]) || ft_isapipe(s[i])) && contl > 0) && flag == 0)
		{
			contw++;
			contl = 0;
		}
		if ((ft_isapipe(s[i]) || ft_isaquote(s[i])) && flag == 0)
			contw++;
		else if (ft_isaquote(s[i]))
			flag = 1;
		i++;
	}
	if (contl > 0)
		contw++;
	return (contw);
}

static char	**ft_pipesplipri(char **split, char *s)
{
	int		i;
	char	*reset;

	i = 0;
	while (i < ft_pipecntwrds(s))
	{
		split[i] = ft_pipestrdupli(s, 0);
		if (split[i] == NULL)
			return (ft_freesp(split));
		i++;
	}
	split[i] = NULL;
	reset = ft_pipestrdupli(s, 1);
	free (reset);
	return (split);
}

static	char	*ft_pipestrdupli(char *s, int reset)
{
	static int	i = 0;
	int			j;
	int			a;
	char		quote;
	char		*dupstr;

	if (reset == 0)
	{
		quote = 0;
		a = 0;
		while (s[i] == 32)
			i++;
		j = i;
		if (ft_isapipe(s[i]))
			i++;
		else if (ft_isaquote(s[i]))
		{
			quote = s[i];
			i++;
			while (s[i] != quote && s[i]) 
				i++;
			if (s[i] == quote)
				i++;
		}
		else
		{
			while (!ft_isspace(s[i]) && s[i] != 0 && !ft_isapipe(s[i]))
				i++;
		}
		dupstr = malloc((i - j) * sizeof(char) + 1);
		if (!dupstr)
			return (NULL);
		while (j < i)
		{
			dupstr[a] = s[j];
			j++;
			a++;
		}
		dupstr[j] = 0;
		return (dupstr);
	}
	else
	{
		i = 0;
		return (NULL);
	}
}
/*
static char		**check_pipesplitter(char **split)
{
	int i;
	int j;
	int quote;
	char *tmp;
	
	i = 0;
	while (split[i])
	{
		if ((ft_strchr(split[i], 39) || ft_strchr(split[i], 34)) && ft_strlen(split[i]) == 1) 
		{
			quote = (int)split[i][0];
			j = i + 1;
			while (split[j] && (!ft_strchr(split[j], quote)))
			{
				tmp = split[j];	
				split[i] = ft_strjoin_doublefree(split[i], split[j]);
				split[j] = tmp;				
				j++;
			}
			if (split[j] && (ft_strchr(split[j], 39) || ft_strchr(split[j], 34)))
				{
						split[i] = ft_strjoin_doublefree(split[i], split[j]);
						j++;
				}
			i++;
			while (split[j])
			{
				split[i] = split[j];
				
				i++;
				j++;
			}
			split[i] = NULL;
		}
		else
			i++;
	}
	return (split);
}
*/
