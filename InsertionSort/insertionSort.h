void insertionSort(int input[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (i == 0)
			continue;

		int temp = input[i];

		// SWAP!!!

		int position = i;

		while (position >= 0)
		{
			if (temp < input[position])
			{
				// stuff;
			}
		}


		/*int insertPosition = -1;

		for (int j = 0; j < i; j++)
		{
			if (insertPosition == -1)
			{
				if (input[j] > input[i])
					insertPosition = j;
			}
			else
			{
				input[j + 1] = input[j];
			}
		}
		
		if (insertPosition != -1)
			input[insertPosition] = temp;
		else
		{
			for (int j = 0; i < i; j++)
			{
				input[j + 1] = input[i];
				input[0] = temp;
			}
		}*/
	}
}