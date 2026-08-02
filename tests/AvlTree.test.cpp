#define CATCH_CONFIG_MAIN
#include "../src/AvlTree/AvlTree.h"
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cstdlib>
#include <vector>

template <class T>
int subtreeHeight(AvlNode<T> *node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 + std::max(subtreeHeight(node->left), subtreeHeight(node->right));
}

template <class T>
void requireNodeInvariants(AvlNode<T> *node, AvlNode<T> *parent) {
    if (node == nullptr) {
        return;
    }

    REQUIRE(node->GetParent() == parent);

    int leftHeight  = subtreeHeight(node->left);
    int rightHeight = subtreeHeight(node->right);

    REQUIRE((int)node->height == 1 + std::max(leftHeight, rightHeight));
    REQUIRE(std::abs(leftHeight - rightHeight) <= 1);

    if (node->left != nullptr) {
        REQUIRE(node->left->GetValue() <= node->GetValue());
    }

    if (node->right != nullptr) {
        REQUIRE(node->right->GetValue() >= node->GetValue());
    }

    requireNodeInvariants(node->left, node);
    requireNodeInvariants(node->right, node);
}

template <class T>
void requireAvlInvariants(AvlTree<T> *tree) {
    requireNodeInvariants(tree->GetRoot(), (AvlNode<T> *)nullptr);
    REQUIRE(tree->Depth() == subtreeHeight(tree->GetRoot()));
}

template <class T>
void collectInOrder(AvlNode<T> *node, std::vector<T> &out) {
    if (node == nullptr) {
        return;
    }

    collectInOrder(node->left, out);
    out.push_back(node->GetValue());
    collectInOrder(node->right, out);
}

template <class T>
std::vector<T> inOrderValues(AvlTree<T> *tree) {
    std::vector<T> values = {};
    collectInOrder(tree->GetRoot(), values);
    return values;
}

TEST_CASE("Test AvlTree Initialization", "[AvlTree]") {
    SECTION("Initialization with primitive types") {
        auto tree_int  = new AvlTree<int>();
        auto tree_char = new AvlTree<char>();

        REQUIRE(tree_int->Amount() == 0);
        REQUIRE(tree_int->Depth() == 0);

        REQUIRE(tree_char->Amount() == 0);
        REQUIRE(tree_char->Depth() == 0);

        REQUIRE(tree_int->GetRoot() == nullptr);
        REQUIRE(tree_char->GetRoot() == nullptr);

        delete tree_int;
        delete tree_char;
    }

    SECTION("A single insertion makes a leaf of height one") {
        auto avl = new AvlTree<int>();

        avl->Insert(42);

        REQUIRE(avl->GetRoot() != nullptr);
        REQUIRE(avl->GetRoot()->GetValue() == 42);
        REQUIRE(avl->GetRoot()->height == 1);
        REQUIRE(avl->GetRoot()->GetParent() == nullptr);
        REQUIRE(avl->Amount() == 1);
        REQUIRE(avl->Depth() == 1);

        delete avl;
    }
}

TEST_CASE("Testing AvlTree Insert", "[AvlTree]") {
    SECTION("Simple Insert with integers") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 20; i++) {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(avl->Insert(random));
            REQUIRE(avl->Amount() == i + 1);
            REQUIRE(avl->HasValue(random));

            requireAvlInvariants(avl);
        }

        delete avl;
    }

    SECTION("Insert with characters") {
        auto avl = new AvlTree<char>();

        REQUIRE_NOTHROW(avl->Insert('a'));
        REQUIRE_NOTHROW(avl->Insert('b'));
        REQUIRE_NOTHROW(avl->Insert('c'));
        REQUIRE_NOTHROW(avl->Insert('d'));

        REQUIRE_NOTHROW(avl->Insert('z'));
        REQUIRE_NOTHROW(avl->Insert('f'));
        REQUIRE_NOTHROW(avl->Insert('g'));
        REQUIRE_NOTHROW(avl->Insert('h'));

        REQUIRE(avl->Amount() == 8);
        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Insertion keeps the in order traversal sorted") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 50; i++) {
            avl->Insert(rand() % 100);
        }

        auto values = inOrderValues(avl);

        REQUIRE((int)values.size() == avl->Amount());
        REQUIRE(std::is_sorted(values.begin(), values.end()));

        delete avl;
    }
}

