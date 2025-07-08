#include "figure.h"

Figure::Figure(const std::string& fig_name) : name(fig_name) {}

std::string Figure::get_name() const { return name; }

Figure::~Figure() {}