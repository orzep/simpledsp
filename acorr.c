/******************************************************************************
* Copyright Marcin Orzepowski. All rights reserved.                           *
*                                                                             *
* Redistribution and use in source and binary forms, with or without modifi-  *
* cation, are permitted provided that the following conditions are met:       *
*   1. Redistributions of source code must retain the above copyright notice, *
*      this list of conditions and the following disclaimer.                  *
*   2. Redistributions in binary form must reproduce the above copyright      *
*      notice, this list of conditions and the following disclaimer in the    *
* documentation and/or other materials provided with the distribution.        *
*                                                                             *
* THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  *
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED   *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE      *
* DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY  *
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;*
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF    *
* THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.           *
******************************************************************************/
/**
 * @file acorr.c
 * @author Marcin Orzepowski
 * @date 19 Feb 2016
 * @brief File containing implementation of autocorrelation function ACF and example of use
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/**
* @brief Autocorrelation Function
* Calculates autocorrelation function of double dataset
* @param double * data - pointer to array of double data
* @param int length - length of data vector
**/

double *acorr(double * data, int length)
{
	// calculate buffer size
	int bufferSize = length * 4 - 2;
	// calculate auto correlation size
	int acfSize = length * 2 - 1;
	double *buffer = (double *) malloc((bufferSize) * sizeof(double));
	double *corr = (double *) malloc((acfSize) * sizeof(double));
	double sampleSum;
	memset(buffer, 0, (bufferSize) * sizeof(double));
	memset(buffer, 0, (acfSize) * sizeof(double));
	memcpy(buffer + length - 1, data, length * sizeof(double));
	for(int i = 0; i < bufferSize; i++)
		printf("%.1f  ", buffer[i]);
	printf("\n");
	for(int lag = 0; lag < 2 * length - 1; lag++)
	{
		sampleSum = 0;
		for(int sampleNumber = 0; sampleNumber < acfSize; sampleNumber ++)
		{
			sampleSum += buffer[sampleNumber + lag] * buffer[sampleNumber +  length - 1];  //buffer[length * 2 - sampleNumber - 2];
		}
		corr[lag] = sampleSum;
	}
	free(buffer);
	return corr;
}

int main()
{

	//double data[] = {1.0, 1.0, 1.0, 1.0};
	double data[] = {1.0, 2.0, 1.0, 2.0};
	
	double *result = acorr(data, 4);
	for(int i = 0; i < 7; i++)
		printf("%.1f  ", result[i]);
	printf("\n");
	char x[10];

	scanf("%s", x);
	return 0;
}
