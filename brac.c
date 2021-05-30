//ckeck if input line is brackets-balansed '(' ')'
//gcc brac.c | ./a.out
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_LENGTH 1234

struct stack;
void up_head_stack (struct stack *s);
void down_head_stack (struct stack *s);
void stack_push (struct stack *s, char c);
char stack_pop (struct stack *s);
int stack_is_empty (struct stack *s);
void read_stack (struct stack *s);
void read_stack (struct stack *s);
void print_stack (struct stack *s);
int check_by_brackets (struct stack *s);


struct stack
{
	int head;
	int max;
	char *data;
};

void up_head_stack (struct stack *s)
{
	if (!s)
		{
			fprintf (stderr, "No stack!\n");
			return;
		}

	if (s->head < (s->max - 1))
		s->head++;
	else 
		fprintf (stderr, "Max stack data!\n");
}

void down_head_stack (struct stack *s)
{
	if (!s)
		{
			fprintf (stderr, "No stack!\n");
			return;
		}

	if (s->head >= 0)
		s->head--;
	else 
		fprintf (stderr, "Stack head error\n");
}

void stack_push (struct stack *s, char c)
{
	if (!s)
		{
			fprintf (stderr, "No stack!\n");
			return;
		}

	if (s->head < (s->max - 1))
		{
			s->data[s->head + 1] = c;
			up_head_stack (s);
		}
	else  
		fprintf (stderr, "Max stack data!\n");
}

char stack_pop (struct stack *s)
{
	char res = 0;
	if (!s)
		{
			fprintf (stderr, "No stack!\n");
			return 0;
		}

	if (s->head >= 0)
		{
			res = s->data[s->head];
			down_head_stack (s);
			return res;
		}
	else 
		fprintf (stderr, "Stack head error\n");

	return 0;
}

int stack_is_empty (struct stack *s)
{
	char res = 0;
	if (!s)
		{
			fprintf (stderr, "No stack!\n");
			return 0;
		}

	return (s->head < 0);
}

void read_stack (struct stack *s)
{
	char c = 0;
	int n = 0;
	int i = 0;
	char *cs = (char*) malloc (MAX_LENGTH * sizeof(char));
	memset (cs, 0, MAX_LENGTH * sizeof(char));
	if (!s)
		return;

	while (scanf ("%c", &c) == 1)
		{
			if (c != '\n' && n < (MAX_LENGTH - 1))
				{
					cs[n] = c;
					n++;
				}
			else 
				{
					cs[n + 1] = '\0';
					break;
				}
		}

	s->max = n + 1;
	s->head = -1;
	s->data = (char*) malloc ((n + 1) * sizeof(char));
	memset (s->data, 0, (n + 1) * sizeof(char));
	for (i = n; i >= 0; i--)
		stack_push (s, cs[i]);

	free (cs);
}

void print_stack (struct stack *s)
{
	int i = 0;
	if (!s)
		return;

	for (i = 0; i <= s->head; i++)
		printf ("%c", s->data[i]);
	printf ("\n");
}

int check_by_brackets (struct stack *s)
{
	char tmp = 0;
	struct stack brackets_stack;
	int res = 0;
	if (!s)
		return -1;

	brackets_stack.head = -1;
	brackets_stack.max = s->max;
	brackets_stack.data = (char*) malloc (s->max * sizeof(char));
	memset (brackets_stack.data, 0, s->max * sizeof(char));

	while (!stack_is_empty (s))
		{
			tmp = stack_pop (s);
			printf ("%c", tmp);

			if (tmp == ')')
				{
					if (stack_is_empty (&brackets_stack))
						break;

					stack_pop (&brackets_stack);
				}

			if (tmp == '(')
				{
					stack_push (&brackets_stack, tmp);
				}
		}

	if (!stack_is_empty (s) || !stack_is_empty (&brackets_stack))
		res = -1;

	free (brackets_stack.data);
	return res;
}

int main (void)
{
	struct stack S;
	printf ("Input lile:\n");

	read_stack (&S);
	
	if (!check_by_brackets (&S))
		printf (" ->True\n");
	else 
		printf (" <-False\n");

	free(S.data);
	return 0;
}
