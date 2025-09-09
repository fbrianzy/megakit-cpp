#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <optional>

namespace megakit::io {
  struct ArgParse {
    std::unordered_map<std::string, std::string> kv;
    std::vector<std::string> pos;
    explicit ArgParse(int argc, char** argv){
      for(int i=1;i<argc;++i){
        std::string s = argv[i];
        if(s.rfind("--",0)==0){
          auto eq = s.find('=');
          if (eq != std::string::npos) {
            kv[s.substr(2, eq-2)] = s.substr(eq+1);
          } else if (i+1<argc && std::string(argv[i+1]).rfind("--",0)!=0) {
            kv[s.substr(2)] = argv[++i];
          } else {
            kv[s.substr(2)] = "1";
          }
        } else pos.push_back(s);
      }
    }
    std::optional<std::string> get(const std::string& key) const {
      auto it = kv.find(key);
      if (it==kv.end()) return std::nullopt;
      return it->second;
    }
    int get_int(const std::string& key, int def) const {
      auto v = get(key); return v? std::stoi(*v) : def;
    }
  };
}
