//
// Created by Fengwei Zhang on 6/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0588_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0588_H

#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class FileSystem {
    // 类似Trie，根据输入的查找路径，建立目录树
    // 树中节点（Node）包含4个属性：文件/目录名（name），是否为文件（is_file），文件内容（content），子节点映射（children）
    // 细节：若名为name的子节点在children中不存在，我们默认创建新节点（node->children[name]=new Node(name)）
public:
    FileSystem() {
        root = new Node("");
    }

    vector<string> ls(const string &path) {
        auto node = findNode(path);
        if (node->is_file) {
            return {node->name};
        }
        vector<string> ans;
        ans.reserve(node->children.size());
        for (const auto &item: node->children) {
            ans.emplace_back(item.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    void mkdir(const string &path) {
        findNode(path);
    }

    void addContentToFile(const string &path, const string &content) {
        auto node = findNode(path);
        node->is_file = true;
        node->content += content;
    }

    string readContentFromFile(const string &path) {
        return findNode(path)->content;
    }

private:
    struct Node {
        string name;
        bool is_file;
        string content;
        unordered_map<string, Node *> children{};

        Node(const string &name) {
            this->name = name;
            is_file = false;
            content = "";
        }
    };

    Node *root;

    Node *findNode(const string &path) {
        int prev = 1;
        auto i = path.find_first_of('/', prev);
        auto node = root;
        while (i != string::npos) {
            auto name = path.substr(prev, i - prev);
            if (!node->children.count(name)) {
                node->children[name] = new Node(name);
            }
            node = node->children[name];
            prev = (int) i + 1;
            i = path.find_first_of('/', prev);
        }
        if (prev < (int) path.size()) {
            auto name = path.substr(prev);
            if (!node->children.count(name)) {
                node->children[name] = new Node(name);
            }
            node = node->children[name];
        }
        return node;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0588_H
