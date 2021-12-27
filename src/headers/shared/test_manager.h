#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_TEST_MANAGER_H
#define SRC_TEST_MANAGER_H

#import test_data.h

class TestManager
{
private:
	TestData test_data;

public:
	void open_test();
	void load_test_data_to_open();
	TestData create_new_test();
	TestManager(TestData test_data);
};

#endif //SRC_TEST_MANAGER_H
