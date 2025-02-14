#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP

#include <cstdint>  
#include <bitset>
#include <cmath>
#include "murmurhash.hpp"


template <typename Key>
struct BloomHash {
  std::size_t operator()(Key key, unsigned int seed) const 
  {
    // Implementation of murmur3_32 
    return murmur3_32(reinterpret_cast<uint8_t*>(&key), sizeof(Key), seed);
  }
};

template <typename Key, unsigned int m, typename Hash = BloomHash<Key>>

class BloomFilter {
 public:
  explicit BloomFilter(unsigned int num_hashes) : k_(num_hashes) 
  {}

  BloomFilter(std::initializer_list<Key> init, unsigned int num_hashes)
      : k_(num_hashes) 
      {
    for (const auto& key : init) 
    {
      insert(key);
    }
  }

  template <typename It>
  BloomFilter(It first, It last, unsigned int num_hashes) : k_(num_hashes) 
  {
    for (auto it = first; it != last; ++it) 
    {
      insert(*it);
    }
  }


  bool insert(const Key& key) 
  {
    bool inserted = false;
    for (unsigned int i = 0; i < k_; ++i) 
    {
      std::size_t hashValue = hash_(key, i);
      inserted |= !data_.test(hashValue % m);
      data_.set(hashValue % m);
    }
    return inserted;
  }


  bool contains(const Key& key) const 
  {
    for (unsigned int i = 0; i < k_; ++i) 
    {
      std::size_t hashValue = hash_(key, i);
      if (!data_.test(hashValue % m)) 
      {
        return false;
      }
    }
    return true;
  }


  uint64_t approx_size() const 
  {
    double X = data_.count();
    double nummer = -(static_cast<double>(m) / k_) * std::log(1.0 - (X / m)); 
    return std::round(nummer);
  }

 
  template <typename It>
  double false_positive_rate(It positive_begin, It positive_end,
                             It negative_begin, It negative_end) const 
                             {
    double falsePositives = 0;
    double trueNegatives = 0;

    for (auto it = positive_begin; it != positive_end; ++it) 
    {
      if (!contains(*it)) 
      {
        falsePositives++;
      }
    }

    for (auto it = negative_begin; it != negative_end; ++it) 
    {
      if (!contains(*it)) 
      {
        trueNegatives++;
      }
    }

    return falsePositives / (falsePositives + trueNegatives);
  }


  double space_ratio(uint64_t num_elements) 
  {
    return static_cast<double>(sizeof(data_)) / static_cast<double>(sizeof(Key)* num_elements);
  }

 private:
  std::bitset<m> data_;
  unsigned int k_;
  Hash hash_;
}; 

#endif // BLOOM_FILTER_HPP

