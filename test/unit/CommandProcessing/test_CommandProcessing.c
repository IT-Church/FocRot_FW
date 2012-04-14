#include "unity.h"
#include "CommandProcessing.h"
#include <string.h>

void setUp(){}
void tearDown(){}

void test_InterpretCommandString_should_set_command_to_HELLO_CMD_for_string_HELLO()
{
	char * inputString = "HELLO";
	focusingRotatorCommand cmd;
	char returnedError[100] = {0x00};
	InterpretCommandString(inputString, 5, &cmd, returnedError);
	TEST_ASSERT_EQUAL(CMD_HELLO, cmd.command);
	TEST_ASSERT_TRUE(strlen(returnedError) == 0);
}

void test_InterpretCommandString_should_set_command_to_HALT_CMD_for_string_HALT()
{
	char * inputString = "HALT";
	focusingRotatorCommand cmd;
	char returnedError[100] = {0x00};
	InterpretCommandString(inputString, 4, &cmd, returnedError);
	TEST_ASSERT_EQUAL(CMD_HALT, cmd.command);
	TEST_ASSERT_TRUE(strlen(returnedError) == 0);
}

