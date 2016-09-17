#include <iostream>
#include <vector>
using namespace std;

class Component {
public:
	virtual void Traverse() = 0;
};

class Leaf: public Component {
	int value;
public:
	Leaf(int val) {
		value = val;
	}

	void Traverse() {
		cout<< value << " " ;
	}
};

class Composite: public Component {
	vector < Component * > children;
public:
	void add(Component *ele) {
		children.push_back(ele);
	}

	void Traverse() {
		for (int i = 0 ; i < children.size() ; i++ ) {
			children[i]->Traverse();
		}
	}
};

int main() {
	Composite container[4];

	for (int i = 0 ; i < 4 ; i++ ) {
		for (int j = 0 ; j < 3 ; j++) { 
			container[i].add(new Leaf(i*3+j));
			// 0 -> add ( 0, 1, 2 )
			// 1 -> add ( 3, 4, 5 )
			// 2 -> add ( 6, 7, 8 )
			// 3 -> add ( 9, 10, 11)
		}
	}

	for (int i = 1 ; i < 4 ; i++ ) {
		container[0].add(&(container[i]));
		// [0] = [0] + [1] + [2] + [3]
	}

	for (int i = 0 ; i < 4 ; i++ ) {
		container[i].Traverse();
		cout << endl;
	}
	system("PAUSE");
}










