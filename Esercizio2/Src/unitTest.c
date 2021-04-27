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
    TEST_ASSERT_EQUAL(0, edit_distance_dyn("", ""));
}

static void oneIsEmptyDyn() {
    TEST_ASSERT_EQUAL(4, edit_distance_dyn("", "Ciao"));
    TEST_ASSERT_EQUAL(4, edit_distance_dyn("Ciao", ""));
}

static void twoEqualDyn() {
    TEST_ASSERT_EQUAL(0, edit_distance_dyn("Ciao", "Ciao"));
}

static void slideExample1(){
    TEST_ASSERT_EQUAL(1, edit_distance_dyn("casa", "cassa"));
}
static void slideExample2(){
    TEST_ASSERT_EQUAL(2, edit_distance_dyn("casa", "cara"));
}
static void slideExample3(){
    TEST_ASSERT_EQUAL(4, edit_distance_dyn("tassa", "passato"));
}
static void slideExample4(){
    TEST_ASSERT_EQUAL(0, edit_distance_dyn("pioppo", "pioppo"));
}

int main(int argc, char *argv[]) {
    RUN_TEST(twoStringsEmpty);
    RUN_TEST(oneIsEmpty);
    RUN_TEST(twoEqual);
    RUN_TEST(twoStringsEmptyDyn);
    RUN_TEST(oneIsEmptyDyn);
    RUN_TEST(twoEqualDyn);
    RUN_TEST(slideExample1);
    RUN_TEST(slideExample2);
    RUN_TEST(slideExample3);
    RUN_TEST(slideExample4);

}