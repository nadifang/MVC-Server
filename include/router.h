#ifndef ROUTER_H
#define ROUTER_H
#include "routerFramework.h"

class MyRouter : public Router {
public:
	void init() override;
};

extern MyRouter myRouter;

#endif // ROUTER_H
