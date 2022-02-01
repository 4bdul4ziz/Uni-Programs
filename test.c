// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int w, h, s, q;
float mat[20][20], mat2[20][20];

//getting matrix from text file
void getMatrix(char *filename)
{
   FILE *fp;
   int i, j;
   fp = fopen(filename, "r");
   if (fp == NULL)
   {
      printf("Error opening file!\n");
      exit(1);
   }
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < w; j++)
      {
         fscanf(fp, "%f", &mat[i][j]);
      }
   }
   fclose(fp);
}
//printing the matrix from input file
void printMatrix(char *filename)
{
   FILE *fp;
   int i, j;
   fp = fopen(filename, "r");
   if (fp == NULL)
   {
      printf("Error opening file!\n");
      exit(1);
   }
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < w; j++)
      {
         fscanf(fp, "%f", &mat[i][j]);
         printf("%f ", mat[i][j]);
      }
      printf("\n");
   }
   fclose(fp);
}
//matrix addition function
void add()
{
   int i, j;
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < w; j++)
      {
         mat[i][j] = mat[i][j] + mat2[i][j];
      }
   }
}
//matrix substraction function
void sub()
{
   int i, j;
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < w; j++)
      {
         mat[i][j] = mat[i][j] - mat2[i][j];
      }
   }
}
//matrix multiplication function
void mul()
{
   int i, j, k;
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < s; j++)
      {
         for (k = 0; k < q; k++)
         {
            mat[i][j] = mat[i][j] * mat2[i][j];
         }
      }
   }
}
//matrix division function
void div()
{
   int i, j, k;
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < s; j++)
      {
         for (k = 0; k < q; k++)
         {
            mat[i][j] = mat[i][j] / mat2[i][j];
         }
      }
   }
}
//matrix input from two text files

void input()
{
   int i, j;
   printf("Enter the elements of matrix 1:\n");
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < w; j++)
      {
         scanf("%f", &mat[i][j]);
      }
   }
   printf("Enter the elements of matrix 2:\n");
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < w; j++)
      {
         scanf("%f", &mat2[i][j]);
      }
   }
}
void main()
{
   getMatrix();
   printMatrix();
   getMatrix2();
   printMatrix2();
   float product[MAX][MAX];
   float product2[MAX][MAX];
   float product3[MAX][MAX];
   float product4[MAX][MAX];
   int sum = 0;
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < s; j++)
      {
         for (k = 0; k < q; k++)
         {
            sum += mat[i][k] * mat2[k][j];
         }
         product[i][j] = sum;
         sum = 0;
      }
   }
   printf("The multiplication of two matrices:\n");
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < s; j++)
      {
         printf("%d", product[i][j]);
      }
      printf("\n");
   }
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < s; j++)
      {
         sum2 += mat[i][j] + mat2[i][j];
      }
      product2[i][j] = sum2;
      sum2 = 0;
   }
   printf("the addition of two matrices is:\n");
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < s; j++)
      {
         printf("%d", product2[i][j]);
      }
      printf("\n");
   }
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < s; j++)
      {
         sum3 += mat[i][j] - mat2[i][j];
      }
      product3[i][j] = sum3;
      sum3 = 0;
   }
   printf("the substraction of two matrices is:\n");
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < s; j++)
      {
         printf("%d", product3[i][j]);
      }
      printf("\n");
   }
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < s; j++)
      {
         sum4 += mat[i][j] / mat2[i][j];
      }
      product4[i][j] = sum4;
      sum4 = 0;
   }
   printf("the divison of two matrices is:\n");
   for (i = 0; i < h; i++)
   {
      for (j = 0; j < s; j++)
      {
         printf("%d", product4[i][j]);
      }
      printf("\n");
   }
   return 0;
}
