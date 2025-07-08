#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class Figure {
protected:
    string name;

    Figure(const string& fig_name);

public:
    virtual void print_info() const = 0;
    string get_name() const;
    virtual ~Figure();
};

#endif