TEST_CASE("Testing AvlTree rotations", "[AvlTree]") {
    SECTION("Left Left case rotates to the right") {
        auto avl = new AvlTree<int>();

        avl->Insert(30);
        avl->Insert(20);
        avl->Insert(10);

        auto root = avl->GetRoot();

        REQUIRE(root->GetValue() == 20);
        REQUIRE(root->left->GetValue() == 10);
        REQUIRE(root->right->GetValue() == 30);
        REQUIRE(avl->Depth() == 2);

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Right Right case rotates to the left") {
        auto avl = new AvlTree<int>();

        avl->Insert(10);
        avl->Insert(20);
        avl->Insert(30);

        auto root = avl->GetRoot();

        REQUIRE(root->GetValue() == 20);
        REQUIRE(root->left->GetValue() == 10);
        REQUIRE(root->right->GetValue() == 30);
        REQUIRE(avl->Depth() == 2);

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Left Right case rotates twice") {
        auto avl = new AvlTree<int>();

        avl->Insert(30);
        avl->Insert(10);
        avl->Insert(20);

        auto root = avl->GetRoot();

        REQUIRE(root->GetValue() == 20);
        REQUIRE(root->left->GetValue() == 10);
        REQUIRE(root->right->GetValue() == 30);
        REQUIRE(avl->Depth() == 2);

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Right Left case rotates twice") {
        auto avl = new AvlTree<int>();

        avl->Insert(10);
        avl->Insert(30);
        avl->Insert(20);

        auto root = avl->GetRoot();

        REQUIRE(root->GetValue() == 20);
        REQUIRE(root->left->GetValue() == 10);
        REQUIRE(root->right->GetValue() == 30);
        REQUIRE(avl->Depth() == 2);

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Rotations keep the parent pointers consistent") {
        auto avl = new AvlTree<int>();

        for (int value : {50, 25, 75, 10, 30, 60, 90, 5, 15, 1}) {
            avl->Insert(value);
            requireAvlInvariants(avl);
        }

        REQUIRE(avl->GetRoot()->GetParent() == nullptr);

        delete avl;
    }
}

TEST_CASE("Testing AvlTree balancing under sorted insertion", "[AvlTree]") {
    SECTION("Ascending insertion stays logarithmic") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 1000; i++) {
            avl->Insert(i);
        }

        REQUIRE(avl->Amount() == 1000);
        REQUIRE(avl->Depth() >= 10);
        REQUIRE(avl->Depth() <= 14);

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Descending insertion stays logarithmic") {
        auto avl = new AvlTree<int>();

        for (int i = 1000; i > 0; i--) {
            avl->Insert(i);
        }

        REQUIRE(avl->Amount() == 1000);
        REQUIRE(avl->Depth() >= 10);
        REQUIRE(avl->Depth() <= 14);

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Duplicated values do not break the invariants") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 10; i++) {
            avl->Insert(4);
            avl->Insert(9);
        }

        REQUIRE(avl->Amount() == 20);
        REQUIRE(avl->HasValue(4));
        REQUIRE(avl->HasValue(9));

        requireAvlInvariants(avl);

        delete avl;
    }
}

TEST_CASE("Test AvlTree Clear method", "[AvlTree]") {
    SECTION("Clear on an empty tree") {
        auto avl = new AvlTree<int>();

        REQUIRE_NOTHROW(avl->Clear());

        REQUIRE(avl->Amount() == 0);
        REQUIRE(avl->Depth() == 0);
        REQUIRE(avl->GetRoot() == nullptr);

        REQUIRE_NOTHROW(avl->Clear());

        REQUIRE(avl->Amount() == 0);
        REQUIRE(avl->Depth() == 0);
        REQUIRE(avl->GetRoot() == nullptr);

        delete avl;
    }

    SECTION("Clear on a filled tree") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 20; i++) {
            REQUIRE_NOTHROW(avl->Insert(rand() % 100));
        }

        REQUIRE_NOTHROW(avl->Clear());
        REQUIRE_NOTHROW(avl->Clear());

        REQUIRE(avl->Amount() == 0);
        REQUIRE(avl->Depth() == 0);
        REQUIRE(avl->GetRoot() == nullptr);

        delete avl;
    }

    SECTION("The tree is reusable after a Clear") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 100; i++) {
            avl->Insert(i);
        }

        avl->Clear();

        for (int i = 0; i < 30; i++) {
            avl->Insert(i);
        }

        REQUIRE(avl->Amount() == 30);
        requireAvlInvariants(avl);

        delete avl;
    }
}

TEST_CASE("Test AvlTree Search and HasValue Methods", "[AvlTree]") {
    SECTION("Search on an empty tree") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 20; i++) {
            const int random = rand() % 100;

            REQUIRE(avl->Search(random) == nullptr);
            REQUIRE_FALSE(avl->HasValue(random));
        }

        delete avl;
    }

    SECTION("Search for non-existent values") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 20; i++) {
            avl->Insert(rand() % 100);
        }

        for (int i = 0; i < 20; i++) {
            int random = (rand() % 100) + 100;

            REQUIRE(avl->Search(random) == nullptr);
            REQUIRE_FALSE(avl->HasValue(random));
        }

        delete avl;
    }

    SECTION("Search for existing values") {
        auto             avl          = new AvlTree<int>();
        std::vector<int> targetValues = {};

        for (int i = 0; i < 20; i++) {
            const int random = rand() % 100;

            targetValues.push_back(random);
            avl->Insert(random);
        }

        for (const int &value : targetValues) {
            auto foundedValue = avl->Search(value);

            REQUIRE(foundedValue != nullptr);
            REQUIRE(foundedValue->GetValue() == value);
            REQUIRE(avl->HasValue(value));
        }

        delete avl;
    }

    SECTION("Search still works after the tree rotates") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 200; i++) {
            avl->Insert(i);
        }

        for (int i = 0; i < 200; i++) {
            auto found = avl->Search(i);

            REQUIRE(found != nullptr);
            REQUIRE(found->GetValue() == i);
        }

        REQUIRE_FALSE(avl->HasValue(200));

        delete avl;
    }
}

