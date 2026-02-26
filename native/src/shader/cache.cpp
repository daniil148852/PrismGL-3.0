#include "cache.hpp"

#include <cstdint>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

namespace prism {
namespace shader {

bool Cache::load(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }

    entries_.clear();

    while (file.peek() != EOF) {
        std::uint32_t key_len = 0;
        file.read(reinterpret_cast<char*>(&key_len), sizeof(key_len));
        if (!file) {
            return false;
        }

        std::string key(key_len, '\0');
        file.read(key.data(), key_len);
        if (!file) {
            return false;
        }

        std::uint32_t data_len = 0;
        file.read(reinterpret_cast<char*>(&data_len), sizeof(data_len));
        if (!file) {
            return false;
        }

        std::vector<std::uint8_t> data(data_len);
        file.read(reinterpret_cast<char*>(data.data()), data_len);
        if (!file) {
            return false;
        }

        entries_.emplace(std::move(key), std::move(data));
    }

    return true;
}

bool Cache::save(const std::string& path) const {
    std::ofstream file(path, std::ios::binary | std::ios::trunc);
    if (!file.is_open()) {
        return false;
    }

    for (const auto& [key, data] : entries_) {
        const auto key_len = static_cast<std::uint32_t>(key.size());
        file.write(reinterpret_cast<const char*>(&key_len), sizeof(key_len));
        file.write(key.data(), key_len);

        const auto data_len = static_cast<std::uint32_t>(data.size());
        file.write(reinterpret_cast<const char*>(&data_len), sizeof(data_len));
        file.write(reinterpret_cast<const char*>(data.data()), data_len);

        if (!file) {
            return false;
        }
    }

    return true;
}

void Cache::store(const std::string& key, const std::vector<std::uint8_t>& data) {
    entries_[key] = data;
}

const std::vector<std::uint8_t>* Cache::find(const std::string& key) const {
    auto it = entries_.find(key);
    if (it == entries_.end()) {
        return nullptr;
    }
    return &it->second;
}

bool Cache::contains(const std::string& key) const {
    return entries_.count(key) > 0;
}

void Cache::remove(const std::string& key) {
    entries_.erase(key);
}

void Cache::clear() {
    entries_.clear();
}

} // namespace shader
} // namespace prism
