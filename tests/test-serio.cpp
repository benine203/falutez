
#include <gtest/gtest.h>

#include <cpptrace.hpp>
#include <utils.hpp>

#include <falutez/falutez-serio.hpp>

// templated test case
using XSONTypes = ::testing::Types<XSON::NLH, XSON::GLZ>;
template <typename T> struct XSONTest : public ::testing::Test {};

TYPED_TEST_SUITE(XSONTest, XSONTypes);

TYPED_TEST(XSONTest, DefaultConstructor) {

  TypeParam obj = typename TypeParam::object_t{};

  // Verify that the object is empty
  EXPECT_TRUE(obj.empty());
}

TYPED_TEST(XSONTest, CopyConstructor) {

  TypeParam obj1{};

  obj1["key"] = "value";
  obj1["key2"] = 42;
  obj1["key3"] = 3.14;

  ASSERT_TRUE(obj1.is_object());
  ASSERT_EQ(obj1.size(), 3);
  ASSERT_EQ(obj1["key"], "value");
  ASSERT_EQ(obj1["key2"], 42);
  ASSERT_EQ(obj1["key3"], 3.14);

  // Copy the object
  TypeParam from_otherobj(obj1);
  ASSERT_TRUE(from_otherobj.is_object());

  //// Verify that the values are correctly copied
  EXPECT_EQ(from_otherobj["key"], "value");
  EXPECT_EQ(from_otherobj["key2"], 42);
  EXPECT_EQ(from_otherobj["key3"], 3.14);

  TypeParam from_arrayt{typename TypeParam::array_t{4, 5}};
  ASSERT_TRUE(from_arrayt.is_array());

  TypeParam from_constchar{"xyz"};
  ASSERT_TRUE(from_constchar.is_string());

  TypeParam cons_from_vec{std::vector<int>{9, 8, 7}};
  ASSERT_TRUE(cons_from_vec.is_array());

  auto const obj2 = TypeParam{{{"key", "value"}, {"key2", 42}, {"key3", 3.14}}};

  auto copy2 = TypeParam(obj2);

  ASSERT_TRUE(copy2.is_object());

  EXPECT_EQ(copy2["key"], "value");
  EXPECT_EQ(copy2["key2"], 42);
  EXPECT_EQ(copy2["key3"], 3.14);
}

TYPED_TEST(XSONTest, MoveConstructor) {

  TypeParam obj1 = typename TypeParam::object_t{};
  obj1["key"] = "value";
  obj1["key2"] = 42;
  obj1["key3"] = 3.14;

  // Move the object
  TypeParam obj2(std::move(obj1));

  // Verify that the values are correctly moved
  EXPECT_EQ(obj2["key"], "value");
  EXPECT_EQ(obj2["key2"], 42);
  EXPECT_EQ(obj2["key3"], 3.14);
}

TYPED_TEST(XSONTest, CopyAssignment) {

  TypeParam obj1 = typename TypeParam::object_t{};
  obj1["key"] = "value";
  obj1["key2"] = 42;
  obj1["key3"] = 3.14;

  TypeParam obj2{};

  // Copy the object
  obj2 = obj1;

  // Verify that the values are correctly copied
  EXPECT_EQ(obj2["key"], "value");
  EXPECT_EQ(obj2["key2"], 42);
  EXPECT_EQ(obj2["key3"], 3.14);
}

TYPED_TEST(XSONTest, MoveAssignment) {

  TypeParam obj1 = typename TypeParam::object_t{};
  obj1["key"] = "value";
  obj1["key2"] = 42;
  obj1["key3"] = 3.14;

  TypeParam obj2{};

  // Move the object
  obj2 = std::move(obj1);

  // Verify that the values are correctly moved
  EXPECT_EQ(obj2["key"], "value");
  EXPECT_EQ(obj2["key2"], 42);
  EXPECT_EQ(obj2["key3"], 3.14);
}

TYPED_TEST(XSONTest, EnumItems) {
  const auto *const raw = R"({"key":"value","key2":42,"key3":3.14})";
  auto obj = TypeParam::parse(raw);

  std::set<std::string> keys;

  for (auto const &[key, value] : obj.items()) {
    keys.insert(key);
  }

  EXPECT_EQ(keys.size(), 3);
  EXPECT_TRUE(keys.contains("key"));
  EXPECT_TRUE(keys.contains("key2"));
  EXPECT_TRUE(keys.contains("key3"));
  EXPECT_FALSE(keys.contains("key4"));
}

