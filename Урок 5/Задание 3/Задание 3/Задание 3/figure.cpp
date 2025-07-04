#include "figure.h"
#include <iostream>
using namespace std;

Figure::Figure(const string& fig_name) : name(fig_name) {}

string Figure::get_name() const { return name; }

Figure::~Figure() {}