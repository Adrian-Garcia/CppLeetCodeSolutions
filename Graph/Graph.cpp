#include <iostream>
#include <vector>

using namespace std;

struct GraphNode {
	int val;
	bool check = false;
	vector<GraphNode*> nodes;
	GraphNode(int x) : val(x), nodes(0, NULL) {}
};

int main() {

	return 0;
}