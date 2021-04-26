#include "unity.h"
#include "editDistance.h"

void setUp(void) {}
void tearDown(void) {}

static void twoStringsEmpty() {
    TEST_ASSERT_EQUAL(0, edit_distance("", ""));
}

static void oneIsEmpty() {
    TEST_ASSERT_EQUAL(4, edit_distance("", "Ciao"));
    TEST_ASSERT_EQUAL(4, edit_distance("Ciao", ""));
}

static void twoEqual() {
    TEST_ASSERT_EQUAL(0, edit_distance("Ciao", "Ciao"));
}

static void twoStringsEmptyDyn() {
    TEST_ASSERT_EQUAL(0, edit_distance_dyn("", "", 0, 0));
}

static void oneIsEmptyDyn() {
    TEST_ASSERT_EQUAL(4, edit_distance_dyn("", "Ciao", 0, 4));
    TEST_ASSERT_EQUAL(4, edit_distance_dyn("Ciao", "", 4, 0));
}

static void twoEqualDyn() {
    TEST_ASSERT_EQUAL(0, edit_distance_dyn("Ciao", "Ciao", 4, 4));
}

int main(int argc, char *argv[]) {
    RUN_TEST(twoStringsEmpty);
    RUN_TEST(oneIsEmpty);
    RUN_TEST(twoEqual);
    RUN_TEST(twoStringsEmptyDyn);
    RUN_TEST(oneIsEmptyDyn);
    RUN_TEST(twoEqualDyn);
}