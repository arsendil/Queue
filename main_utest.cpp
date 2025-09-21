#include <gtest/gtest.h>
#include "headers/Queue.hpp"

// === Constructor / empty / size tests ===
TEST(QueueTest, EmptyConstructor) {
    Queue<int> q;
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(q.size(), 0);
}

// === Push / top / pop tests ===
TEST(QueueTest, PushTopPop) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    EXPECT_FALSE(q.empty());
    EXPECT_EQ(q.size(), 3u);
    EXPECT_EQ(q.top(), 1);

    q.pop();
    EXPECT_EQ(q.top(), 2);
    q.pop();
    EXPECT_EQ(q.top(), 3);
    q.pop();
    EXPECT_TRUE(q.empty());
}

// === Copy constructor / assignment operator tests ===
TEST(QueueTest, CopyConstructor) {
    Queue<int> q1;
    q1.push(5);
    q1.push(10);

    Queue<int> q2(q1);
    EXPECT_EQ(q1.size(), q2.size());
    EXPECT_EQ(q1.top(), q2.top());

    q2.pop();
    EXPECT_NE(q1.top(), q2.top()); // q1 untouched
}

TEST(QueueTest, AssignmentOperator) {
    Queue<int> q1;
    q1.push(7);
    q1.push(14);

    Queue<int> q2;
    q2 = q1;
    EXPECT_EQ(q1.size(), q2.size());
    EXPECT_EQ(q1.top(), q2.top());

    q2.pop();
    EXPECT_NE(q1.top(), q2.top());
}

// === Comparison operators ===
TEST(QueueCompareTest, Equal) {
    Queue<int> q1;
    Queue<int> q2;

    q1.push(1);
    q1.push(2);

    q2.push(1);
    q2.push(2);

    EXPECT_TRUE(q1 == q2);
    q2.push(3);
    EXPECT_FALSE(q1 == q2);
}

TEST(QueueCompareTest, LessGreater) {
    Queue<int> q1;
    Queue<int> q2;

    q1.push(1);
    q1.push(2);

    q2.push(1);
    q2.push(3);

    EXPECT_TRUE(q1 < q2);
    EXPECT_TRUE(q2 > q1);
}

TEST(QueueCompareTest, LessEqualGreaterEqual) {
    Queue<int> q1;
    Queue<int> q2;

    q1.push(1);
    q1.push(2);

    q2.push(1);
    q2.push(2);

    EXPECT_TRUE(q1 <= q2);
    EXPECT_TRUE(q1 >= q2);

    q2.push(3);
    EXPECT_TRUE(q1 <= q2);
    EXPECT_FALSE(q1 >= q2);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
