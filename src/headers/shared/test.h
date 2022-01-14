#ifndef SRC_TEST_TEST_H
#define SRC_TEST_TEST_H

#include "../test_data/test_data.h"
#include "../control/control.h"

class Test
{
private:
	TestData::TestData test_data_;
	void take();
	void review();
	void delete_();
	void edit();

public:
	void open(TestData::TestData test_data, Control::TestMenu::OptionType open_type)
	{

	}

};

#endif //SRC_TEST_TEST_H
