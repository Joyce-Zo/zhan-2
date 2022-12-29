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

bool isValid(char* s) {
    ST st;
    StackInit(&st);
    while (*s)
    {
        if (*s == '('
            || *s == '['
            || *s == '{')
        {
            StackPush(&st, *s);
            s++;
        }
        else// 说明是右括号，则取栈顶的元素(出栈)与字符*s对比
        {
            // 遇到右括号，但栈里没数据，说明前面无右括号，不匹配false
            if (StackEmpty(&st))
            {
                StackDestroy(&st);
                return false;
            }
            STDataType top = StackTop(&st);
            StackPop(&st);
            // 开始对比
            if (*s == ')' && top != '('
                || *s == ']' && top != '['
                || *s == '}' && top != '{')
            {
                StackDestroy(&st);
                return false;
            }
            else
            {
                s++;
            }
        }
    }

    bool ret = StackEmpty(&st);// 如果栈不是空，说明栈中还有左括号未出没匹配
    StackDestroy(&st);
    return ret;
}
int main()
{
	//STtest1();
	STtest2();
}