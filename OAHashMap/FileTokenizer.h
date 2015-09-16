#include<fstream>
#include<string>
#include<vector>
#include<time.h>

using namespace std;

class FileTokenizer
{
public:
	FileTokenizer() : nextWord(0)
	{
		srand(time(0));
	}

	~FileTokenizer()
	{
	}

	size_t read(string filename)
	{	
		string tempstr;
		in.open(filename.c_str());
		if(!in) 
		{
			throw std::exception();
		}

		while(!in.eof())
		{
			in >> tempstr;
			tokenize(tempstr, tokens, " .,!:");
		}
		in.close();

		nextWord = rand()%tokens.size();	// Start at random position
		
		return tokens.size();
	}

	string getNextWord()
	{
		string retVal;
		if(tokens.size() > 0)
		{ 
			retVal = tokens[nextWord];
			nextWord = (nextWord+1)%tokens.size();
		}
		return retVal;
	}
	

private:

	void tokenize(const string& str, vector<string>& tokens, const string& delimiters)
	{
		size_t lastPos = str.find_first_not_of(delimiters, 0);
		size_t pos     = str.find_first_of(delimiters, lastPos);

		while (string::npos != pos || string::npos != lastPos)
		{
			tokens.push_back(str.substr(lastPos, pos - lastPos));
			lastPos = str.find_first_not_of(delimiters, pos);
			pos = str.find_first_of(delimiters, lastPos);
		}
	}
	size_t nextWord;
	ifstream in;
	vector<string> tokens;
};

