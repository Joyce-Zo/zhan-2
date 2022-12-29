#include"Stack.h"


void STtest1()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	
	//printf("%d ", StackPop(&st));
	StackDestroy(&st); 
}

void STtest2()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	// 入 1 2 3 4
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st); // 先出4，再出3，出2，出1
	}

	StackDestroy(&st);
}
int main()
{
	//STtest1();
	STtest2();
}