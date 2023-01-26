/*

Author: Bj�rn Metzger
Initials: BM
Date: 26.01.2023


This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.
If not, see <https://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// initilizing all funktions for the calculation of pi
double generateRandNum();
double generatePi();
int getSamplePoints();

int main() {
    //calulating pi
    /*print the value of pi after,
    we calulate it by calling the generatePi funktion,
    wich inturen accepts a integer value for the amounts of sample points,
    |wich are obtained by calling getSamplepoints funktion*/
    printf("The calculated PI = %g", generatePi(getSamplePoints()));

    return(0);
}
int getSamplePoints() {
    // get a user input that determins with how many sample point he wants to calculate pi
    int samplePoints = 0; //initializing a integer with the value 0

    printf("Sample Points: "); //print the promt of how many sample points top the screeen
    scanf_s("%d", &samplePoints); // grab the user input as a integer
    return samplePoints;// return the amount aof sample points as a integer
}
double generatePi(int samplePoints) {
    /*generate genertate pi with a set ammount of sample points inported into the funktion viwa the int samplePoints*/
    srand(time(NULL));// set a randome seed for the rand() funtion. otherwise we willl have the same values over and over
    //gnenerate all variables that can be defined as variables
    double samplePointsInCircle = 0;//
    double posXPoint = 0;//x-coordinat of the point within the 0-1 matrix initalised with valu 0
    double posYPoint = 0;//y-coordinat of the point within the 0-1 matrix initalised with valu 0
    double areaBetween_OP = 0;//the area the point (defined by X and Y coordinats spans an area form the koordinate origen
    double pi = 0;//initaialising a pi variable as a double with the value 0
    //create a for loop that repeats for the set amount of to be created sample points
    for (int i = 0; i < samplePoints; ++i) {
        //generating the randome axis components for the sample point
        posXPoint = generateRandNum();//seting the value generated by the generateRandNum funktion to the x value
        posYPoint = generateRandNum();//seting the value generated by the generateRandNum funktion to the y value
        // calculating the square area that spans from the Coordinate origen
        areaBetween_OP = (posXPoint * posXPoint) + (posYPoint * posYPoint);//the formular is X^2 + Y^2
        // controll if the area is smaller than 1 unit 
        if (areaBetween_OP <= 1) {
            samplePointsInCircle++;// if it is smaller than 1 unit we count up the smaple points within the circle by one
        };
    }
    //calculating pi by deviding the number of sample points within the cicle and the number of total sample point after doing so we multiply the value by 4 to have a full unit circle as till now we only calculated a quarter to reduce the necesary amount of sample points
    pi = samplePointsInCircle / samplePoints * 4;

    return pi;//returning the value pi as a double
}
double generateRandNum() {
    /*generate a sample Number between 0 and 1*/
    double randNum; // define randNum
    randNum = (double)rand() / RAND_MAX; // make shure that the compiler notices it as a floting point devision with (double)

    return randNum; //return the randome number between 0 and 1
}