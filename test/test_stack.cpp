// тесты для стека

#include "stack.h"

#include <gtest.h>

TEST(Stack, can_Push_elem)

{

TStack<int> st(3);

st.Push(1);

st.Push(2);

st.Push(3);

ASSERT_NO_THROW(st.Push(4));

}

TEST(TStack, can_create_empty_stack)

{

ASSERT_NO_THROW(TStack<int> st());

}

TEST(TestStack, can_get_Size)

{

TStack<int> a(20);

EXPECT_EQ(0, a.GetSize());

}

TEST(Stack, can_create_stack_with_positive_lenght)

{

ASSERT_NO_THROW(TStack<int> st(5));

}

TEST(Stack, can_create_stack_with_negative_lenght)

{

ASSERT_ANY_THROW(TStack<int> st(-5));

}

TEST(Stack, can_create_stack_with_lenght_more_max)

{

ASSERT_ANY_THROW(TStack<int> st(6000));

}