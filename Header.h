#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
using namespace std;

#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <tuple>
#include <stdexcept>
#ifndef _WIN32
#include <locale.h>
#endif
static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";// ДЛЯ КРАСИВОГО ВЫВОДА
class Tree {
public:
	struct Leaves {
		int value;
		Leaves* Left = nullptr;
		Leaves* Right = nullptr;

		Leaves(int value, Leaves* Left, Leaves* Right): value(value), Right(Right), Left(Left) {}
	}*root;
	Tree()
	{
		Leaves * root = new Leaves(NULL, nullptr, nullptr);
		this->root = root;
	}// в нем как то мало смысла
	Tree(int val) {
		Leaves* root = new Leaves(val,nullptr, nullptr);
		this->root = root;
	}

	Tree(const Tree& copy_tree)
	{
		root = copy(copy_tree.root);
	}

	Leaves* copy(Leaves const* root)
	{
		if (!root) return nullptr;// Проверка на ненулевой указатель
		Leaves* copy_root = new Leaves(root->value, nullptr, nullptr);
		copy_root->Left = copy(root->Left);
		copy_root->Right = copy(root->Right);
		return copy_root;
	}
	
	Tree& operator=(const Tree& copy_tree)
	{
		if (!copy_tree.root)
		{
			clear(root);
			return *this;
		}
		clear(root);
		root = copy(copy_tree.root);
		return *this;
	}

	Leaves* minimum(Leaves* root) 
	{
		if (!root->Left) return root;
		return minimum(root->Left);
	}
	Leaves* erase_(Leaves* root, int value)
	{
		if (!root) return root;// есть вообще что нибудь

		if (root->value > value) root->Left = erase_(root->Left, value);
		else if (root->value < value) root->Right = erase_(root->Right, value);
		else if (root->Left && root->Right) {
			root->value = minimum(root->Right)->value;
			root->Right = erase_(root->Right, root->value);
		}
		else 
			if (root->Left) root = root->Left;
			else if (root->Right) root = root->Right;
			else root = nullptr;
	
		return root;
	}
	bool erase(int value) {
		if (contains(value)) {
			root = erase_(root, value);
			return true;
		}
		return false;
	}
	bool contains(int key)
	{
		if (contain(root, key)) return true;
		return false;
	}
	bool contain(Leaves const* root, int key)
	{
		if (root)
		{
			if (root->value == key) return true;
			if (root->value > key) return contain(root->Left, key);
			return contain(root->Right, key);
		}
		else return false;
	}
	Leaves* find(Leaves* root,int key)
	{
		if (root)
		{
			if (root->value == key) return root;
			if (root->value > key) return find(root->Left, key);
			return find(root->Right, key);
		}
		else return nullptr;
	}
	/*bool erase(int value)
	{
		temp = find(root, value);
	}*/
	void insert(int key)
	{	
		Leaves* temp = root;
		int stop = 1;
		while (stop != 0)
		{
			
			if ((root->value) > key)
			{
				if (root->Left != nullptr)
				{
					root = root->Left;
				}
				else
				{
					Leaves* node = new Leaves(key, nullptr, nullptr);
					root->Left = node;
					stop = 0;
					root = temp;

				}
			}
			else
			{
				if (root->Right != nullptr)
				{
					root = root->Right;
				}
				else
				{
					Leaves* node = new Leaves(key, nullptr, nullptr);
					root->Right = node;
					stop = 0;
					root = temp;
				}
			}
		}

	}
	// ВЫВОДЫ РАЗЛИЧНОЙ КРАСОТЫ
	void clear(Leaves* root) {
		if (!root) return;
		if (root->Left) clear(root->Left);
		if (root->Right) clear(root->Right);
		root = nullptr;
	}

	
	//void print_tree(Leaves* t, int u) {
	//	if (t == nullptr)
	//		return;  // Если дерево пустое, то отображать нечего, выходим
	//	else {  // Иначе
	//		print_tree(t->Left, ++u);  // С помощью рекурсивного посещаем левое поддерево
	//		for (int i = 0; i < u; ++i)
	//			cout << "|";
	//		cout << t->value << endl;  // И показываем элемент
	//		u--;
	//		print_tree(t->Right, ++u);  // С помощью рекурсии посещаем правое поддерево
	//	}
	//}
	//void dump3(Leaves* root, int space = 0) {
	//	if (!root)
	//		return;
	//	enum { COUNT = 2 };
	//	space += COUNT;

