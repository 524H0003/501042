#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.1415926535

FILE *openInputFile()
{
	FILE *inputFile = fopen("input.inp", "r");
	if (inputFile == NULL)
	{
		printf("khong mo duoc file input.inp\n");
		return NULL;
	}
	return inputFile;
}

FILE *openOutputFile()
{
	FILE *outputFile = fopen("output.out", "w");
	if (outputFile == NULL)
	{
		printf("Kh�ng mo duoc file output.out\n");
		return NULL;
	}
	return outputFile;
}

float makebc(float dc)
{
	return pow(dc, 2) * sqrt(dc);
}

float makebg(float dg)
{
	return pow(dg, 2) * PI / 3.0;
}

int isPerfectSquare(int x)
{
	int s = (int)sqrt(x);
	return (s * s == x) ? 1 : 0;
}

int isFibonacci(int n)
{
	return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

int main()
{
	FILE *inputFile = openInputFile();
	if (inputFile == NULL)
	{
		return 1;
	}

	int n, dc, dg, ld;
	char w[10];
	if (fscanf(inputFile, "%d %d %d %d %s", &n, &dc, &dg, &ld, w) != 5)
	{
		printf("Du lieu trong file input.inp kh�ng hop le\n");
		return 1;
	}

	if (n <= 0 || n > 2000 || ld < 1 || ld > 600 || (strcmp(w, "Rain") && strcmp(w, "Sun") && strcmp(w, "Cloud") && strcmp(w, "Fog") && strcmp(w, "Wind")))
	{
		FILE *outputFile = openOutputFile();
		if (outputFile != NULL)
		{
			fprintf(outputFile, "-1 -1 %d", n);
			fclose(outputFile);
		}
	}

	printf("Du lieu doc duoc la:\n");
	printf("So nep: %d\n", n);
	printf("Do dai canh banh chung: %d\n", dc);
	printf("Duong kinh banh giay: %d\n", dg);
	printf("So la dong: %d\n", ld);
	printf("Thoi tiet: %s\n", w);

	int ld_moi_bc = (dc < 8) ? 1 : 2;
	int ld_moi_bg = (dg < 5) ? 1 : 2;

	printf("So la dong can cho moi banh chung: %d\n", ld_moi_bc);
	printf("So la dong can cho moi banh giay: %d\n", ld_moi_bg);

	return 0;

	int max_bc = 0, max_bg = 0;
	float nep_con_lai = n;
	int ld_su_dung = 0;

	if (strcmp(w, "Wind") == 0)
	{
		while (nep_con_lai >= makebc(dc) && ld_su_dung + ld_moi_bc <= ld)
		{
			max_bc++;
			nep_con_lai -= makebc(dc);
			ld_su_dung += ld_moi_bc;
		}
		while (nep_con_lai >= makebg(dg) && ld_su_dung + ld_moi_bg <= ld)
		{
			max_bg++;
			nep_con_lai -= makebg(dg);
			ld_su_dung += ld_moi_bg;
		}
	}

	else if (strcmp(w, "Rain") == 0)
	{
	}

	else if (strcmp(w, "Sun") == 0)
	{
		int H = ld % 5;
		int G = dc % 6;
		int X;
		int table[5][6] = {
				{5, 7, 10, 12, 15, 20},
				{20, 5, 7, 10, 12, 15},
				{15, 20, 5, 7, 10, 12},
				{12, 15, 20, 5, 7, 10},
				{10, 12, 15, 20, 5, 7}};
		X = table[H][G];
		n = n * X / 100 + n;
		ld -= X;

		int weatherCondition = (dc + dg) % 3;
		switch (weatherCondition)
		{
		case 0:
			strcpy(w, "Rain");
			break;
		case 1:
			strcpy(w, "Wind");
			break;
		case 2:
			strcpy(w, "Cloud");
			break;
		}

		 if (strcmp(w, "Fog") == 0)
		{
			if (isFibonacci(dc) && isFibonacci(dg))
			{
				dc /= 2;
				dg /= 2;
			}
			else
			{
				dc *= 2;
				dg *= 2;
			}
		}
	}
}