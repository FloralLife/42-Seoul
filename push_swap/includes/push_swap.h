/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:31:22 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 17:28:55 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	int				sort;
	int				is_sort;
}	t_node;

typedef struct s_list
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}	t_list;

typedef struct s_cmdnode
{
	struct s_cmdnode	*prev;
	struct s_cmdnode	*next;
	char				*cmd;
}	t_cmdnode;

typedef struct s_cmdlist
{
	t_cmdnode	*head;
	t_cmdnode	*tail;
}	t_cmdlist;

typedef struct s_stack
{
	t_list		*a;
	t_list		*b;
	t_cmdlist	*cmdlist;
	int			sorted;
	int			list_size;
}	t_stack;

void		parse_to_stack(t_stack *data, int size, char **input);

int			is_ordered(t_list *list);
int			is_ordered_reverse(t_list *list);
void		sort(t_stack *data);
int			sort_a_2(t_stack *data);
void		sort_a_3(t_stack *data);
void		sort_a_head_to_tail(t_stack *data);
void		sort_a_5(t_stack *data);
void		sort_ab(t_stack *data);
int			sort_b_2(t_stack *data);
void		sort_b_3(t_stack *data);
void		sort_b_3_desc(t_stack *data);
void		sort_b_small3(t_stack *data);
void		sort_b_5(t_stack *data);
void		exec_cmd(t_stack *data, char *cmd);

int			swap_stack(t_list *list);
int			rrotate_stack(t_list *list);
int			rotate_stack(t_list *list);
int			push_stack(t_list *list_to, t_list *list_from);

void		ft_putstr(char *str);
void		ft_puterror(char *str);
void		error(t_stack *data);
void		free_stack(t_stack *data);
void		free_input(char **str);
int			is_integer(char *str);
int			is_unique(int *arr, int size);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			ft_strcmp(const char *s1, const char *s2);

t_node		*new_node(int value, int sort);
void		listadd_front(t_list *list, t_node *new);
void		listadd_back(t_list *list, t_node *new);
t_cmdnode	*new_cmdnode(char *cmd);
void		cmdlistadd_back(t_cmdlist *list, t_cmdnode *new);
void		cmdlistadd_front(t_cmdlist *list, t_cmdnode *new);
void		cmdlistdlt_back(t_cmdlist *list);

#endif
