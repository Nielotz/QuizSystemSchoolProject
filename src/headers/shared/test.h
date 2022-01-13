#ifndef SRC_TEST_H
#define SRC_TEST_H

#include "../test_data/test_data.h"

class Test
{
private:
	TestData::TestData test_data_;
	void take();
	void review();
	void delet();
	void edit();

public:
	void open(TestData::TestData test_data, Control::TestMenu::OptionType open_type)
	{

	}

};

#endif //SRC_TEST_H
