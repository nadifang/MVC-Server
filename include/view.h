#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "modelAndView.h"

using namespace std;

class View {
public:
	View()  = default;
	~View() = default;
	static string render(ModelAndView &);
};

#endif // VIEW_H
