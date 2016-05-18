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

TEST(GoalUndoTest, AddingAdjacentsEntries)
{
  GoalUndo gundo;
  gundo.addOperation("Movies", "Genre");
  gundo.addOperation("Comedy");
  gundo.addOperation("Adventure");
  gundo.addOperation("Theater", "Musical");
  gundo.addOperation("Dramatics");
  gundo.addOperation("Documentary");

  ASSERT_EQ("Theater", gundo.getGoal());
  ASSERT_EQ("Musical Dramatics Documentary", gundo.getOperations());
  gundo.undoGoal();

  ASSERT_EQ("Movies", gundo.getGoal());
  ASSERT_EQ("Genre Comedy Adventure", gundo.getOperations());
  gundo.undoGoal();

  gundo.undoGoal();
  ASSERT_EQ("", gundo.getGoal());
  gundo.undoGoal();
  ASSERT_EQ("", gundo.getGoal());
  ASSERT_EQ("", gundo.getOperations());
}
