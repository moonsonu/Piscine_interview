#include "header.h"

#include <stdio.h>

void	reverseWords(struct s_node *lst)
{
	if (lst->next != NULL)
	{
		reverseWords(lst->next);
		putchar(' ');
	}
	printf("%s", lst->word);
	return ;
}

void	printReverse(struct s_node *lst)
{
	reverseWords(lst);
	putchar('\n');
	return ;
}
