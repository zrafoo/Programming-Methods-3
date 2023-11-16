hash.cpp
#include "hash.h"
#include <iostream>

int easy_hash(std::string name)
{
	int hash = 0;
	for (int i = 0; i < name.length(); i++)
	{
		hash += name[i] * i * name[i];
	}
	return hash;
}

int hard_hash(std::string name)
{
	int hash = 0;
	for (int i = 0; i < name.length(); i++)
	{
		hash += name[i] * i * name[i] * i;
	}
	return hash;
}

void HashTable::add_item(ht_item a)
{
	ht_items.push_back(a);
	count += 1;
}

void ht_collision::init_ht_col(int hkey, int hcount)
{
	key = hkey;
	count = hcount;
}

void HashTable::add_item(int hkey, std::string hvalue)
{
	ht_collision first;
	first.init_ht_col(-1, -1);
	if (ht_col.size() == 0)
	{
		ht_col.push_back(first);
	}
	int flag1 = 0;
	for (int i = 0; i < this->ht_items.size(); i++)
	{
		if (hkey == this->ht_items[i].key)
		{
			flag1 = 1;
			ht_item A;
			for (int j = 0; j < ht_col.size(); j++)
			{
				int flag2 = 0;
				if (hkey == ht_col[j].key)
				{
					flag2 = 1;
					count += 1;
					A.init_ht_item((hkey + ht_col[j].count* ht_col[j].count) % 1013, hvalue); // HASH-ФУНКЦИЯ
					break;
				}
				if ((flag2 == 0)&&(j==ht_col.size()-1))
				{
					ht_collision B;
					B.init_ht_col(hkey, 1);// HASH-ФУНКЦИЯ
					ht_col.push_back(B);
					A.init_ht_item(hkey % 1013, hvalue); // HASH-ФУНКЦИЯ
				}
			}

			this->ht_items.push_back(A);
			break;
		}

	}
	if (flag1 == 0)
	{
		ht_item A;
		A.init_ht_item(hkey, hvalue);
		ht_items.push_back(A);
		count += 1;
	}
}

void HashTable::set_Size(int hsize)
{
	size = hsize;
	count = 0;
}

void HashTable::print_HashTable()
{
	std::cout << "	Hash table:	"<<'\n';
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->ht_items[i].key << " - " << this->ht_items[i].value << '\n';
	}
}

void HashTable::print_Collisions()
{
	std::cout << "	Collision table:	" << '\n';
	for (int i = 0; i < ht_col.size(); i++)
	{
		std::cout << ht_col[i].key << " - " << ht_col[i].count << '\n';
	}
}

void ht_item::init_ht_item(int hkey, std::string hvalue)
{
	key = hkey;
	value = hvalue;
}
void ht_item::clear()
{
	value.clear();
	key=0;
}

std::string findh(int hash,HashTable T)
{
	std::string ans;
	for (int i = 0; i < T.ht_items.size(); i++)
	{
		if (hash == T.ht_items[i].key)
		{
			ans = T.ht_items[i].value;
			break;
		}
	}
	return ans;
}
