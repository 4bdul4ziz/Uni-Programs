#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

typedef struct
{
    float matrix[4][4];
    int current_row_index;
    int current_column_index;
};

MM matricesArr[100];
int matricesArrCurrentIndex = 0;

char currentValStr[20];
int currentValStrIndex = 0;

MM currentMatrix;

void emptCV()
{
    for (int i = 0; i < 20; i++)
    {
        currentValStr[i] = '0';
    }
}

void segments()
{
    int i;
    for (i = 0; i < 20; i++)
    {
        if (currentValStr[i] == '0')
        {
            printf(" ");
        }
        else if (currentValStr[i] == '1')
        {
            printf("-");
        }
        else if (currentValStr[i] == '2')
        {
            printf("_");
        }
        else if (currentValStr[i] == '3')
        {
            printf("=");
        }
        else if (currentValStr[i] == '4')
        {
            printf("#");
        }
        else if (currentValStr[i] == '5')
        {
            printf("@");
        }
        else if (currentValStr[i] == '6')
        {
            printf("$");
        }
        else if (currentValStr[i] == '7')
        {
            printf("%");
        }
        else if (currentValStr[i] == '8')
        {
            printf("&");
        }
        else if (currentValStr[i] == '9')
        {
            printf("*");
        }
        else if (currentValStr[i] == 'A')
        {
            printf("+");
        }
        else if (currentValStr[i] == 'B')
        {
            printf("-");
        }
        else if (currentValStr[i] == 'C')
        {
            printf("=");
        }
        else if (currentValStr[i] == 'D')
        {
            printf("#");
        }
        else if (currentValStr[i] == 'E')
        {
            printf("@");
        }
        else if (currentValStr[i] == 'F')
        {
            printf("$");
        }
        else if (currentValStr[i] == 'G')
        {
            printf("%");
        }
        else if (currentValStr[i] == 'H')
        {
            printf("&");
        }
        else if (currentValStr[i] == 'I')
        {
            printf("*");
        }
        else if(current
    }

    void readMatrix()
    {

        int NEW_ROW = 1;
        int VALUE = 2;
        int SPACE = 3;
        int MATRIX_END = 4;

        int NO_OP = -1;

        int CURRENT_OP_CODE;
        int PREV_OP_CODE;

        currentMatrix.current_column_index = 0;
        currentMatrix.current_row_index = 0;

        FILE *file;
        file = fopen("matrix.txt", "r");

        char c;
        while ((c = fgetc(file)) != EOF)
        {
            if (c == ' ')
            {
                CURRENT_OP_CODE = SPACE;
            }
            else if (c == ';')
            {
                CURRENT_OP_CODE = NEW_ROW;
            }
            else if (c == ']')
            {
                CURRENT_OP_CODE = MATRIX_END;
            }
            else if (isdigit(c) == 1 || c == '.')
            {
                CURRENT_OP_CODE = VALUE;
            }

            if (CURRENT_OP_CODE == VALUE && PREV_OP_CODE == VALUE)
            {
                currentValStr[currentValStrIndex] = c;
                currentValStrIndex++;
            }
            else if (CURRENT_OP_CODE == VALUE && CURRENT_OP_CODE != PREV_OP_CODE)
            {
                currentValStrIndex = 0;
                emptCV();
                currentValStr[currentValStrIndex] = c;
                currentValStrIndex++;
            }
            if (CURRENT_OP_CODE != VALUE && PREV_OP_CODE == VALUE)
            {
                currentValStrIndex = 0;
                currentMatrix.matrix[currentMatrix.current_row_index][currentMatrix.current_column_index] = atof(currentValStr);
                currentMatrix.current_column_index++;
            }

            if (CURRENT_OP_CODE == NEW_ROW)
            {
                currentMatrix.current_column_index = 0;
                currentMatrix.current_row_index++;
            }
            if (CURRENT_OP_CODE == MATRIX_END)
            {
                matricesArr[matricesArrCurrentIndex] = currentMatrix;
                matricesArrCurrentIndex++;
                currentMatrix = (MM){
                    {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, 0, 0};
                currentMatrix.current_row_index = 0;
            }
            // at end set PREV_OP_CODE
            PREV_OP_CODE = CURRENT_OP_CODE;
            CURRENT_OP_CODE = NO_OP;
        }
    }

    void operation()
    {
        int i;
        for (i = 0; i < matricesArrCurrentIndex; i++)
        {
            int j;
            for (j = 0; j < 4; j++)
            {
                int k;
                for (k = 0; k < 4; k++)
                {
                    currentMatrix.matrix[j][k] = matricesArr[i].matrix[j][k];
                }
            }
        }
    }

    MM add(MM matrix1, MM matrix2)
    {
        MM result;
        result.current_row_index = matrix1.current_row_index;
        result.current_column_index = matrix1.current_column_index;

        for (int i = 0; i < matrix1.current_row_index; i++)
        {
            for (int j = 0; j < matrix1.current_column_index; j++)
            {
                result.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
            }
        }
        return result;
    }

    MM sub(MM matrix1, MM matrix2)
    {
        MM substractMatrix;
        for (int rowIndex = 0; rowIndex < 4; rowIndex++)
        {
            for (int columnIndex = 0; columnIndex < 4; columnIndex++)
            {
                substractMatrix.matrix[rowIndex][columnIndex] = matrix1.matrix[rowIndex][columnIndex] - matrix2.matrix[rowIndex][columnIndex];
            }
        }
        return substractMatrix;
    }

    MM mul(MM matrix1, MM matrix2)
    {
        MM productMatrix;
        for (int rowIndex = 0; rowIndex < 4; rowIndex++)
        {
            for (int columnIndex = 0; columnIndex < 4; columnIndex++)
            {
                productMatrix.matrix[rowIndex][columnIndex] = productMatrix.matrix[rowIndex][columnIndex] * productMatrix.matrix[rowIndex][columnIndex];
            }
        }
        return productMatrix;
    }

    void printMatrix(MM matrixToPrint)
    {
        for (int rowIndex = 0; rowIndex < 4; rowIndex++)
        {
            for (int columnIndex = 0; columnIndex < 4; columnIndex++)
            {
                printf("%f ", matrixToPrint.matrix[rowIndex][columnIndex]);
            }
            printf("\n");
        }
    }

    int main()
    {
        readMatrix();
        printf("\n Two Matrices\n");
        for (int l = 0; l < 2; l++)
        {
            printf("\n Matrix %d \n", l + 1);
            printMatrix(matricesArr[l]);
        }

        MM sumMatrix = add(matricesArr[0], matricesArr[1]);

        printf("\n Sum of Two Matrices\n");
        printMatrix(sumMatrix);

        MM differenceMatrix = sub(matricesArr[0], matricesArr[1]);
        printf("\n Difference of Two Matrices\n");
        printMatrix(differenceMatrix);

        MM productMatrix = mul(matricesArr[0], matricesArr[1]);
        printf("\n Product of Two Matrices\n");
        printMatrix(productMatrix);

        return 0;
    }