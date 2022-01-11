#ifndef SRC_QUIZ_SYSTEM_H
#define SRC_QUIZ_SYSTEM_H

#include "../headers/control/control.h"
#include "../headers/ui/ui.h"

class QuizSystem
{
private:
	UI:: UI ui_;
	Control::Control control_;

public:
	QuizSystem();
	void create_new_test();
	void exit();
};


#endif //SRC_QUIZ_SYSTEM_H