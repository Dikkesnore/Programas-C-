/******************************
 *                            *
 *    Simple program going    *
 *    throught vectors        *
 *                            *
 ******************************/

#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

// Prototypes
int sum_positive(const std::vector<int> &v);
int count_evens(const std::vector<int> &v);
int count_evens(const Matrix &v);
bool equals(const std::vector<int> &v1, const std::vector<int> &v2);
bool contains(const std::vector<int> &v1, const std::vector<int> &v2);

int main()
{
	// Variables
	std::vector<int> list {45, -3, 16, 8};
	std::vector<int> list1 {45, -3, 16, 8};
	std::vector<int> list2 {45, -3};
	std::vector<int> list3 {45, 8, 8};
	Matrix matrix {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	// Testing functions
	std::cout << "Sum_pos(list) -> expected 69, gave " << sum_positive(list) << ".\n";
	std::cout << "Count_ev(list) -> expected 2, gave " << count_evens(list) << ".\n";
	std::cout << "Count_ev(matrix) -> expected 4, gave " << count_evens(matrix) << ".\n";
	std::cout << "Equals(list, list1) -> expected true, gave " << equals(list, list1) << ".\n";
	std::cout << "Equals(list, list2) -> expected false, gave " << equals(list, list2) << ".\n";
	std::cout << "Contains(list, list2) -> expected true, gave " << contains(list, list2) << ".\n";
	std::cout << "Contains(list, list3) -> expected false, gave " << contains(list, list3) << ".\n";
}

// Returns the sum of the positive elements in a vector
int sum_positive(const std::vector<int> &v)
{
	unsigned int sum = 0;

	for(int num:v)
	{
		if (num > 0)
		{
			sum += num;
		}
	}

	return sum;
}

// Returns the count of even numbers in a vector
int count_evens(const std::vector<int> &v)
{
	unsigned short count = 0;

	for (int num:v)
	{
		if (num % 2 == 0)
		{
			count++;
		}
	}

	return count;
}

// Returns the count of even numbers in a 2 dimensional vector
// Function overloading
int count_evens(const Matrix &v)
{
	unsigned short count = 0;

	for (std::vector<int> Line:v)
	{
		for (int num:Line)
		{
			count += (num % 2 == 0);
		}
	}

	return count;
}

// Checks if a vector is equal to another
bool equals(const std::vector<int> &v1, const std::vector<int> &v2)
{
	if (v1.size() != v2.size())
	{
		return false;
	}

	for (unsigned int index = 0; index < v1.size(); index++)
	{
		if(v1[index] != v2[index])
		{
			return false;
		}
	}

	return true;
}

// Checks if vector v1 has the elements in vector v2
// Elements repeated in v2 must be repeated in v1
bool contains(const std::vector<int> &v1, const std::vector<int> &v2)
{
	if (v1.size() < v2.size())
	{
		return false;
	}

	// Creating a vector holding the index of the values
	// Correlating a index of vector v2 to a index of vector v1
	// Id est element in v2[0] is in v1[verified[0]]
	std::vector<int> verified;
	bool found = false;

	for (unsigned int indexV2 = 0; indexV2 < v2.size(); indexV2++)
	{
		for (unsigned int indexV1 = 0; indexV1 < v1.size(); indexV1++)
		{
			// Checks if a index has already been verified
			bool skip = false;
			for (unsigned int ind:verified)
			{
				if(indexV1 == ind)
				{
					skip = true;
					break;
				}
			}

			if (v1[indexV1] == v2[indexV2] && !skip)
			{
				verified.push_back(indexV1);
				found = true;
				break;
			}
		}

		if(!found)
		{
			return false;
		}
		found = false;
	}

	return true;
}