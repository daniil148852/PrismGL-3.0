#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace prism {
namespace shader {

class Cache {
public:
    Cache() = default;
    ~Cache() = default;

    Cache(const Cache&) = delete;
    Cache& operator=(const Cache&) = delete;

    Cache(Cache&&) = default;
    Cache& operator=(Cache&&) = default;

    bool load(const std::string& path);
    bool save(const std::string& path) const;

    void store(const std::string& key, const std::vector<std::uint8_t>& data);
    const std::vector<std::uint8_t>* find(const std::string& key) const;

    bool contains(const std::string& key) const;
    void remove(const std::string& key);
    void clear();

private:
    std::unordered_map<std::string, std::vector<std::uint8_t>> entries_;
};

} // namespace shader
} // namespace prism
