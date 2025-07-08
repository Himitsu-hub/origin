#include "figure_error.h"

FigureError::FigureError(const std::string& what_arg)
    : std::domain_error(what_arg) {}