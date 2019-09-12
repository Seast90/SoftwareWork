#include "People.h"
void People::ClearPunctuation() {
	wstring str = address, s=L"";
	int len = str.size();
	for (int i = 0; i < len; i++)
		if (str[i] != ',' && str[i] != L'��' && str[i] != '.' && str[i] != L'��')
			s = s + str[i];
	address = s;
}
void People::GetNumber() {
	wstring str = Ori;
	int len = str.size();
	for (int pos = 0; pos < len; pos++) {
		if (str[pos] < '0' && str[pos] > '9') continue;
		int cnt = 0;
		PhoneNumber = 0;
		for (int _pos = pos; _pos < len&&str[_pos] >= '0'&&str[_pos] <= '9'; _pos++) {
			cnt++;
			PhoneNumber = 10 * PhoneNumber + str[_pos] - '0';
		}
		if (cnt == 11) {
			Ori = Ori.substr(0, pos) + Ori.substr(pos + 11, len - pos - 10);
			break;
		}
	}
}
void People::GetName() {
	wstring str = Ori;
	int pos = 0, len = str.size();
	while (pos < len && str[pos] != L',' && str[pos] != '��')
		pos++;
	name = str.substr(0, pos);
	address = str.substr(pos, len - pos + 1);
}
void People::GetAddress() {
	one = Address(address);
	one.Classification();
}

void People::Print() {
	wcout << name<<"\n";
	cout << PhoneNumber << "\n";
	wcout << address <<"\n";
	system("pause");
}

void People::doit() {
	GetNumber();
	GetName();
	ClearPunctuation();
}