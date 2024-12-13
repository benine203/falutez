#include <benchmark/benchmark.h>

#include <falutez/falutez-serio.hpp>

// templated benchmark over the type of XSON implementation
template <typename TXSONImpl> void BM_XSON_SERIALIZE(benchmark::State &state) {
  TXSONImpl obj;
  const auto raw = R"({"key":"value","key2":42,"key3":3.14})";

  for (auto _ : state) {
    benchmark::DoNotOptimize(obj.serialize());
  }
}

BENCHMARK_TEMPLATE(BM_XSON_SERIALIZE, XSON::NLH);
BENCHMARK_TEMPLATE(BM_XSON_SERIALIZE, XSON::GLZ);

template <typename TXSONImpl>
void BM_XSON_DESERIALIZE(benchmark::State &state) {
  TXSONImpl obj;
  const auto raw = R"({"key":"value","key2":42,"key3":3.14})";

  for (auto _ : state) {
    benchmark::DoNotOptimize(obj.deserialize(raw));
  }
}

BENCHMARK_TEMPLATE(BM_XSON_DESERIALIZE, XSON::NLH);
BENCHMARK_TEMPLATE(BM_XSON_DESERIALIZE, XSON::GLZ);

template <typename TXSONImpl> void BM_XSON_LOOKUP(benchmark::State &state) {
  TXSONImpl obj;
  const auto raw = R"({"key":"value","key2":42,"key3":3.14})";

  obj.deserialize(raw);

  for (auto _ : state) {
    benchmark::DoNotOptimize(obj["key"].template get<std::string>());
    benchmark::DoNotOptimize(obj["key2"].template get<int>());
    benchmark::DoNotOptimize(obj["key3"].template get<double>());

    benchmark::DoNotOptimize(obj.at("key").template get<std::string>() ==
                             "value");

    benchmark::DoNotOptimize(obj.at("key2").template get<int>() == 42);

    benchmark::DoNotOptimize(obj.at("key3").template get<double>() == 3.14);
  }
}

BENCHMARK_TEMPLATE(BM_XSON_LOOKUP, XSON::NLH);
BENCHMARK_TEMPLATE(BM_XSON_LOOKUP, XSON::GLZ);

template <typename TXSONImpl> void BM_XSON_MODIFY(benchmark::State &state) {
  TXSONImpl obj;
  const auto raw = R"({"key":"value","key2":42,"key3":3.14})";

  obj.deserialize(raw);

  for (auto _ : state) {
    obj["key"] = "value";
    obj["key2"] = 42;
    obj["key3"] = 3.14;
  }
}

BENCHMARK_TEMPLATE(BM_XSON_MODIFY, XSON::NLH);
BENCHMARK_TEMPLATE(BM_XSON_MODIFY, XSON::GLZ);

int main(int argc, char **argv) {
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv)) {
    return 1;
  }
  ::benchmark::RunSpecifiedBenchmarks();
}