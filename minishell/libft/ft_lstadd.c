#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new)
{
	if (*alst != NULL && new != NULL)
	{	
		new->next = *alst;
		*alst = new;
	}
	else if (*alst == NULL)
	{
		*alst = new;
		new->next = NULL;
	}
	return ;

}