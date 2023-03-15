#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using std::string;

struct print_opt {
    bool l;
    bool o;
    bool r;
    bool i;
};

bool search_within_string(
    const string *const str1,
    const string *const str2,
    size_t *const pos
);
bool search_within_string(
    const string *const str1,
    const string *const str2
);
void option_switch(
    string *const str,
    print_opt *const opt
);
void read_file(
    const string *const str1,
    const string *const str2,
    const print_opt *const opt
);

// -olori following man_grep_plain_ASCII.txt

