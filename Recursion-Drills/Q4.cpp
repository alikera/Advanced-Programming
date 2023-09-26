#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convertToString(char data[]) {
	string str = "";
	for (int i = 0; i < sizeof(data); i++)
		str = str + data[i];
	return str;
}

void combination(string allowedLetters, int sizeOfAllowed, int lenPass,
	int index, char data[], int current, vector <string> &vecCombination)
{
	if (index == lenPass)
	{
		vecCombination.push_back(convertToString(data));
		return;
	}
	if (current >= sizeOfAllowed)
		return;

	data[index] = allowedLetters[current];
	combination(allowedLetters, sizeOfAllowed, lenPass, index + 1, data, current + 1, vecCombination);
	combination(allowedLetters, sizeOfAllowed, lenPass, index, data, current + 1, vecCombination);
}

void permute(string password, int from, int to, vector<string> &possiblePassword)
{
	if (from == to) {
		possiblePassword.push_back(password);
		return;
	}
	else
	{
		for (int i = from; i <= to; i++)
		{
			swap(password[from], password[i]);
			permute(password, from + 1, to, possiblePassword);
			swap(password[from], password[i]);
		}
	}
}

unsigned long int generatePasswordHash(string password) {
	return hash<string>() (password);
}

void solve(long int hash, vector<string> possiblePassword) {
	for (int i = 0; i<possiblePassword.size(); i++) {
		if (generatePasswordHash(possiblePassword[i]) == hash) {
			cout << possiblePassword[i];
			return;
		}
	}
	cout << "NOT_FOUND";
}

int main()
{
	int lenPass;
	cin >> lenPass;

	string allowedLetter;
	cin >> allowedLetter;

	string allowedLetters="";
	for(int k=0;k<2*(allowedLetter.size());k++)
		allowedLetters=allowedLetters + allowedLetter[k % allowedLetter.size()];

	unsigned long int hash;
	cin >> hash;

	char data[100];
	vector <string> vecCombination;

	vector <string> possiblePassword;

	int sizeOfAllowed = allowedLetters.size();
	combination(allowedLetters, sizeOfAllowed, lenPass, 0, data, 0, vecCombination);

	for (int i = 0; i<vecCombination.size(); i++)
		permute(vecCombination[i], 0, lenPass - 1, possiblePassword);

	solve(hash, possiblePassword);
	return 0;
}
