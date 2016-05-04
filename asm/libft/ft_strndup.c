#include "libft.h"

char	*ft_strndup(char *str, int len)
{
	char	*rep;

	if ((rep = (char*)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	ft_strncpy(rep, str, len);
	rep[len] = '\0';
	return (rep);
}