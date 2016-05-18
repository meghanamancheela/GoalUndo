/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


// Test case for undoGoal()
// Testing for the case where, there are no goals.
TEST(GoalUndoTest, undoGoal_NoGoals)
{
  GoalUndo testGoal;
  testGoal.undoGoal();

  ASSERT_EQ("",testGoal.getGoal());
}

// Test for undogoal()
// Testing for the case where, there are goals.
TEST(GoalUndoTest, undoGoal_MoreThanOneGoal)
{
  GoalUndo testGoal;
  testGoal.addOperation("FirstGoal", "DrawLine");
  testGoal.addOperation("SecondGoal", "Rotate_Line");
  testGoal.addOperation("ThirdGoal", "DrawSquare");
  testGoal.undoGoal();

  ASSERT_EQ("SecondGoal",testGoal.getGoal());
}

// Test for undoOperation()
// Testing for the case where there is only one operation in the goal.
TEST(GoalUndoTest, undoOperation_OnlySingleOperation)
{
  GoalUndo testGoal;
  testGoal.addOperation("MyGoal","DrawTriangle");
  testGoal.undoOperation();

  ASSERT_EQ("",testGoal.getGoal());
}

// Test for undoOperation()
// Testing for the case where, there are is no existing goal.
TEST(GoalUndoTest, undoOperation_NoGoals)
{
  GoalUndo testGoal;
  testGoal.undoOperation();

  ASSERT_EQ("",testGoal.getGoal());
}

// Test for undoOperation()
// Testing for the case where, there are more than one operations in the goal
TEST(GoalUndoTest, undoOperation_MoreThanOneGoal)
{
  GoalUndo testGoal;
  testGoal.addOperation("MyGoal","DrawTriangle");
	testGoal.addOperation("DrawRectangle");
	testGoal.addOperation("DrawCircle");
  testGoal.undoOperation();

  ASSERT_EQ("DrawTriangle DrawRectangle",testGoal.getOperations());
}
