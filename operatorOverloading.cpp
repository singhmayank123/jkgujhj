// c++ program to overload << andf >> operator 

#include<iostream>
using namespace std;

class Student{
	
	private:
		string name;
		int age;
		
	public:
		
		ostream& operator<<(ostream& os, const Student& s){
			
			os << "Name : "<<s.name<<endl;
			os << "Age : "<<s.age << endl;
			
			return os;
		}
		
		istream& operator>>(istream& is, Student& s){
			
			cout << "NAME : ";
			is >> s.name;
			cout << "AGE : ";
			is >> s.age;
			
			return is;
		}
};

int main(){
	
	Student s1, s2;
	
	cout << "Enter the details of student 1: "<<endl;
	
	cin >> s1 ;
	
	cout << "Enter the details of student 2: "<<endl;
	
	cin >> s2 ;
	
	cout << "\nBelow are the student details: "<<endl;
	cout << s1 << endl << s2;
}
