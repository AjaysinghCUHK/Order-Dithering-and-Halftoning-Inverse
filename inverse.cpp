/* --------------------------------------------------------------------- */
/*	CSCI 3280, Introduction to Multimedia Systems                        */
/*	Spring 2018                                                          */
/*                                                                       */
/*	Assignment 01 Skeleton :	inverse.cpp                              */
/* --------------------------------------------------------------------- */

#include "utils.h"
#include <math.h> 

//!	NOTICE! ******** PUT ALL YOUR CODE INSIDE inverse() ********


void inverse(int n, char* file_path, char* save_path)
{
	printf("Running Halftoning Inverse.\n");
	//gaussian filter code
	double *filter = (double *)malloc(n);
	double total = 0.0;
	double sig = 5.0;
	int i;
	int j;
	for (i = -n/2; i <= n/2; i++) 
	{
		for (j = -n/2; j <= n/2; j++) 
		{
			int id = (i + n/2) + n*(j + n/2);
			filter[id] = (exp(-(j*j + i*i) / (sig*sig*2))) / (3.1416*sig*sig*2);
			total += filter[id];
		}
	}
	for (i = 0; i<n*n; i++) 
	{
		filter[i] /= total;
	}
	//dithering inverse part
	Bitmap dithered = Bitmap(file_path);
	Bitmap inversed = Bitmap(file_path);

	for (i = n/2; i<((dithered.getWidth()-n/2)); i++) 
	{
		
		for (j = n/2; j<(dithered.getHeight()-n/2); j++) 
		{
			unsigned char rgb_r;
			double sum_r = 0.0;
			unsigned char rgb_g;
			double sum_g = 0.0;
			unsigned char rgb_b;
			double sum_b = 0.0;
			int ii;
			int jj;
			for (ii = ((-n/2)); ii<=((n/2)); ii++) 
			{
				for (jj = ((-n/2)); jj <=((n/2)); jj++) 
				{
					dithered.getColor(i + ii, j + jj, rgb_r, rgb_g, rgb_b);

					int id = (ii + n/2) + n*(jj + n/2);

					sum_b += (filter[id] * rgb_b);
					sum_g += (filter[id] * rgb_g);
					sum_r += (filter[id] * rgb_r);
				}
			}

			inversed.setColor(i, j, sum_r, sum_g, sum_b);
		}
	}

	inversed.save(save_path);
}