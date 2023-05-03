#include "Header.h"
#include <time.h>
#include <vector>
using namespace std;
void test_1000()
{
	///////////////////////////////////////////////////////////////////////1000////////////////////////////////
	clock_t start_1000 = clock();
	for (int i = 0; i < 100; i++)
	{
		Tree A(lcg());
		for (int j = 0; j < 1000; j++)
		{
			A.insert(lcg());
		}
	}


	clock_t end_1000 = clock();

	long double seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	long double result_1000 = seconds_1000 / 100;
	printf("1000 TEST\nThe time: %lf seconds\nThe final result = % lf\n", seconds_1000, result_1000);
	
	//////////////////////////////////////////////////////1000 find//////////////////////////////////////////////////////
	
	Tree A(lcg());
	for (int j = 0; j < 1000; j++)
	{
		A.insert(lcg());
	}
	start_1000 = clock();
	for (int j = 0; j < 1000; j++)
	{
		A.contains(lcg());
	}
	end_1000 = clock();
	seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	result_1000 = seconds_1000 / 1000;
	printf("1000 TEST FIND\nThe time: %lf seconds\nThe final result of find = % lf\n", seconds_1000, result_1000);

	//////////////////////////////////////////////////////1000 erase//////////////////////////////////////////////////////
	start_1000 = clock();

	
	for (int j = 0; j < 1000; j++)
	{
		A.insert(lcg());
		A.erase(lcg());
	}
	end_1000 = clock();
	seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	result_1000 = seconds_1000 / 1000;
	printf("1000 TEST ERASE\nThe time: %lf seconds\nThe final result of erase = % lf\n\n", seconds_1000, result_1000);
}

void test_10000()
	{
		/////////////////////////////////////////////////////////////////////10000////////////////////////////////////////////
	clock_t start_10000 = clock();
	for (int i = 0; i < 100; i++)
	{
		Tree A(lcg());
		for (int j = 0; j < 10000; j++)
		{
			A.insert(lcg());
		}

	}


	clock_t end_10000 = clock();

	long double seconds_10000 = (long double)(end_10000 - start_10000) / CLOCKS_PER_SEC;
	long double result_10000 = seconds_10000 / 100;
	printf("10 000 TEST\nThe time: %lf seconds\nThe final result = % lf\n", seconds_10000, result_10000);

	//////////////////////////////////////////////////////10000 find//////////////////////////////////////////////////////
	
	Tree A(lcg());
	for (int j = 0; j < 10000; j++)
	{
		A.insert(lcg());
	}
	start_10000 = clock();
	for (int j = 0; j < 1000; j++)
	{
		A.contains(lcg());
	}
	end_10000 = clock();
	seconds_10000 = (long double)(end_10000 - start_10000) / CLOCKS_PER_SEC;
	result_10000 = seconds_10000 / 1000;
	printf("10000 TEST FIND\nThe time: %lf seconds\nThe final result of find = % lf\n", seconds_10000, result_10000);

	//////////////////////////////////////////////////////10000 erase//////////////////////////////////////////////////////
	start_10000 = clock();
	for (int j = 0; j < 1000; j++)
	{
		A.insert(lcg());
		A.erase(lcg());
	}
	end_10000 = clock();
	seconds_10000 = (long double)(end_10000 - start_10000) / CLOCKS_PER_SEC;
	result_10000 = seconds_10000 / 1000;
	printf("10000 TEST Erase\nThe time: %lf seconds\nThe final result of erase = % lf\n\n", seconds_10000, result_10000);

	}

