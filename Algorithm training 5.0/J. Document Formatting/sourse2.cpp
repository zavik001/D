#include <iostream>

#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

enum types { word, embedded, surrounded, floating };


class object {
public:
	object() {

	}
	object(int x,int y,int w,int h, types type) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		this->type = type;
	}
	int x =0, y = 0;
	int w = 0, h = 0;
	types type;

 };
class dword {
public:
	static vector<vector<int>> cur_line;
	static vector<vector<int>> sur_pic;

	static void add_word(object *word) {
		int k = 1;
		if (tap == 0) {
			k = 0;
		}
		if (cur_line.size() == 0) {
			dword::new_line();
			k = 0;
		}
		if (pre_object != nullptr and pre_object->type == surrounded) {
			k = 0;
		}
		pre_object = word;

		for (int i = cur_frag; ; i++) {
			if (cur_line.size() == 0) {
				dword::new_line();
				k = 0;
			}

			if (c * k + x + word->w <= cur_line[i][1]) {
				//cout<<"word  " << x + c * k << " " << y << endl;
				x += word->w + c*k;
				//cout << k << endl;
				break;
			}
			else {
				k = 0;
				if (i < cur_line.size() - 1) {
					x = cur_line[i + 1][0];
					cur_frag++;
				}
				else {
					cur_line.clear();
					cur_frag = 0;
					i = -1;
				}
			}
		}
		tap = 1;
	}
	
	static void add_em(object *em) {
		int k = 1;
		if (cur_line.size() == 0) {
			dword::new_line();
			k = 0;
		}
		if (tap == 0) {
			k = 0;
		}
		if (pre_object != nullptr and pre_object->type == surrounded) {
			k = 0;
		}
		for (int i = cur_frag; ; i++) {

			if (cur_line.size() == 0) {
				dword::new_line();
				k = 0;
			}

			if (c * k + x + em->w <= cur_line[i][1]) {
				cout << x + c * k << " " << y << endl;
				x += em->w + c * k;
				if (em->h > h + t) {
					t += (em->h - h -t);
				}
				break;
			}
			else {
				k = 0;
				if (i < cur_line.size() - 1) {
					x = cur_line[i + 1][0];
					cur_frag++;
				}
				else {
					cur_line.clear();
					cur_frag = 0;
					i = -1;
				}
			}
		}
		pre_object = em;
		tap = 1;
	}

	static void add_sur(object *sur) {
		if (cur_line.size() == 0) {
			dword::new_line();
		}
		tap = 0;
		for (int i = cur_frag; ; i++) {
			if (cur_line.size() == 0) {
				dword::new_line();
			}
			if ( x + sur->w <= cur_line[i][1]) {
				sur_pic.push_back(vector<int> {x, y, x + sur->w, y + sur->h});
				cout << x << " "<<y << endl;
				x += sur->w;
				
				break;
			}
			else {

				if (i < cur_line.size() - 1) {
					x = cur_line[i + 1][0];
					cur_frag++;
				}
				else {
					cur_line.clear();
					cur_frag = 0;
					i = -1;
				}
			}
		}
		pre_object = sur;
	
	}

	static void add_fl(object *fl) {
		if (cur_line.size() == 0) {
			dword::new_line();
		}
		int dx = fl->x;
		int dy = fl->y;
		int t1 = y;
		int t2 = x;
		if (pre_object != nullptr and  pre_object->type == floating) {
			y = pre_object->y;
			x = pre_object->x;
		}

		if (x + dx < 0) {
			cout << 0 << " " << y + dy << endl;
			fl->x = fl->w;
		}
		else {
			if (x + dx + fl->w > w) {
				cout << w - fl->w << " " << y + dy << endl;
				fl->x = w ;
			}
			else {
				cout << x + dx << " " << y + dy << endl;
				fl->x = x + dx + fl->w;
			}
		}
		fl->y = dy + y;
		pre_object = fl;
		y = t1;
		x = t2;
	}

	static void new_par() {
		cur_line.clear();
		cur_frag = 0;
		pre_object = nullptr;
		y += h + t;
		for (int i = 0; i < sur_pic.size(); i++) {
			if (sur_pic[i][3] > y) {
				y = sur_pic[i][3];
			}
		}
		y -= h;
		t = 0;
	}

