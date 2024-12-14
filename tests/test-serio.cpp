
#include <gtest/gtest.h>

#include <cpptrace.hpp>
#include <utils.hpp>

#include <falutez/falutez-serio.hpp>

// templated test case
using XSONTypes = ::testing::Types<XSON::NLH, XSON::GLZ>;
template <typename T> struct XSONTest : public ::testing::Test {
  T value_;
};

TYPED_TEST_SUITE(XSONTest, XSONTypes);

TYPED_TEST(XSONTest, Access) {
  TypeParam obj = this->value_;

  obj["key"] = "value";
  obj["key2"] = 42;
  obj["key3"] = 3.14;
  obj["key4"] = true;

  // Verify that the values are correctly set and retrieved using operator[]
  EXPECT_EQ(obj["key"], "value");
  EXPECT_EQ(obj["key2"], 42);
  EXPECT_EQ(obj["key3"], 3.14);

  // Verify that the values are correctly retrieved using the at() method with
  // type conversion
  EXPECT_EQ(obj.at("key").template get<std::string>(), "value");
  EXPECT_EQ(obj.at("key2").template get<int>(), 42);
  EXPECT_EQ(obj.at("key3").template get<double>(), 3.14);

  EXPECT_TRUE(obj.has_boolean_field("key4"));

  EXPECT_TRUE(obj.has_string_field("key"));
  EXPECT_FALSE(obj.has_string_field("key2"));

  EXPECT_TRUE(obj.has_number_field("key2"));
  EXPECT_TRUE(obj.has_number_field("key3"));

  EXPECT_FALSE(obj.has_double_field("key2"));
  EXPECT_TRUE(obj.has_double_field("key3"));
}

TYPED_TEST(XSONTest, SERDE) {

  TypeParam obj = this->value_;

  const auto serialized = R"({"key":"value","key2":42,"key3":3.14})";
  // Deserialize the object from a serialized string
  auto &ref_self = obj.deserialize(serialized);

  // Verify that the deserialization returns a reference to the same object
  EXPECT_EQ(&ref_self, &obj);

  // Verify that the values are correctly deserialized and retrieved using
  // operator[]
  EXPECT_EQ(obj["key"], "value");
  EXPECT_EQ(obj["key2"], 42);
  EXPECT_EQ(obj["key3"], 3.14);

  // Verify that the object can be serialized back to the original string
  EXPECT_EQ(obj.serialize(), "{\"key\":\"value\",\"key2\":42,\"key3\":3.14}");
}

TEST(XSON, ConversionRoundTrip) {
  XSON::NLH json1;
  XSON::GLZ json2;

  const auto raw = R"({"key":"value","key2":42,"key3":3.14})";

  // Deserialize json1 from the raw string
  json1.deserialize(raw);

  // Serialize json1 and deserialize json2 from the serialized string
  json2.deserialize(json1.serialize());

  // Verify that the values are correctly transferred between json1 and json2
  EXPECT_EQ(json1["key"].get<std::string>(), json2["key"].get<std::string>());
  EXPECT_EQ(json1["key2"].get<int>(), json2["key2"].get<int>());
  EXPECT_EQ(json1["key3"].get<double>(), json2["key3"].get<double>());

  // Serialize json2 and deserialize json1 from the serialized string
  json1.deserialize(json2.serialize());

  // Verify that the final serialized string matches the original raw string
  EXPECT_EQ(json1.serialize(), raw);
}

int main(int argc, char **argv) {
  ::cpptrace::register_terminate_handler();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