TYPED_TEST(XSONTest, ConsFromMap) {

  auto map1 = std::unordered_map<std::string, int>{{"key", 42}, {"key2", 3}};
  auto map2 = std::map<std::string_view, float>{{"key", 42.0}, {"key2", 3.14}};

  TypeParam obj(map1);

  TypeParam obj2(std::move(map2));

  // Verify that the values are correctly set and retrieved using
  // operator[]
  EXPECT_EQ(obj["key"], 42);
  EXPECT_EQ(obj["key2"], 3);

  obj = TypeParam(std::map<std::string, std::variant<int, double>>{
      {"key", 42}, {"key2", 3.14}});

  EXPECT_EQ(obj["key"], 42);
  EXPECT_EQ(obj["key2"], 3);
}

TYPED_TEST(XSONTest, ConsFromIL) {
  TypeParam obj{{
      {"key", 42},
      {"key2", 3.14},
  }};

  // verify
  ASSERT_TRUE(obj.is_object());
  EXPECT_EQ(obj["key"], 42);
  EXPECT_EQ(obj["key2"], 3);

  TypeParam arr{{
      {1, 2, 3},
      {4, 5, 6},
  }};

  auto vec1 = std::vector<int>{1, 2, 3};

  ASSERT_TRUE(arr.is_array());
  EXPECT_EQ(arr[0], vec1);

  auto const cil1 = std::initializer_list<float>{1.1, 2.2, 3.3};
  auto obj2 = TypeParam{cil1};

  ASSERT_TRUE(obj2.is_array());

  auto obj2_0 = obj2[0].template get<float>();

  EXPECT_FLOAT_EQ(obj2_0, 1.1F);
  //  EXPECT_FLOAT_EQ(obj2[1], 2.2F);
  //  EXPECT_FLOAT_EQ(obj2[2], 3.3F);
}

TYPED_TEST(XSONTest, FromVec) {
  TypeParam obj{std::vector<int>{1, 2, 3}};

  ASSERT_TRUE(obj.is_array());
  EXPECT_EQ(obj[0], 1);
  EXPECT_EQ(obj[1], 2);
  EXPECT_EQ(obj[2], 3);

  obj[1] = 42;
  EXPECT_EQ(obj[1], 42);

  obj = std::vector<double>{1.1, 2.2, 3.3};
  ASSERT_TRUE(obj.is_array());
  EXPECT_EQ(obj[0], 1.1);
  EXPECT_EQ(obj[1], 2.2);
  EXPECT_EQ(obj[2], 3.3);

  auto const cvec1 = std::vector<std::string>{"a", "b", "c"};
  obj = cvec1;

  ASSERT_TRUE(obj.is_array());
  EXPECT_EQ(obj[0], "a");
  EXPECT_EQ(obj[1], "b");
  EXPECT_EQ(obj[2], "c");
}

TYPED_TEST(XSONTest, FromVariant) {
  TypeParam obj{std::variant<int, double>{42}};

  ASSERT_TRUE(obj.is_number());
  EXPECT_EQ(obj, 42);

  obj = std::variant<int, double>{3.14};
  ASSERT_TRUE(obj.is_number());

  const auto vec2 = std::variant<double, std::string>{"xyz"};
  obj = vec2;

  ASSERT_TRUE(obj.is_string());
  EXPECT_EQ(obj, "xyz");

  obj = TypeParam{vec2};

  ASSERT_TRUE(obj.is_string());
  EXPECT_EQ(obj, "xyz");
}

TYPED_TEST(XSONTest, Access) {

  TypeParam obj{};

  obj["key"] = "value";
  obj["key2"] = 42;
  obj["key3"] = 3.14;
  obj["key4"] = true;
  obj["key5"] = std::vector<int>{1, 2, 3};

  // Verify that the values are correctly set and retrieved using
  // operator[]
  EXPECT_EQ(obj["key"], "value");
  EXPECT_EQ(obj["key2"], 42);
  EXPECT_EQ(obj["key3"], 3.14);

  // Verify that the values are correctly retrieved using the at()
  //     method with type conversion
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

  EXPECT_FALSE(obj.at("key").is_array());
  EXPECT_TRUE(obj["key5"].is_array());

  auto &arr = obj["key5"].get_array();
  EXPECT_EQ(arr.size(), 3);
}

TYPED_TEST(XSONTest, SERDE) {

  TypeParam obj{};

  const auto *const serialized = R"({"key":"value","key2":42,"key3":3.14})";

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

  const auto *const raw = R"({"key":"value","key2":42,"key3":3.14})";

  // Deserialize json1 from the raw string
  json1.deserialize(raw);

  // Serialize json1 and deserialize json2 from the serialized string
  json2.deserialize(json1.serialize());

  // Verify that the values are correctly transferred between json1 and json2
  EXPECT_EQ(json1[std::string{"key"}].get<std::string>(),
            json2[std::string{"key"}].get<std::string>());
  // EXPECT_EQ(json1["key2"].get<int>(), json2["key2"].get<int>());
  // EXPECT_EQ(json1["key3"].get<double>(), json2["key3"].get<double>());

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