	static void new_line() {
		int s = 0;
		int f = w;
		x = 0;
		y += h + t;
		t = 0;
		sort(sur_pic.begin(), sur_pic.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
		
		for (int i = 0; i < sur_pic.size(); i++) {
			
			if (sur_pic[i][3] > y) {
				
				cur_line.push_back(vector<int> {s, sur_pic[i][0]});
				s = sur_pic[i][2];
			}
			
		}
		if (s < f) {
			cur_line.push_back(vector<int> {s, f});
		}
		
	}
	static int w, h, c;
	static int x, y, t;
	static object *pre_object;
	static int cur_frag;
	static int tap;
};
int dword::c = 0;
int dword::w = 0;
int dword::h = 0;
int dword::x = 0;
int dword::y = 0;
int dword::t = 0;
int dword::tap = 1;
object *dword::pre_object = NULL;
int dword::cur_frag = 0;
vector<vector<int>> dword::cur_line;
vector<vector<int>> dword::sur_pic;

int main() {
	int w = 120;
	int h = 10;
	int c = 8;

	
	ifstream f("input.txt");
	string a[1000];
	int i = 0;
	if (f.is_open()) {
		f >> w >> h >> c;
		dword::w = w;
		dword::h = h;
		dword::c = c;
		dword::y = -h;

		while (getline(f,a[i])) {
			i++;
		}
	}
	int pi = 0, in = 0, jk = 0;
	for (int j = 1; j < i; j++) {
		bool p = false;
			for (int q = 0; q < a[j].size(); q++) {
				if (a[j][q] == '(') {
					p = true;
					
				}
				if (a[j][q] == ')') {
					p = false;
				}
			}
			if (p) {
				for (int q = j + 1; q < i and p; q++) {
					a[j] += ' ';
					for (int u = 0; u < a[q].size(); u++) {
						if (a[q][u] == ')') {
							pi = q - j - 1;
							if (pi >= 0) {
								in = u + 2;
							}
							a[j] += a[q][u];
							p = false;
							break;
						}
						
						a[j] += a[q][u];
					
					}
					
				}
		}

		
		if (a[j].size() == 0) {
			dword::new_par();
		}
		int l = 0;
		int dx = 0;
		int dy = 0;
		for (int k = jk; k < a[j].size(); k++) {

			if (a[j][k] == '(') {
				object *ob = new object();
				for (int z = k + 6; z < a[j].size(); z++) {
					
					if (a[j][z] == 'l' and a[j][z+1] == 'a') {
						z += 7;
						//cout << k << " | ";
						if (a[j][z] == 'e') {
							ob->type = embedded;
							//cout << ob->type;
						}
						if (a[j][z] == 'f') {
							ob->type = floating;
							//cout << ob->type;
						}
						if (a[j][z] == 's') {
							ob->type = surrounded;
							
						}
						 
					}
					if (a[j][z] == 'd' and a[j][z + 1] == 'y') {
						z += 3;
						int t = 1;
						if (a[j][z] == '-') {
							t = -1;
							z++;
						}
						while (true) {
							dy = dy * 10 + a[j][z] - '0';
							z++;
							if (a[j][z] == ' ' or a[j][z] == ')') {
								break;
							}
						}
						dy *= t;
					}
					if (a[j][z] == 'd' and a[j][z + 1] == 'x') {
						z += 3;
						int t = 1;
						if (a[j][z] == '-') {
							t = -1;
							z++;
						}
						while (true) {
							dx = dx * 10 + a[j][z] - '0';
							z++;
							if (a[j][z] == ' ' or a[j][z] == ')') {
								break;
							}
						}
						dx *= t;
					}
					if (a[j][z] == 'w' and a[j][z+1] == 'i') {

						z += 6;

						while (true) {
							ob->w = ob->w * 10 + a[j][z] - '0';
							z++;
							if (a[j][z] == ' ' or a[j][z] == ')') {
								break;
							}
						}

					}
					if (a[j][z] == 'h' and a[j][z + 1] == 'e') {
						z += 7;
						while (true) {
							ob->h = ob->h * 10 + a[j][z] - '0';
							z++;
							if (a[j][z] == ' ' or a[j][z] == ')') {
								break;
							}
						}
					}
					k = z +1;
					if (a[j][z] == ')') {
						break;
					}
					
				}
				ob->x = dx;
				ob->y = dy;
				if (ob->type == surrounded) {
					dword::add_sur(ob);
				}
				if (ob->type == embedded) {
					dword::add_em(ob);
				}
				if (ob->type == floating) {
					dword::add_fl(ob);
				}
				
				
			}
			else {
				if (a[j][k] == ' ' or k == a[j].size() -1) {
					if (a[j][k] == ' ' and k>0 and  a[j][k - 1] == ' ') {
						l = 0;
						continue;
					}
					if (k == a[j].size() - 1 and a[j][k]!= ' ')
						l++;
					dword::add_word(new object(0, 0, l * c,0, word));
					object *ob = new object(0, 0, l * c, 0, word);
					
					l = 0;
				}
				else {
					l++;
				}
			}
		}
		j += pi;
		jk = in;
		pi = 0;
		in = 0;
	}

	return 0;
}