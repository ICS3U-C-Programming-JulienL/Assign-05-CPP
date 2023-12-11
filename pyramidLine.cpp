// Copyright (c) 2023 Julien Lamoureux All rights reserved.

// Created By: Julien Lamoureux
// Date: December 6, 2023
// This program display an equation of a line or the volume of a square pyramid

#include <iostream>
#include <cmath>
#include <iomanip>

float calc_slope(float x1, float x2, float y1, float y2) {
    // return (y2-y1)/(x2-x1)
    return (y2-y1)/(x2-x1);
}


float calc_y_int(float x1, float y1, float slope) {
    // return y1-(slope*x1)
    return y1-(slope*x1);
}


void main_equation_of_a_line() {
    // declare variables
    std::string xPoint1Str, xPoint2Str, yPoint1Str, yPoint2Str;
    float xPoint1Float, xPoint2Float, yPoint1Float, yPoint2Float, slope, yInt;

    // get all the x and y points
    std::cout << "This program shows";
    std::cout << "the equation of a line using 2 points on a graph."
    << std::endl;
    std::cout << "Enter your first x point.";
    std::cin >> xPoint1Str;
    std::cout << "Enter your first y point.";
    std::cin >> yPoint1Str;
    std::cout << "Enter your second x point.";
    std::cin >> xPoint2Str;
    std::cout << "Enter your second y point.";
    std::cin >> yPoint2Str;

    try {
        // convert x1 to a float
        xPoint1Float = std::stof(xPoint1Str);

        try {
            // convert x2 to a float
            xPoint2Float = std::stof(xPoint2Str);

            try {
                // convert y1 to a float
                yPoint1Float = std::stof(yPoint1Str);

                try {
                    // convert y2 to a float
                    yPoint2Float = std::stof(yPoint2Str);

                    // call the calc_slope function
                    slope = calc_slope(xPoint1Float, xPoint2Float,
                    yPoint1Float, yPoint2Float);

                    // call the calc_y_int function
                    yInt = calc_y_int(xPoint1Float, yPoint1Float, slope);

                    // if yInt < 0, show -yInt
                    if (yInt < 0) {
                        std::cout << "The equation of your line is y = "
                        << slope << "x " << yInt << std::endl;
                    } else if (yInt > 0) {
                        // if yInt < 0, show +yInt
                        std::cout << "The equation of your line is y = "
                        << slope << "x+" << yInt << std::endl;
                    } else if (yInt == 0) {
                        // if yInt < 0, show no yInt
                        std::cout << "The equation of your line is y = "
                        << slope << "x" << std::endl;
                    }
                } catch (std::invalid_argument) {
                    // if y2 cannot become a float, tell the user to enter one
                    std::cout << yPoint2Str
                    << " is not a valid floating decimal number,";
                    std::cout << " number, please enter one."
                    << std::endl;
                }
            } catch (std::invalid_argument) {
                // if y1 cannot become a float, tell the user to enter one
                std::cout << yPoint1Str
                << " is not a valid floating decimal number,";
                std::cout << " number, please enter one."
                << std::endl;
            }
        } catch (std::invalid_argument) {
            // if x2 cannot become a float, tell the user to enter one
            std::cout << xPoint2Str
            << " is not a valid floating decimal number,";
            std::cout << " number, please enter one."
            << std::endl;
        }
    } catch (std::invalid_argument) {
        // if x1 cannot become a float, tell the user to enter one
        std::cout << xPoint2Str
        << " is not a valid floating decimal number,";
        std::cout << " number, please enter one."
        << std::endl;
    }
}


float calc_volume_pyramid(float base, float height) {
    // return (base^2)*(height/3)
    return (pow(base, 2)) * (height / 3);
}


float  main_volume_square_pyramid() {
    // declare variables
    std::string baseStr, heightStr;
    float baseFloat, heightFloat, volumePyramid;

    // get the base and height
    std::cout << "This program displays the volume of a square";
    std::cout << "pyramid given the base edge and the height "
    << std::endl;
    std::cout
    << "Enter the base edge: ";
    std::cin >> baseStr;
    std::cout << "Enter the height :";
    std::cin >> heightStr;


    try {
        // convert the base to a float
        baseFloat = std::stof(baseStr);

        try {
            // convert the height to a float
            heightFloat = std::stof(heightStr);

            // call the calc_volume_pyramid() function
            volumePyramid = calc_volume_pyramid(baseFloat, heightFloat);

            // display the volume of the pyramid
            std::cout << "The volume of your square pyramid is "
            << std::fixed << std::setprecision(2)
            << std::setfill('0')
            << volumePyramid << " cm ^ 3 " << std::endl;
        } catch (std::invalid_argument) {
            // if the height cannot become a float, tell the user to enter one
            std::cout
            << heightStr << " is not a valid floating";
            std::cout << "decimal number, please enter one" << std::endl;
        }
        } catch (std::invalid_argument) {
            // if the base cannot become a float, tell the user to enter one
            std::cout
            << baseStr << " is not a valid floating";
            std::cout << "decimal number, please enter one" << std::endl;
        }
}

int main() {
    // declare userChoice
    std::string userChoice;

    // get user choice
    std::cout << "This program writes the equation of a line from";
    std::cout << " two points on a graph (press 1 for this option),";
    std::cout << " or displays the volume of a pyramid with a square";
    std::cout << "base given the base and height (press 2 for this option).";
    std::cin >> userChoice;

    // if user choice is 1, then call the main_equation_of_a_line function
    if (userChoice == "1") {
        main_equation_of_a_line();
    } else if (userChoice == "2") {
        // otherwise, if user choice is 2, call  main_volume_square_pyramid()
        main_volume_square_pyramid();
    } else {
        // otherwise, tell the user to enter 1 or 2
        std::cout << "Please enter 1 or 2 for your selection." << std::endl;
    }
}