	//	dump3(root->Right, space);
	//	for (int i = COUNT; i < space; ++i)
	//		std::cout << "  ";
	//	std::cout << root->value << std::endl;
	//	dump3(root->Left, space);
	//}
		

	 ////////////////////////////////////////// ДАЙ БОГ stackoverflow будет жить вечно////////////////////////////////////////
	void dump1(Leaves const* node) {
#define _MAX(x, y) ((x) > (y) ? (x) : (y))
#define _MIN(x, y) ((x) < (y) ? (x) : (y))

		auto RepStr = [](std::string const& s, size_t cnt) {
			if (ptrdiff_t(cnt) < 0)
				throw std::runtime_error("RepStr: Bad value " + std::to_string(ptrdiff_t(cnt)) + "!");
			std::string r;
			for (size_t i = 0; i < cnt; ++i)
				r += s;
			return r;
		};
		std::function<std::tuple<std::vector<std::string>, size_t, size_t>(Leaves const* node, bool)> Rec;
		Rec = [&RepStr, &Rec](Leaves const* node, bool left) {
			std::vector<std::string> lines;
			if (!node)
				return std::make_tuple(lines, size_t(0), size_t(0));
			auto sval = std::to_string(node->value);
			//if (sval.size() % 2 != 1) sval += " ";
			auto resl = Rec(node->Left, true), resr = Rec(node->Right, false);
			auto const& vl = std::get<0>(resl);
			auto const& vr = std::get<0>(resr);
			auto cl = std::get<1>(resl), cr = std::get<1>(resr), lss = std::get<2>(resl), rss = std::get<2>(resr);
			size_t lv = sval.size();
			size_t ls = vl.size() > 0 ? lss : size_t(0);
			size_t rs = vr.size() > 0 ? rss : size_t(0);
			size_t lis = ls == 0 ? lv / 2 : _MAX(int(lv / 2 + 1 - (ls - cl)), 0);
			size_t ris = rs == 0 ? (lv + 1) / 2 : _MAX(int((lv + 1) / 2 - cr), (lis > 0 ? 0 : 1));
			size_t dashls = (ls == 0 ? 0 : ls - cl - 1 + lis - lv / 2), dashrs = (rs == 0 ? 0 : cr + ris - (lv + 1) / 2);
			//DEB(node->value); DEB(lv); DEB(ls); DEB(rs); DEB(cl); DEB(cr); DEB(lis); DEB(ris); DEB(dashls); DEB(dashrs); std::cout << std::endl;
			lines.push_back(
				(ls == 0 ? "" : (RepStr(" ", cl) + ch_ddia + RepStr(ch_hor, dashls))) +
				sval + (rs == 0 ? "" : (RepStr(ch_hor, dashrs) + ch_rddia + RepStr(" ", rs - cr - 1)))
			);
			//if (lines.back().size() != ls + lis + ris + rs)
			//    throw std::runtime_error("Dump: First line wrong size, got " + std::to_string(lines.back().size()) + ", expected " + std::to_string(ls + lis + ris + rs));
			for (size_t i = 0; i < _MAX(vl.size(), vr.size()); ++i) {
				std::string sl = RepStr(" ", ls), sr = RepStr(" ", rs);
				if (i < vl.size()) sl = vl[i];
				if (i < vr.size()) sr = vr[i];
				sl = sl + RepStr(" ", lis);
				sr = RepStr(" ", ris) + sr;
				lines.push_back(sl + sr);
			}
			return std::make_tuple(lines, (left || ls + lis == 0 || lv % 2 == 1) ? ls + lis : ls + lis - 1, ls + lis + ris + rs);
		};
		auto v = std::get<0>(Rec(node, true));
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << std::endl;

#undef _MAX
#undef _MIN
	}

	void print()
	{
		dump1(root);
	}

	~Tree()
	{

		delete_tree(root);

	}

	void delete_tree(Leaves* root)
	{
		if (root)
		{
			delete_tree(root->Left);
			delete_tree(root->Right);
			delete root;
		}
	}

};
size_t lcg() // Генератор псевдослучайных
{
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

