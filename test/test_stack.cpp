// тесты для стека

#include "stack.h" 


#include <gtest.h> 


TEST(TStack, can_Push_elem)
{
	TStack<int> st(3);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	ASSERT_NO_THROW(st.Push(4));
}
TEST(TStack, can_Pop_elem)
{
	TStack<int> st(3);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Pop();
	EXPECT_EQ(2,st.GetTop());
}


TEST(TStack, can_create_empty_stack)
{
	ASSERT_NO_THROW(TStack<int> st());
}


TEST(TStack, can_get_Size)
{
	TStack<int> a(20);
	EXPECT_EQ(20, a.GetSize());
}


TEST(TStack, can_create_stack_with_positive_lenght)
{
	ASSERT_NO_THROW(TStack<int> st(5));
}


TEST(TStack, can_create_stack_with_negative_lenght)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}
TEST(TStack, can_create_stack_with_negative_lenght2)
{
	ASSERT_ANY_THROW(TStack<int> st(-7));
}

TEST(TStack, can_create_stack_with_lenght_more_max)
{
	ASSERT_NO_THROW(TStack<int> st(6000));
}
TEST(TStack, can_create_stack_with_lenght_more_max2)
{
	ASSERT_NO_THROW(TStack<int> st(99999));
}
TEST(TStack, can_clean_stack)
{
	TStack<int> st(2);
	st.Clean();
	EXPECT_EQ(true, st.IsEmpty());
}
TEST(TStack, can_check_emptiness)
{
	TStack<int> st(2);
	EXPECT_NE(true, st.IsEmpty());
}