void test_100000()
{
	////////////////////////////////////////////////////////////////////100000////////////////////////////////////////////
	clock_t start_100000 = clock();
	for (int i = 0; i < 100; i++)
	{
		Tree A(lcg());
		for (int j = 0; j < 100000; j++)
		{
			A.insert(lcg());
		}
	}
	

	clock_t end_100000 = clock();

	long double seconds_100000 = (long double)(end_100000 - start_100000) / CLOCKS_PER_SEC;
	long double result_100000 = seconds_100000 / 100;
	printf("100 000 TEST\nThe time: %lf seconds\nThe final result = % lf\n", seconds_100000, result_100000);
	//////////////////////////////////////////////////////100000 find//////////////////////////////////////////////////////
	
	Tree	 A(lcg());
	for (int j = 0; j < 100000; j++)
	{
		A.insert(lcg());
	}
	start_100000 = clock();
	for (int j = 0; j < 1000; j++)
	{
		A.contains(lcg());
	}
	end_100000 = clock();
	seconds_100000 = (long double)(end_100000 - start_100000) / CLOCKS_PER_SEC;
	result_100000 = seconds_100000 / 1000;
	printf("100000 TEST FIND\nThe time: %lf seconds\nThe final result of find = % lf\n", seconds_100000, result_100000);

	//////////////////////////////////////////////////////100000 erase//////////////////////////////////////////////////////x
	start_100000 = clock();
	for (int j = 0; j < 1000; j++)
	{
		A.insert(lcg());
		A.erase(lcg());
	}
	end_100000 = clock();
	seconds_100000 = (long double)(end_100000 - start_100000) / CLOCKS_PER_SEC;
	result_100000 = seconds_100000 / 1000;
	printf("100000 TEST ERASE\nThe time: %lf seconds\nThe final result of find = % lf\n\n", seconds_100000, result_100000);

}
void zadacha_easy(vector<int> &vec)
{
	Tree A({});
	vector<int> temp;
	cout << "First vector ";
	for (int i = 0; i < vec.size(); i++)
	{
		cout  << vec.at(i) << " ";
		if (!A.contains(vec.at(i)))
		{
			A.insert(vec.at(i));
			A.erase(0);
		}
		else
		{	
			bool found = std::find(temp.begin(), temp.end(), vec.at(i)) != temp.end();
			if (!found)
			{
				temp.push_back(vec.at(i));
			}
		}
	}
	cout << "\n";
	A.print();
	vec = temp;

}
//////////////////////////////////////////////////vector/////////////////////////////////
void test_1000_vector()
{
	cout << "...........ֲוךעמנû!......\n";
	///////////////////////////////////////////////////////////////////////1000////////////////////////////////
	clock_t start_1000 = clock();
	for (int i = 0; i < 100; i++)
	{
		vector<int> A;
		for (int j = 0; j < 1000; j++)
		{
			A.push_back(lcg());
		}
	}


	clock_t end_1000 = clock();

	long double seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	long double result_1000 = seconds_1000 / 100;
	printf("1000 TEST\nThe time: %lf seconds\nThe final result = % lf\n", seconds_1000, result_1000);

	//////////////////////////////////////////////////////1000 find//////////////////////////////////////////////////////

	vector<int> A;
	for (int j = 0; j < 1000; j++)
	{
		A.push_back(lcg());
	}
	start_1000 = clock();
	for (int j = 0; j < 1000; j++)
	{
		for (int i = 0; i < A.size(); i++)
		{
			if (A.at(i) == lcg()) break;
		}
	}
	end_1000 = clock();
	seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	result_1000 = seconds_1000 / 1000;
	printf("1000 TEST FIND\nThe time: %lf seconds\nThe final result of find = % lf\n", seconds_1000, result_1000);

	//////////////////////////////////////////////////////1000 erase//////////////////////////////////////////////////////
	start_1000 = clock();


	for (int j = 0; j < 1000; j++)
	{
		A.push_back(lcg());
		for (int i = 0; i < A.size(); i++)
		{
			if (A.at(i) == lcg())
			{
				A.erase(A.begin() + i);
			}
		}
	}
	end_1000 = clock();
	seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	result_1000 = seconds_1000 / 1000;
	printf("1000 TEST ERASE\nThe time: %lf seconds\nThe final result of erase = % lf\n\n", seconds_1000, result_1000);
}
void test_10000_vector()
{
	
	///////////////////////////////////////////////////////////////////////10000////////////////////////////////
	clock_t start_1000 = clock();
	for (int i = 0; i < 100; i++)
	{
		vector<int> A;
		for (int j = 0; j < 10000; j++)
		{
			A.push_back(lcg());
		}
	}


	clock_t end_1000 = clock();

	long double seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	long double result_1000 = seconds_1000 / 100;
	printf("10000 TEST\nThe time: %lf seconds\nThe final result = % lf\n", seconds_1000, result_1000);

	//////////////////////////////////////////////////////10000 find//////////////////////////////////////////////////////

	vector<int> A;
	for (int j = 0; j < 10000; j++)
	{
		A.push_back(lcg());
	}
	start_1000 = clock();
	for (int j = 0; j < 1000; j++)
	{
		for (int i = 0; i < A.size(); i++)
		{
			if (A.at(i) == lcg()) break;
		}
	}
	end_1000 = clock();
	seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	result_1000 = seconds_1000 / 1000;
	printf("10000 TEST FIND\nThe time: %lf seconds\nThe final result of find = % lf\n", seconds_1000, result_1000);

	//////////////////////////////////////////////////////10000 erase//////////////////////////////////////////////////////
	start_1000 = clock();


	for (int j = 0; j < 1000; j++)
	{
		A.push_back(lcg());
		for (int i = 0; i < A.size(); i++)
		{
			if (A.at(i) == lcg())
			{
				A.erase(A.begin() + i);
			}
		}
	}
	end_1000 = clock();
	seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	result_1000 = seconds_1000 / 1000;
	printf("10000 TEST ERASE\nThe time: %lf seconds\nThe final result of erase = % lf\n\n", seconds_1000, result_1000);
}
void test_100000_vector()
{
	
	///////////////////////////////////////////////////////////////////////100000////////////////////////////////
	clock_t start_1000 = clock();
	for (int i = 0; i < 100; i++)
	{
		vector<int> A;
		for (int j = 0; j < 100000; j++)
		{
			A.push_back(lcg());
		}
	}


	clock_t end_1000 = clock();

	long double seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	long double result_1000 = seconds_1000 / 100;
	printf("100000 TEST\nThe time: %lf seconds\nThe final result = % lf\n", seconds_1000, result_1000);

	//////////////////////////////////////////////////////100000 find//////////////////////////////////////////////////////

	vector<int> A;
	for (int j = 0; j < 100000; j++)
	{
		A.push_back(lcg());
	}
	start_1000 = clock();
	for (int j = 0; j < 1000; j++)
	{
		for (int i = 0; i < A.size(); i++)
		{
			if (A.at(i) == lcg()) break;
		}
	}
	end_1000 = clock();
	seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	result_1000 = seconds_1000 / 1000;
	printf("100000 TEST FIND\nThe time: %lf seconds\nThe final result of find = % lf\n", seconds_1000, result_1000);

	//////////////////////////////////////////////////////100000 erase//////////////////////////////////////////////////////
	start_1000 = clock();


	for (int j = 0; j < 1000; j++)
	{
		A.push_back(lcg());
		for (int i = 0; i < A.size(); i++)
		{
			if (A.at(i) == lcg())
			{
				A.erase(A.begin() + i);
			}
		}
	}
	end_1000 = clock();
	seconds_1000 = (long double)(end_1000 - start_1000) / CLOCKS_PER_SEC;
	result_1000 = seconds_1000 / 1000;
	printf("100000 TEST ERASE\nThe time: %lf seconds\nThe final result of erase = % lf\n\n", seconds_1000, result_1000);
}

int main() {
	
	Tree A(20);
	A.insert(1);
	A.insert(30);
	A.insert(20);
	/*A.insert(25);
	A.insert(5);
	A.insert(10);
	A.insert(30);
	A.
	A.insert(5);*/
	Tree B = A;
	A.erase(25);
	cout << "B\n";
	A.print();
	cout << "B\n";
	B.print();
	if (B.contains(25)) cout << "ecTb";  /// ץûûûû נאבמעאוע
	
	test_1000();
	test_10000();
	test_100000();
	vector<int> vec{1,1,4,12,4,5,2,3,3,3,127,21,12,536,79,3,6,597,4,56,4324,65};
	zadacha_easy(vec);
	cout << "last vector ";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << " ";
	}
	test_1000_vector();
	test_10000_vector();
	test_100000_vector();
	_getch();	
}

