#include <iostream>
#include <typeinfo>
using namespace std;

//MODIFY AS NEEDED. This is a template to get you started
class Dessert
{
	public: 
	Dessert()
	{
		calories = 10;
	}
	
	double getCalories()
	{ return calories;}
	
	
	void printDetails()
	{
	cout << "Calories of " << typeid(this).name() << " is " << calories << "\n";
	return;
	}
		
	protected:
		double calories;		
};

	
int main()
{

  cout << "Q6 running..." << endl;
  cout << "How many desserts do you have?: ";
  int    count;
  int sortCount;
  cin >> count;
  sortCount = count;
  double calories;
  double Dcals[count][2];
  double temp[2];

  for (int i=0; i<count; i++)
  {
	cout << "Input dessert " << i+1 << " calories: ";
	cin >> calories;
	Dcals[i][0] = i;
	Dcals[i][1] = calories;
	//You can add whatever else you want to this loop
	//Just don't change its basic structure
  }
  while (sortCount > 0)
    {

      for (int i = 0; i < count-1; i++)
	{
	  if (Dcals[i][1] > Dcals[i+1][1])
	    {
	      temp[0] = Dcals[i][0];
	      temp[1] = Dcals[i][1];
	      Dcals[i][0] = Dcals[i+1][0];
	      Dcals[i][1] = Dcals[i+1][1];
	      Dcals[i+1][0] = temp[0];
	      Dcals[i+1][1] = temp[1];
	    }
	}
      sortCount--;
    }

  //CANNOT CHANGE;
  //YOU NEED TO MAKE THIS WORK
  for (int i; i<count; i++)
  {

    cout << "Dessert number " << Dcals[i][0]+1 << " has " << Dcals[i][1] << " calories" << endl;
	//You need to make a string like this appear
	//Dessert number 4 has 77 calories	
	//THESE NEED TO BE IN ODER FROM HIGHEST CALORIES TO LOWEST CALORIES
	
	//Sample input
	/*
	77
	10
	677
	*/
	
	//Sample output
	/*
	Dessert number 3 has 677 calories
	Dessert number 1 has 77 calories
	Dessert number 2 has 10 calories
	*/
  }

  return 0;
}

