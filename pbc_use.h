#pragma once
#include <pbc.h>
#include <pbc_test.h>
#include<string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

char* StrSHA256(const char* str, long long length, char* sha256);
char* FileSHA256(const char* file, char* sha256);
void setup();
struct VAR {
	string g;
	string A;
	string u1;
	string u2;
};
VAR var_back();
struct SK_user {
	element_t IK1;
	element_t IK2;
	element_t VK1;
	element_t VK2;
};
SK_user keyGen(char* a);
struct TOKEN {
	element_t ak;
	element_t o;
	element_t CID0;
	element_t CID1;
	element_t EID;
	element_t EVI;
};
TOKEN authorize(char *aaa);
struct C_TOTAL {
	string C1;
	string C2;
	string C3;
};
C_TOTAL encrypt(string _g,string _a,string _u1,string _u2,string keyword);
void trapdoor(SK_user sk);
bool test1();
struct RESULT {
	bool result;
	string C1;
	string C2;
	string C3;
};
RESULT test2();

