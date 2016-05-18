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

TEST(GoalUndoTest, MultiOperationsInsideSingleGoal)
{
  GoalUndo gundo;
  gundo.addOperation("fFirst", "MyTask");

  ASSERT_EQ("MyTask", gundo.getOperations());
}

TEST(GoalUndoTest, RedundantOperation)
{
  GoalUndo gundo;
  gundo.addOperation("AnyIoperation");
  gundo.undoOperation("AnyIoperation");
  ASSERT_EQ("", gundo.getOperations());
}
TEST(GoalUndoTest, MultiOpInsideSingleGoal)
{
  GoalUndo gundo;
  gundo.addOperation("fFirst", "MyTask");
  gundo.addOperation("MyTask11");
  ASSERT_EQ("MyTask MyTask11", gundo.getOperations());
}


TEST(GoalUndoTest, UndoIdenticalNames)
{
  GoalUndo gundo;
  gundo.addOperation("AnyIoperation");

  ASSERT_EQ("AnyIoperation", gundo.getGoal());
  ASSERT_EQ("AnyIoperation", gundo.getOperations());
}
TEST(GoalUndoTest, AddingSingleOperation)
{
  GoalUndo gundo;

  gundo.addOperation("RandomOperation");

  ASSERT_EQ("RandomOperation", gundo.getOperations());
}

TEST(GoalUndoTest, CheckforNull)
{
  GoalUndo gundo;
  ASSERT_EQ("", gundo.getOperations());
}


TEST(GoalUndoTest, NotEmpty)
{
  GoalUndo gundo;
  gundo.addOperation("arithmetic", "add operation");
  ASSERT_EQ("arithmetic", gundo.getGoal());
}

TEST(GoalUndoTest, ErrorOp)
{
  GoalUndo gundo;
  gundo.undoOperation("Arithmetic");
  ASSERT_EQ("", gundo.getOperations());
}

TEST(GoalUndoTest, EmptyNameforAdd)
{
  GoalUndo gundo;
  gundo.addOperation("", "");

  ASSERT_EQ("", gundo.getGoal());
}

/*
TEST(GoalUndoTest, AddingSubCategories)
{
  GoalUndo gundo;
  gundo.addOperation("Arts", "Music");
  gundo.addOperation("Psychology");
  gundo.addOperation("Philanthrophy");
  gundo.addOperation("Physiology");
  gundo.addOperation("Science", "Physics");
  gundo.addOperation("Chemistry");
  gundo.addOperation(" MolecularBio");

  ASSERT_EQ("Science", gundo.getGoal());
  ASSERT_EQ("Physics Chemistry MolecularBio", gundo.getOperations());
  gundo.undoGoal();

  ASSERT_EQ("Arts", gundo.getGoal());
  ASSERT_EQ("Music Pyschology Philathrophy Physiology", gundo.getOperations());
  gundo.undoGoal();


  gundo.undoGoal();
  ASSERT_EQ("", gundo.getGoal());
  gundo.undoGoal();
  ASSERT_EQ("", gundo.getGoal());
  ASSERT_EQ("", gundo.getOperations());
}*/
