#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node {
	struct s_node	P;
	struct s_node	L;
	struct s_node	R;
	int				num;
	int				rb;
}	t_node;

typedef struct	s_rbtree {
	struct s_rbtree	root;
	int				size;
}	t_rbtree;

t_node	*new_node(int num)
{
	t_node	new;

	new.P = NULL;
	new.L = NULL;
	new.R = NULL;
	new.num = num;
	new.rb = 1;

	return &new;
}

void	add(t_rbtree rb, int num)
{
	t_node	*n = rb.root;
	t_node	*new = new_node(num);

	if (!n)
	{
		new->rb = 0;
		rb.root = new;
		return ;
	}
	while (n)
	{
		if (n->num < num)
		{
			if (n->L)
				n = n->L;
			else
			{
				n->L = new;
				break ;
			}
		}
		else
		{
			if (n->R)
				n = n->R;
			else
			{
				n->R = new;
				break ;
			}
		}
	}
	new->P = n;
	
	double_red(rb, new);

	rb.size++;
}

void	resetuct(t_rbtree rb, t_node *N, t_node *U)
{
	t_node	*G;
	t_node	*P;

	P = N->P;
	G = P->P;
	if (G->num < P->num)
	{
		if (P->num < N->num)
	}
}

void	recolor(r_rbtree rb, t_node *N, t_node *U)
{
	t_node	*P;
	t_node	*G;

	P = N->P;
	G = P->P;
	if (rb.root != G)
		G->rb = 1;
	U->rb = 0;
	U->rb = 0;
}

void	double_red(t_rbtree rb, t_node *n)
{
	t_node	*U;

	while (n->P->rb == 1 && n->rb == 1)
	{
		if (n->P->num < n->P->P->num)
			U = n->P->R;
		else
			U = n->P->L;
		if (U && U->rb)
			recolor(rb, n, U);
		else
			restruct(rb, n, U);
		n = n->P;
	}
}

int main()
{
	t_rbtree	rb;

	rb.root = NULL;
	rb.size = 0;

	add(rb, 1);
	add(rb, 2);
	add(rb, 3);
	add(rb, 4);
}
