#include <iostream>
#include <typeinfo>

using namespace std;


class Dessert
{
	public: 
	Dessert()
	{
		calories = 10;
	}
	
	virtual void addSugar(double s)
	{ 
		calories += s*300; 
		return;
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

//Add the BirthdayCake class here
class BirthdayCake : public Dessert
{
public:
  BirthdayCake()
  {
    calories = 20000;
  }

  void addSugar(double s)
  { 
    calories += s*2; 
    return;
  }
};

//DO NOT MODIFY
void sweeten(Dessert *d, double s)
{ 
	d->addSugar(s); 
	cout << "Added Sugar to " << typeid(d).name() << endl;
	return;
}


int main()
{
  
  cout << "Q2 running..." << endl;
  double increment;
  cout << "Input sugar increment: ";
  cin >> increment;
  
  Dessert* d = new Dessert();
  d->printDetails();
  sweeten(d, increment);
  d->printDetails();
  
  //Uncomment once BirthdayCake class is created and you submit the question
  //Fix typos and correct as needed

  BirthdayCake* b = new BirthdayCake(); 
  b -> printDetails();
  sweeten(b, increment);
  b -> printDetails();

    
  return 0;
}

