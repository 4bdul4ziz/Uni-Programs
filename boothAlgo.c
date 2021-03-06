#include <stdio.h>
#include <math.h>
void shiftleft(int A[], int Q[]);
void twocomp(int A[], int Ad, int p);
void restoring();
void nonrestoring();
void main()
{
	restoring();
	nonrestoring();
}
void restoring()
{
	int divid = 110, divisor = 10, Q[100], M[100], count = 8, i, A[] = {0, 0, 0, 0, 0, 0, 0, 0}, Ad = 0, Md = 0, p = 0, Qd = 0, it = 1;
	Q[0] = Q[1] = Q[2] = Q[3] = Q[4] = Q[5] = Q[6] = Q[7] = 0;
	for (i = 7; divid > 0 && i >= 0; i--)
	{
		Q[i] = divid % 2;
		divid = divid / 2;
	}
	Q[0] = 0;
	while (count > 0)
	{
		printf("\nIteration=%d", it);
		printf("\nState:Left Shift");
		shiftleft(A, Q);
		printf("\nA=");
		for (i = 0; i < 8; i++)
			printf("%d\t", A[i]);
		printf("\nQ=");
		for (i = 0; i < 8; i++)
			printf("%d\t", Q[i]);
		Ad = 0;
		p = 0;
		for (i = 7; i >= 0; i--)
		{
			Ad = Ad + (A[i] * pow(2, p));
			p++;
		}
		p = 0;
		Ad = Ad - divisor;
		printf("\nState:A=A-M");
		if (Ad > 0)
		{
			A[0] = A[1] = A[2] = A[3] = A[4] = A[5] = A[6] = A[7] = 0;
			for (i = 7; Ad > 0 && i >= 0; i--)
			{
				A[i] = Ad % 2;
				Ad = Ad / 2;
			}
			printf("\nA=");
			for (i = 0; i < 8; i++)
				printf("%d\t", A[i]);
			Ad = Md = 0;
		}
		else
		{
			twocomp(A, Ad, p);
			printf("\nA=");
			for (i = 0; i < 8; i++)
			{
				printf("%d\t", A[i]);
			}
			Md = 0;
		}
		if (A[0] == 0)
			Q[7] = 1;
		else
		{
			Q[7] = 0;
			p = 0;
			Ad = 0;
			printf("\nState:A=A+M when A is negative");
			for (i = 7; i >= 0; i--)
			{
				Ad = Ad + (A[i] * pow(2, p));
				p++;
			}
			Ad = Ad + divisor;
			A[0] = A[1] = A[2] = A[3] = A[4] = A[5] = A[6] = A[7] = 0;
			for (i = 7; Ad > 0 && i >= 0; i--)
			{
				A[i] = Ad % 2;
				Ad = Ad / 2;
			}
			printf("\nA=");
			for (i = 0; i < 8; i++)
			{
				printf("%d\t", A[i]);
			}
		}
		count = count - 1;
		it++;
	}
	Ad = 0;
	p = 0;
	for (i = 7; i >= 0; i--)
	{
		Ad = Ad + (A[i] * pow(2, p));
		p++;
	}
	p = 0;
	Qd = 0;
	for (i = 7; i >= 0; i--)
	{
		Qd = Qd + (Q[i] * pow(2, p));
		p++;
	}
	printf("\n----------Restoring division----------");
	printf("\nQuotient=%d", Qd);
	printf("\nRemainder=%d", Ad);
}
void nonrestoring()
{
	int divid = 110, divisor = 10, Q[100], M[100], count = 8, i, A[] = {0, 0, 0, 0, 0, 0, 0, 0}, Ad = 0, Md = 0, p = 0, Qd = 0, it = 1;
	Q[0] = Q[1] = Q[2] = Q[3] = Q[4] = Q[5] = Q[6] = Q[7] = 0;
	for (i = 7; divid > 0 && i >= 0; i--)
	{
		Q[i] = divid % 2;
		divid = divid / 2;
	}
	Q[0] = 0;
	while (count > 0)
	{
		printf("\n\nIteration%d", it);
		if (A[0] == 0)
		{
			printf("\nState:A>0");
			shiftleft(A, Q);
			printf("\nLeft Shifting of A=");
			for (i = 0; i < 8; i++)
				printf("%d\t", A[i]);
			printf("\nLeft shifting of Q=");
			for (i = 0; i < 7; i++)
				printf("%d\t", Q[i]);
			for (i = 7; i >= 0; i--)
			{
				Ad = Ad + (A[i] * pow(2, p));
				p++;
			}
			p = 0;
			Ad = Ad - divisor;
			printf("\nState:A=A-M");
			if (Ad > 0)
			{
				A[0] = A[1] = A[2] = A[3] = A[4] = A[5] = A[6] = A[7] = 0;
				for (i = 7; Ad > 0 && i >= 0; i--)
				{
					A[i] = Ad % 2;
					Ad = Ad / 2;
				}
				printf("\nA=");
				for (i = 0; i < 8; i++)
				{
					printf("%d\t", A[i]);
				}
				Ad = Md = 0;
			}
			else
			{
				twocomp(A, Ad, p);
				printf("\nA=");
				for (i = 0; i < 8; i++)
				{
					printf("%d\t", A[i]);
				}
				Md = 0;
			}
		}
		else
		{
			printf("\nState:A<0");
			shiftleft(A, Q);
			printf("\nLeft Shifting of A=");
			for (i = 0; i < 8; i++)
				printf("%d\t", A[i]);
			printf("\nLeft shifting of Q=");
			for (i = 0; i < 7; i++)
				printf("%d\t", Q[i]);
			p = 0, Ad = 0;
			for (i = 7; i >= 0; i--)
			{
				Ad = Ad + (A[i] * pow(2, p));
				p++;
			}
			Md = 0;
			p = 0;
			Ad = Ad + divisor;
			printf("\nState:A=A+M");
			A[0] = A[1] = A[2] = A[3] = A[4] = A[5] = A[6] = A[7] = 0;
			for (i = 7; Ad > 0 && i >= 0; i--)
			{
				A[i] = Ad % 2;
				Ad = Ad / 2;
			}
			printf("\nA=");
			for (i = 0; i < 8; i++)
			{
				printf("%d\t", A[i]);
			}
			Ad = Md = 0;
		}
		if (A[0] == 0)
		{
			printf("\nLSB of Q when A>0");
			Q[7] = 1;
			printf("\nQ=");
			for (i = 0; i < 8; i++)
			{
				printf("%d\t", Q[i]);
			}
		}
		else
		{
			printf("\nLSB of Q when A<0");
			Q[7] = 0;
			printf("\nQ=");
			for (i = 0; i < 8; i++)
			{
				printf("%d\t", Q[i]);
			}
		}
		count = count - 1;
		it++;
	}
	if (count == 0)
	{
		if (A[0] == 1)
		{
			printf("\nState:A<0");
			for (i = 7; i >= 0; i--)
			{
				Ad = Ad + (A[i] * pow(2, p));
				p++;
			}
			p = 0;
			p = 0;
			Ad = Ad + divisor;
			printf("\nState:A=A+M");
			A[0] = A[1] = A[2] = A[3] = A[4] = A[5] = A[6] = A[7] = 0;
			for (i = 7; Ad > 0 && i >= 0; i++)
			{
				A[i] = Ad % 2;
				Ad = Ad / 2;
			}
			printf("\nA=");
			for (i = 0; i < 8; i++)
			{
				printf("%d\t", A[i]);
			}
			Ad = 0;
		}
		Ad = 0;
		p = 0;
		for (i = 7; i >= 0; i--)
		{
			Ad = Ad + (A[i] * pow(2, p));
			p++;
		}
		p = 0;
		Qd = 0;
		for (i = 7; i >= 0; i--)
		{
			Qd = Qd + (Q[i] * pow(2, p));
			p++;
		}
		printf("\n----------Non-Restoring division----------");
		printf("\nQuotient=%d", Qd);
		printf("\nRemainder=%d", Ad);
	}
}
void shiftleft(int A[], int Q[])
{
	int i;
	for (i = 0; i < 7; i++)
	{
		A[i] = A[i + 1];
	}
	A[7] = Q[0];
	for (i = 0; i < 7; i++)
	{
		Q[i] = Q[i + 1];
	}
}
void twocomp(int A[], int Ad, int p)
{
	int i;
	Ad = Ad + ((-Ad) * 2);
	A[0] = A[1] = A[2] = A[3] = A[4] = A[5] = A[6] = A[7] = 0;
	for (i = 7; Ad > 0 && i >= 0; i--)
	{
		A[i] = Ad % 2;
		Ad = Ad / 2;
	}
	for (i = 0; i < 8; i++)
	{
		if (A[i] == 1)
			A[i] = 0;
		else
			A[i] = 1;
	}
	Ad = 0;
	p = 0;
	for (i = 7; i >= 0; i--)
	{
		Ad = Ad + (A[i] * pow(2, p));
		p++;
	}
	Ad = Ad + 1;
	A[0] = A[1] = A[2] = A[3] = A[4] = A[5] = A[6] = A[7] = 0;
	for (i = 7; Ad > 0 && i >= 0; i--)
	{
		A[i] = Ad % 2;
		Ad = Ad / 2;
	}
	Ad = 0;
}