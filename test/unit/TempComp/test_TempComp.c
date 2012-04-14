#include "unity.h"
#include "TempComp.h"
#include "mock_NVM.h"
#include "mock_Tick.h"
#include "mock_Stepper.h"

void tearDown()
{
	
}

void setUp()
{
}

void test_InitTempComp_should_set_reset_required_to_true()
{
	focuser myFoc;
	memset(&myFoc, 0x00, sizeof(myFoc));

	TEST_ASSERT_NOT_EQUAL(1U, myFoc.tempCompInfoStr.ResetRequired);
	InitTempComp(&myFoc);
	TEST_ASSERT_EQUAL(1U, myFoc.tempCompInfoStr.ResetRequired);
}

// void test_calculateDeltaSteps_should_return_expected_value()
// {
// 	focuser myFoc;
// 	memset(&myFoc, 0x00, sizeof(myFoc));
// 	myFoc.statusStr.CurrentTemp = 104;
// 	myFoc.statusStr.CurrentPosition = 5215;
// 	myFoc.tempCompInfoStr.TempCompMode = 'A';
// 	myFoc.tempCompInfoStr.LastTempCompStartTemp = 243;
// 	myFoc.tempCompInfoStr.LastTempCompStartPos = 5000;
// 	myFoc.tempCompInfoStr.TempCoeffs[0] = -45;
// 	myFoc.motionInfoStr.MaxPosition = 10000;

// 	int x = calculateDeltaSteps(&myFoc);
// 	TEST_ASSERT_EQUAL(410, x);
// }

void test_DoTempComp_should_do_nothing_it_tempCompEnabled_is_false()
{
	focuser myFoc;
	DoTempComp(&myFoc);
	
}

