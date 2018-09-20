#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 100);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 100);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 80);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 100);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 100);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 100);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 100);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 100);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 100);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 100);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 100);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 10);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 10);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 10);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
	tankPush(tank, 10);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);


//	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
//	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
//	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
//	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
//	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
//	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
//	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n]->sum, tank->stacks[tank->n]->elem->energy, tank->n);
//	printf("asdasdasdSum: %d Energy: %d Stack: %d\n", 1, tankPop(tank), tank->n);
//	printf("asdSum: %d Energy: %d Stack: %d\n", 1, tankPop(tank), tank->n);
	return (0);
}



// Function used for the test
// Don't go further :)
