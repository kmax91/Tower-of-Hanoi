///https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
///Edited by Arjun Kamath 11/5/18


#include <stdio.h> 
#include <iostream>
#include <algorithm>

int N;			//Number of disks
int speed;		//Speed of simulation

struct Stack {
	char A[10][20];
	int end;
};
Stack A,B,C;

void initialize_full(Stack &A,int N)
{
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<2*10;j++)
		{	
			if((j>= 10-i-1) && (j<= 10-i-1+(i+1)*2-1 )){
				A.A[i][j] = '*';
			}
			else{
				A.A[i][j] = ' ';
			}
		}
	}
	A.end = -1;
	std::cout<<"\n";
}

void initialize_empty(Stack &A,int N)
{
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<2*10;j++)
		{	
			if((j<= 10) && (j>= 10-1 )){
				A.A[i][j] = '|';
			}
			else{
				A.A[i][j] = ' '; 
				A.A[i][j+1] = ' '; 
			}
		}
	}
	A.end = N-1;
	std::cout<<"\n";
}

void print_all()
{
	std::cout<<"\n\t "<<A.end+1<<"\t\t\t\t\t\t\t\t "<<B.end+1<<"\t\t\t\t\t\t\t\t "<<C.end+1;
	std::cout<<"\n\n";
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<2*10;j++)
		{
			std::cout<<A.A[i][j];
		}
		std::cout<<"\t\t\t\t\t\t";	
		for(int j = 0;j<2*10;j++)
		{
			std::cout<<B.A[i][j];
		}
		std::cout<<"\t\t\t\t\t\t";	
		for(int j = 0;j<2*10;j++)
		{
			std::cout<<C.A[i][j];
		}

		std::cout<<"\n";

	}
	for(int j = 0;j<2*10;j++)
	{
		std::cout<<"=";
	}
	std::cout<<"\t\t\t\t\t\t";	
	for(int j = 0;j<2*10;j++)
	{
		std::cout<<"=";
	}
	std::cout<<"\t\t\t\t\t\t";	
	for(int j = 0;j<2*10;j++)
	{
		std::cout<<"=";
	}
	std::cout<<"\n\n";
}

void swap(int n,Stack &from_rod,Stack &to_rod)
{
	for(int j =0;j<2*10;j++)
	{
		char temp = from_rod.A[from_rod.end+1][j];
		from_rod.A[from_rod.end+1][j] = to_rod.A[to_rod.end][j];
		to_rod.A[to_rod.end][j] = temp;
	}
	from_rod.end++;
	to_rod.end--;

	print_all();
}

void wait()
{
	printf("\n\n");
	for(int s = 0;s< 20;s++){
	fflush(stdout);
	printf(".");	
		for(int k = 0;k< 100000000/(speed*10);k++);
	}
	printf("\n\n");
	
}

// C recursive function to solve tower of hanoi puzzle 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
	if (n == 1) 
	{ 
		printf("\n NEXT::Move disk 1 from rod %c to rod %c", from_rod, to_rod);
		wait();
		
		std::cout << "\033[2J\033[1;1H";
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
		if(from_rod == 'A'){
			if(to_rod == 'B')
				swap(n,A,B);
			else if(to_rod == 'C')
				swap(n,A,C);
		}
		else if(from_rod == 'B'){
			if(to_rod == 'A')				
				swap(n,B,A);
			else if(to_rod == 'C')
				swap(n,B,C);
		}
		else if(from_rod == 'C'){
			if(to_rod == 'A')
				swap(n,C,A);
			else if(to_rod == 'B')
				swap(n,C,B);
		}
		return; 
	
	} 
	towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
	
	printf("\n NEXT::Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
	wait();

	std::cout << "\033[2J\033[1;1H";
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
	if(from_rod == 'A'){
		if(to_rod == 'B')
			swap(n,A,B);
		else if(to_rod == 'C')
			swap(n,A,C);
	}
	else if(from_rod == 'B'){
		if(to_rod == 'A')				
			swap(n,B,A);
		else if(to_rod == 'C')
			swap(n,B,C);
	}
	else if(from_rod == 'C'){
		if(to_rod == 'A')
			swap(n,C,A);
		else if(to_rod == 'B')
			swap(n,C,B);
	}

	towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
}


int main() 
{ 	 
	std::cout<<"Enter number of disks:";
	std::cin>>N; 

	std::cout<<"Enter speed(1:10):";
	std::cin>>speed; 

	initialize_full(A,N);
	initialize_empty(B,N);
	initialize_empty(C,N);

	std::cout << "\033[2J\033[1;1H";
	printf("\n Initial arrangement");
	print_all();
	
	towerOfHanoi(N, 'A', 'C', 'B'); // A, B and C are names of rods 
	return 0; 
} 

