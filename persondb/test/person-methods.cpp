#include <gtest/gtest.h>
#include "person.h"

class PersonTest : public ::testing::Test {
	protected:
		virtual void SetUp() {}
		virtual void TearDown() {}
		Person person;
};

TEST(Person, DefaultConstructor) {
	EXPECT_NO_THROW(Person person);
}

TEST_F(PersonTest, setName) {
	EXPECT_NO_THROW(person.setName("John Doe"));
	EXPECT_EQ(person.name(), "John Doe");
	EXPECT_ANY_THROW(person.setName(""));
	EXPECT_EQ(person.name(), "John Doe");
}

TEST_F(PersonTest, setAddress) {
	EXPECT_NO_THROW(person.setAddress("123 Prentice Dr."));
	EXPECT_EQ(person.address(), "123 Prentice Dr.");
	EXPECT_NO_THROW(person.setAddress(""));
	EXPECT_EQ(person.address(), "");
}

TEST_F(PersonTest, setPhone) {
	EXPECT_NO_THROW(person.setPhone("8001234567"));
	EXPECT_EQ(person.phone(), "8001234567");
	EXPECT_NO_THROW(person.setPhone("800-123-4567"));
	EXPECT_EQ(person.phone(), "800-123-4567");
	EXPECT_NO_THROW(person.setPhone("800 123 4567"));
	EXPECT_NO_THROW(person.setPhone("(800) 123-4567"));
	EXPECT_NO_THROW(person.setPhone("(800)123-4567"));
	EXPECT_NO_THROW(person.setPhone(""));
	EXPECT_ANY_THROW(person.setPhone("800123456x"));
	EXPECT_ANY_THROW(person.setPhone("800123456"));
	EXPECT_ANY_THROW(person.setPhone("-800-123-4567"));
	EXPECT_ANY_THROW(person.setPhone("800-123-456"));
	EXPECT_ANY_THROW(person.setPhone("1-2-3"));
	EXPECT_ANY_THROW(person.setPhone("()-"));
}

TEST_F(PersonTest, setMass) {
	EXPECT_NO_THROW(person.setMass(75));
	EXPECT_EQ(person.mass(), 75);
	EXPECT_ANY_THROW(person.setMass(0));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
