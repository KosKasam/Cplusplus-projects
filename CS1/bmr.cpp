// BMR Calculation Program
// Konstantinos Kasamias
// 02/16/2018
// Lab 5

#include <iostream>

using std::cout; using std::cin; using std::endl;

int heightInches, heightFeet, heightTotal, age, weight;
const int calories = 195;
char gender;

double bmrWomen(double weight, double height, double age); //function prototype for bmr of Women
double bmrMen(double weight, double height, double age); //function prototype for bmr of Men
int doughnut(double calories); //function prototype for the calculations of
							   //the number of donughts eaten based off of bmr

int main()
{
	
	cout << "Please enter height in feet and inches:\n" << endl;
	cin >> heightFeet >> heightInches;
	cout << "age in years:\nweight in pounds:\ngender[m/f]:\n" << endl;
	cin >> age >> weight >> gender;
	heightTotal = heightInches + heightFeet * 12;
	
	
//boolean operator processing gender as an expression for bmr
	if (gender=='m'){
		cout << bmrMen(weight, heightTotal, age) << endl;
		cout << doughnut(calories) << endl;
		system("pause");
	}

	else if (gender=='f'){
		cout << bmrWomen(weight, heightTotal, age) << endl;
		cout << doughnut(calories) << endl;
		system("pause");
	}
	else
	{
		cout << "Please enter either Male or Female:\n";
		system("pause");
	}
}



double bmrWomen(double weight, double height, double age) //function definition of bmr for Women
{
	double bmrWomen = 655 + (4.3*weight) + (4.7*height) - (4.7*age);
	return bmrWomen;
}



double bmrMen(double weight, double height, double age) //function definition of bmr for Men
{
	double bmrMen = 66 + (6.3*weight) + (12.9*height) - (6.8*age);
	return bmrMen;
}



int doughnut(double calories) //function definition of doughnuts
{
	if (gender == 'm')
	{
		double doughnut = bmrMen(weight, heightTotal, age) / calories;
		return doughnut;
	}
	else
	{
		double doughnut = bmrWomen(weight, heightTotal, age) / calories;
		return doughnut;
	}
}
