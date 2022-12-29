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
	// �� 1 2 3 4
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st); // �ȳ�4���ٳ�3����2����1
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
        else// ˵���������ţ���ȡջ����Ԫ��(��ջ)���ַ�*s�Ա�
        {
            // ���������ţ���ջ��û���ݣ�˵��ǰ���������ţ���ƥ��false
            if (StackEmpty(&st))
            {
                StackDestroy(&st);
                return false;
            }
            STDataType top = StackTop(&st);
            StackPop(&st);
            // ��ʼ�Ա�
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

    bool ret = StackEmpty(&st);// ���ջ���ǿգ�˵��ջ�л���������δ��ûƥ��
    StackDestroy(&st);
    return ret;
}
int main()
{
	//STtest1();
	STtest2();
}