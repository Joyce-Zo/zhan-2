#include"Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->capacity=0;
	ps->top = 0;// 或者= -1
}
void StackDestroy(ST* ps)
{
	assert(ps); // 函数末尾记得使用。否则只把数据置空，地址-空间不变
	free(ps->data);
	ps->data = NULL;
	ps->top =ps->capacity= 0;
}

void StackPush(ST* ps, STData Type x)
{
	assert(ps);
	if (ps->top == ps->capacity) // 判断是否为空
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->data, sizeof(STDataType) * (newCapacity));
		if (tmp == NULL)
		{
			printf("Realloc Failed!\n");
			exit(-1);
		}
		else
		{
			ps->data = tmp;
			ps->capacity = newCapacity;
		}
	}
	ps->data[ps->top] = x;	// 插入数据
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));  //assert(ps->top > 0);
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));  //assert(ps->top > 0);
	return ps->data[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	// 1.
	if (ps->top == 0) // 为空就返回真
	{
		return true;
	}
	else
	{
		return false;
	}

	// 2.
	return ps->top == 0; // 逻辑等于0即真，否则假
}