#include "OAHashMap.h"
#include "Stopwatch.h"
#include "FileTokenizer.h"

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	Stopwatch s;
	FileTokenizer ft;
	ofstream excelImportFile;

	size_t index = 0;
	size_t cumulativeSearchTime = 0;
	size_t cumulativeMapSearchTime = 0;
	vector<string> wordsRead;

	const size_t TEST_ARRAY_SIZE(10000);
	const size_t TEST_INCREMENT(250);

	string testArray[TEST_ARRAY_SIZE];
	OAHashMap<string> testMap(TEST_ARRAY_SIZE);

	ft.read("words.txt");
	excelImportFile.open("searchresults.txt");

	for (unsigned int i = 0; i < TEST_ARRAY_SIZE; i += TEST_INCREMENT)
	{
		// Add another TEST_INCREMENT words to the end of the array
		for (int j = 0; j < TEST_INCREMENT; j++)
		{
			wordsRead.push_back(ft.getNextWord());
			testArray[index++] = wordsRead[j];
			testMap.insert(wordsRead[j]);
		}

		// Search for each of the recently read words, register cumulative time spent to do so
		for (int j = 0; j < TEST_INCREMENT; j++)
		{
			// LINEAR SEARCH
			s.start();
			for (unsigned int k = 0; k < index; k++)
			{
				if (testArray[k] == wordsRead[j]) break;
			}
			s.stop();
			cumulativeSearchTime += s.getDuration();

			// MAP TEST
			bool result;
			s.start();
			result = testMap.search(wordsRead[j]);
			s.stop();
			if (!result) cout << "ERROR!!!" << endl;
			cumulativeMapSearchTime += s.getDuration(Stopwatch::NANOSECONDS);
		}

		cout << (double)(index) / TEST_ARRAY_SIZE << "\t" << cumulativeSearchTime << "\t" << cumulativeMapSearchTime << endl;
		excelImportFile << (double)(index) / TEST_ARRAY_SIZE << ";" << cumulativeSearchTime << ";" << cumulativeMapSearchTime << endl;

		// Reset for next test run
		cumulativeSearchTime = 0;
		cumulativeMapSearchTime = 0;
		wordsRead.clear();

	}
}