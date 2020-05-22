#include<iostream>
#include<vector>
using namespace std;
struct path {
	int a;
	int b;
	bool used;
};
vector<path> map;
int ans = 0;
int m_begin=0;
int m_end=3;
void caculate(int node,vector<path> c_map) {	
	if (node == m_end) {
		ans++;
		return;
	}
	for (int i = 0; i < c_map.size(); i++) 
	{
		vector<path> n_map = c_map;
		int a = n_map[i].a, b = n_map[i].b;		
		if (a == node) {
			n_map.erase(n_map.begin()+i);
			caculate(b, n_map);
		}
		if (b == node) {
			n_map.erase(n_map.begin() + i);
			caculate(a, n_map);
		}
	}
}
void build(int a, int b) {
	map.push_back(path{ a,b,false });
}
int main()
{
	build(0, 1);
	build(1, 2);
	build(2, 3);
	build(4, 5);
	build(5, 6);
	build(6, 7);
	build(8, 9);
	build(9, 10);
	build(1, 5);
	build(2, 6);
	build(3, 7);
	build(4, 8);
	build(5, 9);
	build(7, 10);
	caculate(m_begin, map);
	cout << ans<<endl;
	system("pause");
	return 0;
}
