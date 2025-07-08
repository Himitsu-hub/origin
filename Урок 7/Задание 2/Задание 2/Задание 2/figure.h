#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class Figure {
protected:
    std::string name;

    Figure(const std::string& fig_name);

public:
    virtual void print_info() const = 0;
    std::string get_name() const;
    virtual ~Figure();
};

#endif