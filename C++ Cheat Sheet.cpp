/*
* learningc.cpp
* Created by: Ugo Onuke
* 31 Jan 2018
* 12:55:58
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

// Functions
int addNum(int x, int y = 10) { // y = int sets y to a default int in function and can be overwritten
	return x + y;
}

int addNum(int x, int y, int z) { // Functions can be redefined with different parameters
	return x + y + z;
}

// Recursion
int factorial(int x) {
	int n;
	if(x == 1) return x;
	else n = factorial(x-1) * x;
	return n;
}

// Pointers
void makeMeYoung(int* age) {
	cout<<"I used to be "<<*age<<" years old"<<endl;
	*age = 19;
}

// References
void actYour(int& age) {
	age = 21;
}

// Classes
class Animal {
private:
	int height;
	int weight;
	string name;

	static int numOfAnimals; // This variable will remain the same in every Aminal object

public:
	int getHeight() { return height; }
	int getWeight() { return weight; }
	string getName() { return name; }
	void setHeight(int cm) { height = cm; }
	void setWeight(int kg) { weight = kg; }
	void setName(string animalName) { name = animalName; }
	//void setAll(int, int, string);

	Animal(int, int, string); // Default constructor
	~Animal(); // Class de-constructor
	Animal();

	static int getNumOfAnimals() { return numOfAnimals; }
	void toString();
};

// Declaring static variables of class
int Animal::numOfAnimals = 0;

// Regular functions and constructors are the same
//void Animal::setAll(int height, int weight, string name) {
//	this->height = height; // 'This' refers to object specific attributes/variables
//	this->weight = weight;
//	this->height = height;
//	Animal::numOfAnimals++;
//}

// Class constructor
Animal::Animal(int height, int weight, string name) {
	this->height = height; // 'This' refers to object specific attributes/variables
	this->weight = weight;
	this->name = name;
	Animal::numOfAnimals++;
}

// Class de-constructor
Animal::~Animal() {
	cout<<"Animal "<<this->name<<" destroyed"<<endl;
}

// Class default constructor
Animal::Animal() {
	Animal::numOfAnimals++;
}

void Animal::toString() {
	cout<<this->name<<" is "<<this->height<<"cm tall and "<<this->weight<<
			"kg in weight"<<endl;
}

// Class Inheritance
class Dog : public Animal {
private:
	string sound = "Woof";

public:
	void getSound() { cout<<sound<<endl; }
	Dog(int, int, string, string);
	Dog() : Animal() {};
	void toString();
};

// Class constructor
Dog::Dog(int height, int weight, string name, string bark) : Animal(height, weight, name) {
	this->sound = bark;
}

void Dog::toString() {
	cout<<this->getName()<<" is "<<this->getHeight()<<"cm tall and "<<
			this->getWeight()<<" kg in weight and says "<<this->sound<<endl;
}

// Virtual Classes are classes with attributes that may be overwritten by a sub class
class Human {
public:
	void getFamily() { cout<<"We are humans"<<endl; }
	virtual void getClass() { cout<<"I'm am a person"<<endl; }
};

class Child : public Human {
public:
	void getClass() { cout<<"I'm a child"<<endl; }
};

class Baby : public Human{
public:
	void getClass() { cout<<"I'm a baby"<<endl; }
	void getDerived() { cout<<"I'm a Human and Dog"<<endl; }
};
void whatClassAreYou(Human *human) {
	human->getClass();
}

// Abstract Data Type
class Car {
public:
	virtual int getNumWheels() = 0;
	virtual int getNumDoors() = 0;
};

class StationWagon : public Car {
public:
	int getNumWheels() { cout<<"Station wagon has 4 wheels"<<endl; }
	int getNumDoors() { cout<<"Station wagon has 4 doors"<<endl; }
	StationWagon() {}
	~StationWagon();
};

int main()
{
	// Data Types
	string name = "My name is what?!";
	char c = 'o';
	const double PI = 3.1415927; // Constant variables value cannot change
	bool isPrime = true;
	int age = 20;
	float pi = 3.141592; // Accurate to 6 decimal places
	double num = 1.124691842648;
	short int n = 100;
	long int m = 1;
	long long int l = 100000000000000000;
	unsigned int o = 400000; // Same memory size as int but only contains positive ints
	long double p = 434565869835.2435678765;
	int largest = 2147483647;
	int smallest = -2147483647;

	// Random Number
	cout<<"Random Number"<<endl;
	int r = (rand() % 100)+1; // Generates random number between (1 - 100)
	cout<<"Random number: "<<r<<endl;
	cout<<endl;

	// Incrementing Arithmetic
	cout<<"Incrementing Arithmetic"<<endl;
	cout<<n<<endl;
	cout<<"n++ = "<<n++<<endl;
	cout<<n<<endl;
	cout<<"++n = "<<++n<<endl;
	cout<<n<<endl;
	cout<<"n-- = "<<n--<<endl;
	cout<<n<<endl;
	cout<<"--n = "<<--n<<endl;
	cout<<n<<endl;
	cout<<endl;

	//Order of Operations
	/*
	 * 		()
	 * 		*
	 * 		/
	 * 		+
	 * 		-
	 */

	// Functions
	cout<<"Functions"<<endl;
	cout<<addNum(1)<<endl;
	cout<<addNum(1, 1)<<endl;
	cout<<addNum(1, 1, 1)<<endl;
	cout<<endl;

	// Recursion
	cout<<"Recursion"<<endl;
	cout<<factorial(3)<<endl;
	cout<<endl;

	// File IO Read and Writing Files
	cout<<"FStream"<<endl;
	ofstream writer("Guess.txt"); // ofstream = output file stream
	if(!writer) {
		cout<<"Error opening file..."<<endl;
		return -1;
	} else {
		writer<<name<<endl;
		writer.close();
	}
	// Built-in functions
	/*
	 * 		ios::app 		Open stream to append what's already there
	 * 		ios::binary 	Treat file as binary
	 * 		ios::in 			Open file and read input
	 * 		ios::out		Open file and write output
	 * 		ios::trunc		Default
	 */
	ofstream writer1("Guess.txt", ios::app);
	if(!writer1) {
		cout<<"Error opening file..."<<endl;
		return -1;
	} else {
		writer1<<"\n Hello World"<<endl;
		writer1.close();
	}
	char letter;
	ifstream reader("Guess.txt"); // ifstream = input file stream
	if(!reader) {
		cout<<"Error opening file"<<endl;
		return -1;
	} else {
		for(int i = 0; !reader.eof(); i++) {
			reader.get(letter);
			cout<<letter;
		}
		cout<<endl;
		reader.close();
	}

	// Casting
	cout<<"Casting"<<endl;
	cout<<"4/5 = "<<4/5<<endl;
	cout<<"Casted 4/5 = "<<(float) 4/5<<endl;
	cout<<endl;

	// Pointers can be defined/initialized to more than one variables
	cout<<"Pointers"<<endl;
	int myAge =  20;
	int* agePtr = &myAge;
	char myGrade= 'A';
	cout<<"Size of int "<<sizeof(myAge)<<endl;
	cout<<"Size of char "<<sizeof(myGrade)<<endl;
	cout<<"'myAge' is located at: "<<&myGrade<<endl;
	cout<<"Address of pointer "<<agePtr<<endl;
	cout<<"Data at memory address "<<*agePtr<<endl;
	int badNum[5] = {2,23,24,3,42};
	int* numAPtr = badNum; // Array name is a pointer to the first element of array
	cout<<"Address "<<numAPtr<<" Value "<<*numAPtr<<endl;
	numAPtr++; // Increment through the array using pointers
	cout<<"Address "<<numAPtr<<" Value "<<*numAPtr<<endl;
	makeMeYoung(&myAge);
	cout<<"I'm "<<myAge<<" years old now"<<endl;
	cout<<endl;

	// References are only defined/initialized to one variable
	cout<<"References"<<endl;
	int& ageRef = myAge;
	cout<<"myAge: "<<myAge<<endl;
	ageRef++;
	cout<<"myAge: "<<myAge<<endl;
	actYour(ageRef);
	cout<<"myAge: "<<myAge<<endl;
	cout<<endl;

	// Classes
	cout<<"Classes"<<endl;
	Animal Sasha; // Using class default constructor to create object
	Sasha.setHeight(33);
	Sasha.setWeight(10);
	Sasha.setName("Sasha");

	cout<<Sasha.getName()<<" is "<<Sasha.getHeight()<<"cm tall and "<<Sasha.getWeight()<<
				"kg in weight"<<endl;

	Animal Rex(36, 15, "Rex");
	cout<<Rex.getName()<<" is "<<Rex.getHeight()<<"cm tall and "<<Rex.getWeight()<<
					"kg in weight"<<endl;
	cout<<endl;

	// Inheritance
	cout<<"Inheritance"<<endl;
	Dog spot(40, 16, "Spot", "Woof");
	cout<<"Number of Animals: "<<Animal::getNumOfAnimals()<<endl;
	spot.getSound();
	Sasha.toString();
	spot.Animal::toString();
	cout<<endl;

	// Virtual Classes
	cout<<"Virtual Classes"<<endl;
	Human *human = new Human;
	Child *child = new Child;
	whatClassAreYou(human);
	whatClassAreYou(child);
	Human Ugo;
	Baby Sarah;
	Human* ptrHuman = &Ugo;
	Human* ptrBaby = &Sarah;
	// Polymorphism is calling methods from both superclass(parent class) and sub class
	//and the most relevant attribute is executed
	ptrHuman->getFamily();
	ptrHuman->getClass();
	ptrBaby->getFamily();
	ptrBaby->getClass();
	cout<<endl;

	// Abstract Data Type
  cout<<"Abstract Data Types"<<endl;
	Car* stationWagon = new StationWagon();
	stationWagon->getNumWheels();
	cout<<endl;

	// Error Catching
	cout<<"Error Catching"<<endl;
	int number = 0;
	try {
		if(number != 0) cout<<10/number<<endl;
		else throw(number);
	} catch(int number) {
		cout<<number<<" is not valid"<<endl;
	}
	cout<<endl;

	// If Statements
	/*
	 * 	Operators:
	 * 		&&
	 * 		||
	 * 		>
	 * 		<
	 * 		>=
	 * 		<=
	 * 		==
	 * 		!=
	 * 		!
	 */
	cout<<"If Statement"<<endl;
	if(isPrime) cout<<PI<<" is prime"<<endl;
	else if(pi < 4) pi = 4;
	else num = 9.05;
	cout<<endl;

	// Switch Statements
	cout<<"Switch Statement"<<endl;
	switch(sizeof(m)) {
	case 1:
		cout<<1<<endl;
		break;
	case 2:
			cout<<2<<endl;
			break;
	case 4:
			cout<<4<<endl;
			break;
	case 8:
			cout<<8<<endl;
			break;
	default:
			cout<<"Unknown"<<endl;
			break;
	}
	cout<<endl;

	// Ternary Operator
	cout<<"Ternary Operator"<<endl;
	cout<<"m = "<<m<<endl;
	m = (l > 3 && o > 6 && p > 7) ? 7000000 : 4;
	cout<<"m = "<<m<<endl;
	cout<<endl;

	//For Loops
	cout<<"For Loop"<<endl;
	for(int i = 0; i < 10; i++) {
		cout<<"i = "<<i<<endl;
	}
	cout<<endl;

	//While Loops
	cout<<"While Loop"<<endl;
	int i = 0;
	while(i < 10) {
		cout<<"i = "<<i<<endl;
		i++;
	}
	cout<<endl;

	//DoWhile Loops
	cout<<"DoWhile Loop"<<endl;
	i = 0;
	do {
		cout<<"i = "<<i<<endl;
		i++;
	} while(i < 10);
	cout<<endl;

	//User Input
	cout<<"User Input"<<endl;
	string test;
	cin>>test;
	cout<<test<<endl;
	getline(cin, test);
	cout<<test<<endl;
	// int a = std :: stoi(test); // Convert String to Int
	// double b = std :: stod(test); // Convert String to Double
	cout<<endl;

	// Strings
	cout<<"Strings"<<endl;
	string s = "Hello World";
	cout<<s.size()<<endl; // Int size of string starting from 1
	cout<<s.empty()<<endl; // 0 == False || 1 == True
	cout<<s.append("!")<<endl;
	string st = "Hi";
	cout<<s.compare(st)<<endl; // 0 == Equal || 1 == Less Than || -1 == Greater Than
	string temp = st.assign(st); // Temp copies entire 'st' string
	temp = st.assign(st, 0,1);
	// Temp copies 'st' string starting from char index 0 and copying the next 1 char(s)
	int index = s.find("World", 0);
	// Finds the index of where the word starts in string starting at index 0
	cout<<index<<endl;
	s.insert(6, "My ");
	cout<<s<<endl;
	s.erase(0, 6); // Starting at index 0 erase 6 chars
	cout<<s<<endl;
	s.replace(0, 3, "Hi "); // Starting at index 0 replace 2 chars
	cout<<s<<endl;
	cout<<endl;

	//Vectors
	cout<<"Vectors"<<endl;
	vector <int> lottery(10);
	int lotto[5] = {1,2,3,4,5};
	lottery.insert(lottery.begin(), lotto, lotto+3);
	// Inserts first 3 elements of array into the start of vector
	cout<<lottery.at(2);
	lottery.insert(lottery.begin()+5, 44); // Insert at 5th element of vector
	lottery.push_back(64); // Inserts value at the end of vector
	cout<<lottery.back()<<endl; // Returns last value of vector
	cout<<lottery.front()<<endl; // Returns first value of vector
	cout<<lottery.empty()<<endl; // Returns 0 if not empty || 1 if empty
	cout<<lottery.size()<<endl; // Returns size of vector
	lottery.pop_back(); // Removes last value of vector
	cout<<endl;

	// Random Stuff
  cout<<"Random Stuff"<<endl;
  num--;
	smallest += largest;
	largest += smallest;
	if(c<'k') cout<<"C"<<endl;
	cout<<"Size of int is " <<sizeof(age)<<" bytes"<<endl;
	cout<<"\nEclipse C++"<<endl;
	return 0;
}
