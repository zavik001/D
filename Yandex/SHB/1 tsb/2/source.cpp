#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct list 
{
	char c;
	list *next = NULL;
	list *back;
	list(char a, list *b) 
   {
		c = a;
		back = b;
	}
	list *add(char a) 
   {
		list *p = new list(a, this);
		p->next = this->next;
		this->next = p;
		if (p->next != NULL) 
      {
			p->next->back = p;
		}
		return p;
	}
	list *del() 
   {
		list *p = this->back;
		p->next = this->next;
		if (this->next != NULL) 
      {
			this->next->back = p;
		}
		return p;
	}
};


int main() 
{

	string inputString, commandString;
	cin >> inputString >> commandString;
	list *l = new list('0', NULL);
	l->next = new list('0', NULL);
	vector<string> finish(inputString.size());
	list *cur = l;
	for (char command : commandString) 
   {
		switch (command) 
      {
			case '<':
				cur = cur->del();
				break;
			case '>':
				if (cur->next->c != '0') 
            {
					cur = cur->next;
				}
				break;
			default:
				cur = cur->add(command);
				break;
		}
	}
	l = l->next;
	if (inputString.compare(string(1, l->c)) == 0)
   {
		cout << "Yes";
	}
	else 
   {
		cout << "No";
	}
	return 0;
}
