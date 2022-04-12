//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>
namespace fs = std::filesystem;

TEST(A2, B2) {
    try {
        GetTree("task3", true);
    }
    catch (...) {

    }
    const fs::path sandbox{"sandbox"};
    fs::create_directory("sandbox");
    std::ofstream{sandbox/"f"};
    try {
        GetTree("sandbox/f", true);
    }
    catch (...) {

    }
    fs::create_directory("sandbox/da");
    std::ofstream{sandbox/"da/file"};
    ASSERT_EQ(1, GetTree("sandbox", true).children.size());
    ASSERT_EQ(2, GetTree("sandbox", false).children.size());
    FileNode t;
    t.is_dir = false;
    FilterEmptyNodes(t, "../");
    FileNode t1;
    t1.is_dir = true;
    ASSERT_FALSE(t == t1);
    FilterEmptyNodes(t1, "sandbox/f");
    t1.children.push_back(t);
    FilterEmptyNodes(t1, "../");
}