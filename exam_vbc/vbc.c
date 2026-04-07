#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct node{
	enum {
		ADD,
		MULTI,
		VAL,
	}	type;
	int val;
	struct node *l;
	struct node *r;
}	node;

node *new_node(int val){
	node *ret = calloc(1, sizeof(node));
	if (!ret)
		return (NULL);
	ret->val = val;
	return ret;
}

void destroy_tree(node *n){
	if (!n)	
		return ;
	if (n->type != VAL)
	{	
		destroy_tree(n->l);
		destroy_tree(n->r);
	}
	free(n);
}

void unexpected(char c){
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
}

int accept (char **s, char c){
	if (**s == c){
		(*s)++;
		return (1);
	}
	return (0);
}

int expect(char **s, char c){
	if (accept(s, c))
		return (1);
	unexpected(**s);
	return (0);
}

void tree_recursion(node **cur, char *s, int expr_side, int charges)
{
	node *new = NULL;

	if (!*s)
		return ;
	if (*s == '(')
		tree_recursion(cur, s+1, expr_side, charges + 1);
	else if (*s == ')')
		tree_recursion(cur, s+1, expr_side, charges);
	else if (*s == '+')
	{
		new = new_node(0);
		new->type = ADD;
		new->l = (*cur);
		(*cur) = new;
		tree_recursion(cur, s+1, 1, charges);
	}
	else if (*s == '*')
	{
		new = new_node(0);
		new->type = MULTI;
		if ((*cur)->type == ADD){
			new->l = (*cur)->r;
			(*cur)->r = new;
			tree_recursion(&new, s+1, 1, charges);
		}
		else{
			new->l = (*cur);
			(*cur) = new;
			tree_recursion(cur, s+1, 1, charges);
		}
	}
	else if (isdigit(*s)){
		new = new_node(*s - '0');
		new->type = VAL;
		if (*cur == NULL)
		{
			(*cur)= new;
			tree_recursion(cur, s+1, 0, charges);
		}
		else {
			if (expr_side == 0)
				(*cur)->l = new;
			else
				(*cur)->r = new;
			tree_recursion(cur, s+1, 0, charges);
		}
	}

}

node *parse_expr(char *s){
	node *ret = NULL;

	tree_recursion(&ret, s, 0, 0);
	return ret;
}

int eval_tree(node *tree){
	switch (tree->type){
		case ADD:
			return (eval_tree(tree->l) + eval_tree(tree->r));
		case MULTI:
			return (eval_tree(tree->l) * eval_tree(tree->r));
		case VAL:
			return tree->val;
	}
}

int main(int argc, char *argv[]){
	if (argc != 2)
		return 1;
	node *tree = parse_expr(argv[1]);
	if (!tree){
		printf ("here\n");
		return 1;
	}
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
	return (0);
}
