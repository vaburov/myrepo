#include <iostream> 
#include <vector> 

using namespace std;

const unsigned N = 10; // number of words in array
const unsigned K = 10; // maximum number of letters in a word
const unsigned A = 0;  // first alphabet letter
const unsigned Z = 25; // last alphabet letter

int main()
{
	string input[N] = {"Valentin","Andrey", "Alexey", "Alexandr", "Vladimir", "Anna", "Maria", "Marina", "Marfa", "Boris"};
	string output[N];
	vector<unsigned> wt;
	unsigned lt[K][Z+1];

	cout << "Input array:" << endl;
	for(unsigned i=0; i<=N; i++) {
		cout << input[i] << " ";
	}
	cout << endl;

	//initialization
	wt.resize(N);
	cout << "initialized" << endl;
	for(unsigned k=0; k<K; k++) {
		for(unsigned l=A; l<=Z; l++) {
			lt[k][l]=0;
		}
	}

	// first sort iteration by first letter
	for(unsigned i=0; i<N; i++) {
		unsigned a = input[i][0]-'A';
		//cout << "DBG: a=" << a << endl;
		wt[i] = lt[0][a];
		lt[0][a] = i;
	}

	cout << "wt:" << endl;
	for(unsigned i=0; i<N; i++) {
		cout << wt[i] << " ";
	}
	cout << endl << "lt:" << endl;
	for(unsigned i=A; i<=Z; i++) {
		cout << (char)('A'+i) << " ";
	}
	cout << endl;
	for(unsigned i=A; i<=Z; i++) {
		cout << lt[0][i] << " ";
	}
	cout << endl;

	// fill output with sorted data
	unsigned i=0;
	for(unsigned l=A; l<=Z; l++) {
		unsigned x = lt[0][l];
		cout << "DBG: x=" << x << endl;
		do {
			output[i] = input[x];
			cout << "output"<<i<<"=input"<<x<<"("<<input[x]<<")"<<endl;
			x = wt[x];
			i++;
		} while(x);
	}

	cout << "Output array:" << endl;
	for(unsigned i=0; i<=N; i++) {
		cout << output[i] << " ";
	}
	cout << endl;

	return 0;
}
