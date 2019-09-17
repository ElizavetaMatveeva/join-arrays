#define F 7
#define S 5

void print(int* m, int sz) // Print array
{
	int i;
	for(i = 0; i < sz; i++)
	{
		printf("%i ", *(m + i));
	}
	printf("\n");
}

void join(int* first, int size1, int* second, int size2, int* result) // Method that joins both arrays together
{
	int k1 = 0, k2 = 0, i = 0; // 
	while((k1 < size1) && (k2 < size2)) // Joining arrays together until one of them ends
	{ 
		if ( *(first + k1) < *(second + k2) ) // If the value from the 1st array is smaller, write that value in the result array
		{
			*(result + i++) = *(first + k1++); // Also incrementing i at the same time
		}
		else // If the value from the 2nd array is smaller, write that value in the result array instead
			if (*(first + k1) > *(second + k2)) 
				*(result + i++) = *(second + k2++);
		else // If values are equal, write them both in the result array
		{
			*(result + i++) = *(first + k1++);
			*(result + i++) = *(second + k2++);
		}
	}
	while (k1 < size1) // If the second array was shorter, copying the rest of the first array
		*(result + i++) = *(first + k1++);
	while (k2 < size2) // If the first array was shorter, copying the rest of the second array
		*(result + i++) = *(second + k2++);
}

int main()
{
	int first[F] = {3, 4, 8, 9, 9, 9, 9}, second[S] = {1, 9, 11, 12, 15}, result[F + S];
	print(first, F);
	print(second, S); 
	join(first, F, second, S, result); 
	print(result, F+S);
	return 0;
}