TEST_CASE("Test Remove AvlTree method", "[AvlTree]") {
    SECTION("Remove a leaf node") {
        auto avl = new AvlTree<int>();

        for (int value : {50, 30, 70, 20, 40, 60, 80}) {
            avl->Insert(value);
        }

        REQUIRE_NOTHROW(avl->Remove(20));

        REQUIRE(avl->Amount() == 6);
        REQUIRE_FALSE(avl->HasValue(20));
        REQUIRE(avl->Search(20) == nullptr);

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Remove a node with a single child") {
        auto avl = new AvlTree<int>();

        for (int value : {50, 30, 70, 40, 60, 80}) {
            avl->Insert(value);
        }

        REQUIRE_NOTHROW(avl->Remove(30));

        REQUIRE(avl->Amount() == 5);
        REQUIRE_FALSE(avl->HasValue(30));
        REQUIRE(avl->HasValue(40));

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Remove a node with two children") {
        auto avl = new AvlTree<int>();

        for (int value : {50, 30, 70, 20, 40, 60, 80}) {
            avl->Insert(value);
        }

        REQUIRE_NOTHROW(avl->Remove(70));

        REQUIRE(avl->Amount() == 6);
        REQUIRE_FALSE(avl->HasValue(70));
        REQUIRE(avl->HasValue(60));
        REQUIRE(avl->HasValue(80));

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Remove the root") {
        auto avl = new AvlTree<int>();

        for (int value : {50, 30, 70, 20, 40, 60, 80}) {
            avl->Insert(value);
        }

        REQUIRE_NOTHROW(avl->Remove(50));

        REQUIRE(avl->Amount() == 6);
        REQUIRE_FALSE(avl->HasValue(50));
        REQUIRE(avl->GetRoot() != nullptr);
        REQUIRE(avl->GetRoot()->GetParent() == nullptr);

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Removal triggers a rebalance") {
        auto avl = new AvlTree<int>();

        for (int value : {50, 30, 70, 20, 40, 80, 10}) {
            avl->Insert(value);
        }

        avl->Remove(80);
        requireAvlInvariants(avl);

        avl->Remove(70);

        REQUIRE(avl->GetRoot()->GetValue() == 30);
        REQUIRE(avl->Depth() == 3);

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Remove all items from the tree") {
        auto             avl          = new AvlTree<int>();
        std::vector<int> targetValues = {};

        for (int i = 0; i < 50; i++) {
            const int random = rand() % 100;

            targetValues.push_back(random);
            avl->Insert(random);
        }

        for (int i = 49; i >= 0; i--) {
            REQUIRE_NOTHROW(avl->Remove(targetValues.at(i)));
            REQUIRE(avl->Amount() == i);

            requireAvlInvariants(avl);
            REQUIRE((int)inOrderValues(avl).size() == i);
        }

        REQUIRE(avl->Amount() == 0);
        REQUIRE(avl->Depth() == 0);
        REQUIRE(avl->GetRoot() == nullptr);

        delete avl;
    }

    SECTION("Remove keeps the in order traversal sorted") {
        auto             avl          = new AvlTree<int>();
        std::vector<int> targetValues = {};

        for (int i = 0; i < 100; i++) {
            const int random = rand() % 200;

            targetValues.push_back(random);
            avl->Insert(random);
        }

        for (int i = 0; i < 100; i += 2) {
            avl->Remove(targetValues.at(i));

            auto values = inOrderValues(avl);

            REQUIRE(std::is_sorted(values.begin(), values.end()));
            REQUIRE((int)values.size() == avl->Amount());
        }

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Remove duplicated values one by one") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 10; i++) {
            avl->Insert(4);
            avl->Insert(9);
        }

        for (int i = 0; i < 10; i++) {
            REQUIRE_NOTHROW(avl->Remove(4));
        }

        REQUIRE(avl->Amount() == 10);
        REQUIRE_FALSE(avl->HasValue(4));
        REQUIRE(avl->HasValue(9));

        requireAvlInvariants(avl);

        delete avl;
    }

    SECTION("Remove non-existent value from filled tree") {
        auto avl = new AvlTree<int>();

        for (int i = 0; i < 20; i++) {
            avl->Insert(rand() % 100);
        }

        int random = rand() % 100;

        REQUIRE_THROWS(avl->Remove(random + 100));
        REQUIRE(avl->Amount() == 20);

        delete avl;
    }

    SECTION("Remove from an empty tree") {
        auto avl = new AvlTree<int>();

        REQUIRE_THROWS(avl->Remove(19));

        delete avl;
    }
}
