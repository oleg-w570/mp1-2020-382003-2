#include "text_editor.h"

int DLdistance(string s1, string s2)
{
	int i;
	int m = s1.size();
	int n = s2.size();
	int** d = new int* [m];
	for (i = 0; i < m; i++)
		d[i] = new int[n];

	d[0][0] = 0;
	for (i = 1; i < m; i++)
		d[i][0] = d[i - 1][0] + 1;

	for (i = 1; i < n; i++)
		d[0][i] = d[0][i - 1] + 1;

	for (i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{
			if (s1[i] == s2[j])
				d[i][j] = d[i - 1][j - 1];
			else
				d[i][j] = d[i - 1][j - 1] + 1;
			d[i][j] = min(min(d[i][j], d[i - 1][j] + 2), d[i][j - 1] + 1);
			if (i > 1 && j > 1 && s1[i] == s2[j - 1] && s1[i - 1] == s2[j])
				d[i][j] = min(d[i][j], d[i - 2][j - 2] + 1);
		}

	return d[m - 1][n - 1];
}

void text_editor::Print()
{
	cout << text << endl;
}

void text_editor::input()
{
	ifstream itext("text.txt");
	ifstream vocab("voc.txt");
	string temp;

	if (itext.is_open())
	{
		cout << "The text is open!" << endl;
		getline(itext, text);
	}
	else
	{
		cout << "Failed to open text file!" << endl;
	}

	if (vocab.is_open())
	{
		cout << "The vocabulary is open!" << endl;
		while (vocab >> temp)
		{
			voc.push_back(temp);
		}
	}
	else
	{
		cout << "Failed to open vocabulary file!" << endl;
	}

	itext.close();
	vocab.close();
}

void text_editor::output()
{
	ofstream ofile("text_edit.txt");
	
	if (ofile.is_open())
	{
		string v = ".!?";
		size_t prev = 0;
		size_t pos = text.find_first_of(v);

		while (pos != text.npos)
		{
			string sentence = text.substr(prev, pos - prev + 1);
			if (sentence.size() > 0)
			{
				ofile << sentence << endl;
			}
			prev = pos + 2;
			pos = text.find_first_of(v, prev);
		}
	}
	else
	{
		cout << "Failed to open text file!" << endl;
	}

	ofile.close();
}

void text_editor::fix()
{
	string v = " .!,?;:";
	size_t prev = 0;
	size_t pos = text.find_first_of(v);
	while (pos != text.npos)
	{
		string word = text.substr(prev, pos - prev);
		if (word.size() > 0)
		{
			int min_dis = 4;
			int k = 0;

			for (int i = 0; i < voc.size() && min_dis > 0; i++)
			{
				int dis = DLdistance(word, voc[i]);
				if (dis < min_dis)
				{
					min_dis = dis;
					k = i;
				}
			}

			if (min_dis > 0)
			{
				if (min_dis < 4)
				{
					cout << "Do you want to correct the word " << word <<" to " << voc[k] << "? (y/n)" << endl << ">>> ";
					char t;
					do
					{
						cin >> t;
						switch (t)
						{
						case 'y': {
							text.replace(prev, pos - prev, voc[k]);
							break;
						}
						case 'n': {
							text.insert(prev, "*");
							break;
						}
						default: {
							cout << "Incorrect value!" << endl;
							break;
						}
						}
					} while (t != 'y' && t != 'n');
				}
				else
				{
					text.insert(prev, "*");
				}
			}
		}
		prev = pos + 1;
		pos = text.find_first_of(v, prev);
	}
}

void text_editor::replacement()
{
	string word1, word2;
	size_t prev = 0;
	size_t pos;

	do
	{
		cout << "What word do you want to replace?" << endl << ">>> ";
		cin >> word1;
		pos = text.find(word1, prev);
		if (pos == text.npos)
			cout << "Word not find!" << endl;
	} while (pos == text.npos);
	
	cout << "A replacement word?" << endl << ">>> ";
	cin >> word2;

	while (pos != text.npos)
	{
		text.replace(pos, word1.size(), word2);
		prev = pos + word1.size();
		pos = text.find(word1, prev);
	}

	cout << "All words are replaced!" << endl;
}

int text_editor::count_word()
{
	string word;
	int k = 0;
	cout << "Which word do you want to count?" << endl << ">>> ";
	cin >> word;

	size_t prev = 0;
	size_t pos = text.find(word, prev);
	while (pos != text.npos)
	{
		k++;
		prev = pos + word.size();
		pos = text.find(word, prev);
	}

	return k;
}
