# include "bits/stdc++.h"
using namespace std;

// Stern-Brocot seq: similar to Fibonacci sequence but it is different in the way fibonacci sequence is generated

// CPP program to print Brocot Sequence
void SternSequenceFunc(vector<int>& BrocotSequence, int n)
{
	// loop to create sequence
	for (int i = 1; BrocotSequence.size() < n; i++)
	{
		int considered_element = BrocotSequence[i];
		int precedent = BrocotSequence[i - 1];

		// adding sum of considered element and it's precedent
		BrocotSequence.push_back(considered_element + precedent);
		
		// adding next considered element
		BrocotSequence.push_back(considered_element);
	}

	// printing sequence..
	for (int i = 0; i < 15; ++i)
		cout << BrocotSequence[i] << " ";
}

int main()
{
	int n = 15;
	vector<int> BrocotSequence;
	
	// adding first two element
	// in the sequence
	BrocotSequence.push_back(1);
	BrocotSequence.push_back(1);
	
	SternSequenceFunc(BrocotSequence, n);

	return 0;
}