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

// Test case for undogoal()
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

// Test case for undoOperation()
// Testing for the case where there is only one operation in the goal.
TEST(GoalUndoTest, undoOperation_OnlySingleOperation)
{
  GoalUndo testGoal;
  testGoal.addOperation("MyGoal","DrawTriangle");
  testGoal.undoOperation();

  ASSERT_EQ("",testGoal.getGoal());
}

// Test case for undoOperation()
// Testing for the case where, there are is no existing goal.
TEST(GoalUndoTest, undoOperation_NoGoals)
{
  GoalUndo testGoal;
  testGoal.undoOperation();

  ASSERT_EQ("",testGoal.getGoal());
}

// Test case for undoOperation()
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


// Test case for getGoal()
// Testing for the case where, there are no goals.
TEST(GoalUndoTest, getGoal_NoGoals)
{
	GoalUndo testGoal;
	ASSERT_EQ("",testGoal.getGoal());
}

// Test case for getGoal()
// Testing for the case where, there are goals;
TEST(GoalUndoTest, getGoal_ThereAreGoals)
{
	GoalUndo testGoal;
	testGoal.addOperation("FirstGoal" , "DrawLine");
	ASSERT_EQ("FirstGoal" , testGoal.getGoal());
}


// Test case for getOperations()
// Testing for the case where, there is single operation
TEST(GoalUndoTest, getOperations_SingleOperation)
{
  GoalUndo testGoal;
  testGoal.addOperation("firstgoal", "rotateline");
  ASSERT_EQ("rotateline",testGoal.getOperations());
}


// Test case for getOperations()
// Testing the condition where there are multiple operations in in single goal.
TEST(GoalUndoTest, getOperations_MoreThanOneOperationInSingleGoal)
{
  GoalUndo testGoal;
  testGoal.addOperation("Mygoal", "DrawCircle");
  testGoal.addOperation("DrawSquare");
  testGoal.addOperation("DrawTriangle");
  testGoal.addOperation("DrawLine");
  ASSERT_EQ("DrawCircle DrawSquare DrawTriangle DrawLine",
	testGoal.getOperations());
}

// Test case for getOperations()
// Testing the condition, that when there are multiple goals, the method returns
// the operations of the recently added goal.
TEST(GoalUndoTest, getOperations_MoreThanOneGoal)
{
  GoalUndo testGoal;
  testGoal.addOperation("Mygoal", "DrawCircle");
  testGoal.addOperation("DrawSquare");
  testGoal.addOperation("DrawTriangle");
  testGoal.addOperation("DrawLine");

	testGoal.addOperation("SecondGoal", "DrawLine");
	testGoal.addOperation("DrawTriangle");
  ASSERT_EQ("DrawLine DrawTriangle",testGoal.getOperations());
}



// Test case for addOperation(newGoal,newOp)
// Test for method with valid input
TEST(GoalUndoTest, addOperation_AddingFirstGoalwithOperatoin)
{
  GoalUndo testGoal;
  testGoal.addOperation("firstgoal", "rotateline");
  ASSERT_EQ("rotateline",testGoal.getOperations());
}

// Test case for addOperation(newGoal,newOp)
// Testing for the condition where, operation is an empty string.
TEST(GoalUndoTest, addOperation_OperationIsEmptyString)
{
  GoalUndo testGoal;
  testGoal.addOperation("firstgoal" , "");
  ASSERT_EQ("" , testGoal.getOperations());
}

// Test case for addOperation(newGoal,newOp)
// Testing for the condition where, goal is an empty string.
TEST(GoalUndoTest, addOperation_GoalIsEmptyString)
{
  GoalUndo testGoal;
  testGoal.addOperation("" , "DrawCircle");
  ASSERT_EQ("" , testGoal.getGoal());
}

// Test case for addOperation(newGoal,newOp)
// Testing for the condition where, both goal and operations are empty strings.
TEST(GoalUndoTest, addOperation_InvalidInput)
{
  GoalUndo testGoal;
  testGoal.addOperation("" , "");
  ASSERT_EQ("" , testGoal.getGoal());
}


// Test case for addOperation(newOp)
// Testing for the condition where, new operations are added to the recently
// added goal.
TEST(GoalUndoTest, addOperation_AddingOperationsToRecentlyAddedGoal)
{
  GoalUndo testGoal;
  testGoal.addOperation("FirstGoal" , "RotateLine");
	testGoal.addOperation("DrawCircle");

	testGoal.addOperation("SecondGoal" , "DrawSquare");
	testGoal.addOperation("DrawSquare");
	testGoal.addOperation("DrawTriangle");
  ASSERT_EQ("DrawSquare DrawSquare DrawTriangle" , testGoal.getOperations());
}


// Test case for addOperation(newOp)
// Testing for the condition where, newOP is a non empty string. 
TEST(GoalUndoTest, addOperation_EmptyString)
{
  GoalUndo testGoal;
  testGoal.addOperation("FirstGoal" , "RotateLine");
	testGoal.addOperation("DrawCircle");

	testGoal.addOperation("SecondGoal" , "DrawSquare");
	testGoal.addOperation("");
	testGoal.addOperation("DrawTriangle");
  ASSERT_EQ("DrawSquare DrawTriangle" , testGoal.getOperations());
}
