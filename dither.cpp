/* --------------------------------------------------------------------- */
/*	CSCI 3280, Introduction to Multimedia Systems                        */
/*	Spring 2018                                                          */
/*                                                                       */
/*	Assignment 01 Skeleton :	dither.cpp                               */
/* --------------------------------------------------------------------- */

#include "utils.h"

//!	NOTICE! ******** PUT ALL YOUR CODE INSIDE dither() ********

void dither(int n, char* file_path, char* save_path)
{
	printf("Running Order Dithering.\n");
	//matrix code
	int j, i, u;
	int incrementer;
	incrementer = 3;
	u = 0;
	bool up = false, down = true, right = false, left = false;
	int nsq = n * n;
	int forodd, foreven;
	int mid = n / 2;
	int x, y;
	int even = 0, odd = 1;
	float matrix[99][99];

	for (i = 3; i <= n; i++)
	{

		incrementer = incrementer + 2;
	}
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			matrix[q][w] = 0;
		}
	}
	if (n % 2 == 1)
	{
		foreven = nsq - 1;
		forodd = nsq;;
		matrix[mid][mid] = 1;
		x = mid;
		y = mid;
	}
	else if (n % 2 == 0)
	{
		foreven = nsq;
		forodd = nsq - 1;
		x = mid;
		y = mid - 1;
		matrix[y][x] = 1;
	}
	for (j = 0; j < incrementer; j++)
	{

		if (down)
		{
			for (i = 0; i <= u; i++)
			{
				if ((odd<forodd) && ((y + 1)<n))
				{
					matrix[y + 1][x] = odd + 2;
					odd = odd + 2;
					y = y + 1;

				}
				else if ((even<foreven) && ((y + 1)<n))
				{
					matrix[y + 1][x] = even + 2;
					y = y + 1;
					even = even + 2;
				}

			}
			left = true;
			down = false;
			continue;
		}
		else if (left)
		{
			for (i = 0; i <= u; i++)
			{
				if ((odd<forodd) && ((x - 1) >= 0))
				{
					matrix[y][x - 1] = odd + 2;
					odd = odd + 2;
					x = x - 1;

				}
				else if ((even<foreven) && ((x - 1) >= 0))
				{
					matrix[y][x - 1] = even + 2;
					x = x - 1;
					even = even + 2;
				}

			}
			u++;
			up = true;
			left = false;
			continue;

		}
		else if (up)
		{
			for (i = 0; i <= u; i++)
			{
				if ((odd<forodd) && ((y - 1) >= 0))
				{
					matrix[y - 1][x] = odd + 2;
					odd = odd + 2;
					y = y - 1;

				}
				else if ((even<foreven) && ((y - 1) >= 0))
				{
					matrix[y - 1][x] = even + 2;
					y = y - 1;
					even = even + 2;
				}

			}

			right = true;
			up = false;
			continue;

		}
		else if (right)
		{
			for (i = 0; i <= u; i++)
			{
				if (((x + 1)<n) && (odd<forodd))
				{
					matrix[y][x + 1] = odd + 2;
					odd = odd + 2;
					x = x + 1;

				}
				else if (((x + 1)<n) && (even<foreven))
				{
					matrix[y][x + 1] = even + 2;
					x = x + 1;
					even = even + 2;
				}

			}
			u++;
			down = true;
			right = false;
			continue;

		}

	}
	//dither part
	int IX, IY;
	int JJ, KK;
	int PD;
	double gray;
	int IIDXA;
	double intgray;
	int OD = 0;
	unsigned char RGB_R;
	unsigned char RGB_G;
	unsigned char RGB_B;
	unsigned char RGB_RR;
	unsigned char RGB_GG;
	unsigned char RGB_BB;
	Bitmap sourcebit = Bitmap(file_path);
	Bitmap halftonebit = Bitmap(file_path);
	for (IY = 0; IY < sourcebit.getHeight(); IY++)
	{
		for (IX = 0; IX < sourcebit.getWidth(); IX++)
		{
			sourcebit.getColor(IX, IY, RGB_R, RGB_G, RGB_B);
			gray = (0.299 * (double)RGB_R + 0.587*(double)RGB_G + 0.144*(double)RGB_B);
			halftonebit.setColor(IX, IY, gray, gray, gray);

		}
	}
	for (IY = 0; IY <sourcebit.getHeight(); IY += n)
	{
		if ((IY + n) > sourcebit.getHeight())
		{
			int x = sourcebit.getHeight() - IY;
			IY = x;
		}
		for (IX = 0; IX < sourcebit.getWidth(); IX += n)
		{
			for (JJ = 0; JJ < n; JJ++)
			{
				for (KK = 0; KK < n; KK++)
				{
					
					halftonebit.getColor(IX + KK, IY + JJ, RGB_RR, RGB_GG, RGB_BB);
					intgray = (double)RGB_BB;
					if ((intgray / 256.0) >((matrix[KK][JJ]) / (nsq + 1)))
					{
						OD = 255;
					}
					else
					{
						OD = 0;
					}
					halftonebit.setColor(IX + KK, IY + JJ, OD, OD, OD);
				}
			}
		}
	}
	halftonebit.save(save_path);
}