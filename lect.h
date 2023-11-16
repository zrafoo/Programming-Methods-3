#pragma once

#include <string>
#include "lect.h"
#include <vector>

struct ht_item
{
	int key;
	std::string value;
	void init_ht_item(int hkey,std::string hvalue);
	void clear();
};

struct ht_collision
{
	int key;
	int count;
	void init_ht_col(int hkey, int hcount);
};

struct HashTable
{
	int size;
	int count;
	std::vector<ht_item> ht_items;
	std::vector<ht_collision> ht_col;
	void set_Size(int hsize);
	void add_item(ht_item a);
	void add_item(int hkey, std::string hvalue);
	void print_HashTable();
	void print_Collisions();
};

int easy_hash(std::string name);
int hard_hash(std::string name);

std::string findh(int hash, HashTable T);
