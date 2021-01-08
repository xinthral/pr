/**
 * Program: Weather Features
 * Author: Xinthral
 * Date: 3/7/2019
 * Purpose: Convert amount of rain downfall into amount of snowfall
 * Usage:
 *	gcc ./RainToSnow.c -o downfall.exe
 *	./downfall.exe <rain|in> <temp|f>
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void huskyWeather(char* rainfall, char* temperature) {
	// Convert first argument passed to float
	double downfall;
	downfall = atof(rainfall);

	// Check if rain is positive value
	if (downfall < 0) {
		printf("Amount of rain must be non-negative!\n");
		exit(1);
	}

	double tempf;
	double outfall;
	double percent;

	tempf = atof(temperature);

	if (tempf >= 32) {
		outfall = downfall * 0;
	} else if (tempf >= 27) {
		outfall = downfall * 10;
	} else if (tempf >= 15) {
		outfall = downfall * 15;
	} else if (tempf >= 10) {
		outfall = downfall * 30;
	} else if (tempf >= 0) {
		outfall = downfall * 40;
	} else if (tempf >= -20) {
		outfall = downfall * 50;
	} else {
		outfall = downfall * 100;
	}


	percent = outfall / 108.0;

	printf("%.1f inches of rain at %.1fF would result in %.1f inches of snow.\n", ((int) (downfall * 100)) / 100.0, ((int) (tempf * 100)) / 100.0, ((int) (outfall * 100)) / 100.0);
	if (((int) (percent * 100 + 0.5)) == 100) {
		printf("This would cover all of the Husky Statue!\n");
	} else {
		printf("This would cover about %d%% of the Husky Statue!\n", ((int) (percent * 100 + 0.5)));
	}
}

float ftoc(float temp) {
	// Fahrenheit to Celsius Conversion
	return((temp - 32) * (5/9.0));
}

float ctof(float temp) {
	// Celsius to Fahrenheit Conversion
	return(temp * (9/5.0) + 32);
}

void tempCheck(char* temp, char* source, char* target) {
	// Conversion wrapper
	float temperature = atof(temp);
	float resp;

	if (*source == 'f') {
		// printf("f to c");
		resp = ftoc(temperature);
	} else if (*source == 'c') {
		// printf("c to f");
		resp = ctof(temperature);
	}
	printf("%.1f converted to %.1f", temperature, resp);

}

int main(int argc, char* argv[]) {
	// Check if enough arguments were supplied
	if (argc == 3) {
		huskyWeather(argv[1], argv[2]);
	} else if (argc == 4) {
		tempCheck(argv[1], argv[2], argv[3]);
	} else {
		printf("./downfall <rain|inches> <temp|Fahrenheit>\n");
		exit(1);

	}
	return(0);
}
